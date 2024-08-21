import numpy as np
import pandas as pd
import csv

# Load and preprocess data
def load_and_preprocess_data():
    train_data = pd.read_csv('data/train_data4.csv')
    train_label = pd.read_csv('data/train_label4.csv')
    test_data = pd.read_csv('data/test_data4.csv')
    test_label = pd.read_csv('data/test_label4.csv')

    columns_to_drop = [
        'ADDRESS', 'STATE', 'MAIN_ADDRESS', 'ADMINISTRATIVE_AREA_LEVEL_2',
        'SUBLOCALITY', 'STREET_NAME', 'LONG_NAME', 'FORMATTED_ADDRESS'
    ]
    train_data.drop(columns=columns_to_drop, inplace=True)
    test_data.drop(columns=columns_to_drop, inplace=True)

    # Encode categorical variables
    for column in ['BROKERTITLE', 'LOCALITY']:
        train_data[column], _ = pd.factorize(train_data[column])
        test_data[column], _ = pd.factorize(test_data[column])

    # One-hot encoding
    train_data = pd.get_dummies(train_data, columns=['TYPE'])
    test_data = pd.get_dummies(test_data, columns=['TYPE'])
    train_data, test_data = train_data.align(test_data, join='left', axis=1)
    test_data.fillna(0, inplace=True)

    # Normalize data
    mean = train_data.mean()
    std = train_data.std()
    train_data = (train_data - mean) / std
    test_data = (test_data - mean) / std

    # Convert to numpy arrays
    train_data = train_data.to_numpy()
    train_label = train_label['BEDS'].to_numpy().reshape(-1, 1)
    test_data = test_data.to_numpy()
    test_label = test_label['BEDS'].to_numpy().reshape(-1, 1)

    return train_data, train_label, test_data, test_label

# Neural network utilities
def init_weights(size_in, size_out):
    return np.random.randn(size_in, size_out) * np.sqrt(2. / size_in)

def relu(x):
    return np.maximum(0, x)

def relu_deriv(x):
    return (x > 0).astype(float)

def init_network(input_size, hidden_sizes, output_size):
    weights = []
    biases = []
    layer_sizes = [input_size] + hidden_sizes + [output_size]
    for i in range(len(layer_sizes) - 1):
        weights.append(init_weights(layer_sizes[i], layer_sizes[i+1]))
        biases.append(np.zeros((1, layer_sizes[i+1])))
    return weights, biases

# Training and evaluation
def train_network(weights, biases, train_data, train_label, val_data, val_label, epochs, batch_size, learning_rate):
    loss_history = []
    for epoch in range(epochs):
        for i in range(0, len(train_data), batch_size):
            x_batch = train_data[i:i + batch_size]
            y_batch = train_label[i:i + batch_size]
            activations = [x_batch]
            for j in range(len(weights)):
                activations.append(relu(np.dot(activations[-1], weights[j]) + biases[j]))

            deltas = [2 * (activations[-1] - y_batch) / x_batch.shape[0]]
            for j in reversed(range(len(weights))):
                d_weights = np.dot(activations[j].T, deltas[0])
                d_biases = np.sum(deltas[0], axis=0, keepdims=True)
                if j != 0:
                    deltas.insert(0, np.dot(deltas[0], weights[j].T) * relu_deriv(activations[j]))
                weights[j] -= learning_rate * d_weights
                biases[j] -= learning_rate * d_biases

        loss = np.mean((y_batch - activations[-1]) ** 2)
        val_activations = [val_data]
        for j in range(len(weights)):
            val_activations.append(relu(np.dot(val_activations[-1], weights[j]) + biases[j]))
        val_loss = np.mean((val_label - val_activations[-1]) ** 2)
        loss_history.append(val_loss)
        if epoch % 10 == 0:
            print(f'Epoch {epoch + 1}/{epochs} Training Loss: {loss}\t Validation Loss: {val_loss}')

    return weights, biases, loss_history, val_loss, loss

def predict(weights, biases, data):
    activations = [data]
    for j in range(len(weights)):
        activations.append(relu(np.dot(activations[-1], weights[j]) + biases[j]))
    return activations[-1]

# Main script
def main():
    train_data, train_label, test_data, test_label = load_and_preprocess_data()

    # Split data into train and validation sets (80/20 split)
    np.random.seed(0)  # for reproducibility
    indices = np.arange(train_data.shape[0])
    np.random.shuffle(indices)
    split_idx = int(0.8 * len(indices))
    train_data_split = train_data[indices[:split_idx]]
    train_label_split = train_label[indices[:split_idx]]
    val_data = train_data[indices[split_idx:]]
    val_label = train_label[indices[split_idx:]]

    # Network hyperparameters
    input_size = train_data.shape[1]
    output_size = 1
    epochs = 200
    batch_size = 32
    learning_rate = 0.001

    # Different network architectures
    architectures = [{"hidden_sizes": [256, 128]}]
    models_performance = []
    for arch in architectures:
        print("Training with architecture:", arch['hidden_sizes'])
        weights, biases = init_network(input_size, arch['hidden_sizes'], output_size)
        weights, biases, loss_history, val_loss, loss = train_network(weights, biases, train_data_split, train_label_split, val_data, val_label, epochs, batch_size, learning_rate)
        models_performance.append({
            'architecture': arch['hidden_sizes'],
            'weights': weights,
            'biases': biases,
            'val_loss': val_loss,
            'loss': loss
        })

    best_model = min(models_performance, key=lambda x: x['val_loss'])
    print(f'Best model architecture: {best_model["architecture"]}')

    # Make predictions with the best model
    test_predictions = predict(best_model['weights'], best_model['biases'], test_data)
    final_predictions = np.round(test_predictions.flatten()).astype(int)

    # Output results to a CSV file
    with open('output.csv', 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['BEDS'])
        for value in final_predictions:
            writer.writerow([value])

    # Calculate accuracy
    accuracy = np.mean(final_predictions == test_label.flatten())
    print(f'Accuracy: {accuracy * 100:.2f}%')

if __name__ == "__main__":
    main()
