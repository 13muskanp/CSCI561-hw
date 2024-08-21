#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <list>
#include <algorithm>
#include <tuple>
#include <set>
#include <functional>

using namespace std;

struct Node {
    std::string name;
    int x, y, z;
    std::list<std::pair<Node*, double>> edges; // Adjacency list with edge cost
    
};

struct State{
    string name;
    State* parent;
};

struct State1{
    string name;
    State1* parent;
    double cost;
};

struct comparison
{
    bool operator()(State1* node1, State1* node2) 
    { return node1->cost > node2->cost; }
};

class Graph {
public:
    std::unordered_map<std::string, Node> nodes;

    void addNode(const std::string& name, int x, int y, int z) {
        nodes[name] = Node{name, x, y, z};
    }

    void addEdge(const string& from, const string& to) {
        Node* fromNode = &nodes[from];
        Node* toNode = &nodes[to];
        double cost = sqrt(pow(fromNode->x - toNode->x, 2) + pow(fromNode->y - toNode->y, 2));
        fromNode->edges.push_back({toNode, cost});
        toNode->edges.push_back({fromNode, cost});
    }
};


bool isMoveAllowed(const Node& from, const Node& to, int energyLimit, int& momentum) {
    int energyRequired = to.z - from.z;

    if (energyRequired > 0) { // Uphill
        if (energyRequired <= momentum + energyLimit) {
            momentum = 0; // Used momentum, reset it
            return true;
        } else {
            return false; // Not enough energy and momentum for uphill
        }
    } else {
        momentum = max(momentum, abs(energyRequired)); // Gain or maintain momentum if downhill
        return true;
    }
}

vector<string> BFS(const Graph& graph, const string& start, const string& goal, int energyLimit) {
    unordered_map<string, string> cameFrom;
    unordered_map<string, int> momentumMap;
    set<string> visited;
    queue<State*> queue;

    State* startState = new State();
    startState->name = start;
    startState->parent = (State*)NULL;
    queue.push(startState);
    visited.insert(start + " " + start);
    momentumMap[start] = 0;  // Initialize momentum at start

    while (!queue.empty()) {
        State* currentState = queue.front();
        queue.pop();
        const Node& current = graph.nodes.at(currentState->name);

        if (currentState->name == goal) {
            vector<string> path;
            while(currentState->parent){
                path.push_back(currentState->name);
                currentState = currentState->parent;
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& edge : current.edges) {
            Node* next = edge.first;
            bool move = true;
            if(currentState->parent)
            {
                const Node& parent = graph.nodes.at((currentState->parent)->name);
                if(next->z - current.z > energyLimit)
                {
                    if(next->z - parent.z > energyLimit)
                    {
                        move = false;
                    }
                }
            }

else
{
if(next->z - current.z > energyLimit)
                move = false;
}
                if (move && visited.find(next->name + " " + currentState->name) == visited.end()) {
                    State* temp = new State();
                    temp->name = next->name;
                    temp->parent = currentState;
                    queue.push(temp);
                    visited.insert(next->name + " " + currentState->name);
                }
        }
    }

    return {"FAIL"};
}

double calculate3DDistance(const Node& from, const Node& to) {
    return sqrt(pow(from.x - to.x, 2) + pow(from.y - to.y, 2) + pow(from.z - to.z, 2));
}

double heuristic(const Node& current, const Node& goal) {
    return calculate3DDistance(current, goal);
}

vector<string> reconstructPath(const unordered_map<string, string>& cameFrom, const string& start, const string& goal) {
    vector<string> path;
    string current = goal;
    while (current != start) {
        path.push_back(current);
        current = cameFrom.at(current);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path.empty() || path.front() == "FAIL" ? vector<string>{"FAIL"} : path;
}


vector<string> UCS(const Graph& graph, const string& start, const string& goal, int energyLimit) {
    unordered_map<string, string> cameFrom;
    unordered_map<string, int> momentumMap;
    set<string> visited;
    priority_queue<State1*, vector<State1*>, comparison> queue;

    State1* startState = new State1();
    startState->name = start;
    startState->parent = (State1*)NULL;
    startState->cost = 0;
    queue.push(startState);
    visited.insert(start + " " + start);
    momentumMap[start] = 0;  // Initialize momentum at start

    while (!queue.empty()) {
        State1* currentState = queue.top();
        queue.pop();
        const Node& current = graph.nodes.at(currentState->name);

        if (currentState->name == goal) {
            vector<string> path;
            while(currentState->parent){
                path.push_back(currentState->name);
                currentState = currentState->parent;
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& edge : current.edges) {
            Node* next = edge.first;
            bool move = true;
            if(currentState->parent)
            {
                const Node& parent = graph.nodes.at((currentState->parent)->name);
                if(next->name == "uw" and current.name == "start") cout << "XD"; 
                if(next->z - current.z > energyLimit)
                {
                    if(next->z - parent.z > energyLimit)
                    {
                        move = false;
                    }
                }
            }

else
{
if(next->z - current.z > energyLimit)
                move = false;
}
                if (move && visited.find(next->name + " " + currentState->name) == visited.end()) {
                    State1* temp = new State1();
                    temp->name = next->name;
                    temp->parent = currentState;
                    temp->cost = currentState->cost + sqrt(pow(next->x - current.x, 2) + pow(next->y - current.y, 2));
                    queue.push(temp);
                    visited.insert(next->name + " " + currentState->name);
                }
        }
    }

    return {"FAIL"};
}

vector<string> AStar(const Graph& graph, const string& start, const string& goal, int energyLimit) {
    unordered_map<string, string> cameFrom;
    unordered_map<string, int> momentumMap;
    set<string> visited;
    priority_queue<State1*, vector<State1*>, comparison> queue;

    State1* startState = new State1();
    startState->name = start;
    startState->parent = (State1*)NULL;
    startState->cost = 0 + heuristic(graph.nodes.at(start), graph.nodes.at(goal));
    queue.push(startState);
    visited.insert(start + " " + start);
    momentumMap[start] = 0;  // Initialize momentum at start

    while (!queue.empty()) {
        State1* currentState = queue.top();
        queue.pop();
        const Node& current = graph.nodes.at(currentState->name);

        if (currentState->name == goal) {
            vector<string> path;
            while(currentState->parent){
                path.push_back(currentState->name);
                currentState = currentState->parent;
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& edge : current.edges) {
            Node* next = edge.first;
            bool move = true;
            if(currentState->parent)
            {
                const Node& parent = graph.nodes.at((currentState->parent)->name);
                if(next->name == "uw" and current.name == "start") cout << "XD"; 
                if(next->z - current.z > energyLimit)
                {
                    if(next->z - parent.z > energyLimit)
                    {
                        move = false;
                    }
                }
            }

else
{
if(next->z - current.z > energyLimit)
                move = false;
}
                if (move && visited.find(next->name + " " + currentState->name) == visited.end()) {
                    State1* temp = new State1();
                    temp->name = next->name;
                    temp->parent = currentState;
                    temp->cost = currentState->cost + sqrt(pow(next->x - current.x, 2) + pow(next->y - current.y, 2)+ pow(next->z - current.z, 2));
                    queue.push(temp);
                    visited.insert(next->name + " " + currentState->name);
                }
        }
    }

    return {"FAIL"};
}

void parseInput(const string& filename, string& algorithm, int& energyLimit, Graph& graph) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open " << filename << endl;
        return;
    }

    file >> algorithm >> energyLimit;
    int n, m;
    file >> n;
    string name;
    int x, y, z;
    for (int i = 0; i < n; ++i) {
        file >> name >> x >> y >> z;
        graph.addNode(name, x, y, z);
    }
    file >> m;
    string from, to;
    for (int i = 0; i < m; ++i) {
        file >> from >> to;
        graph.addEdge(from, to);
    }
}

int main() {
    string algorithm;
    int energyLimit;
    Graph marsTerrain;

    parseInput("input.txt", algorithm, energyLimit, marsTerrain);

    vector<string> path;
    if (algorithm == "BFS") {
        path = BFS(marsTerrain, "start", "goal", energyLimit);
    } else if (algorithm == "UCS") {
       path = UCS(marsTerrain, "start", "goal", energyLimit);
    } else if (algorithm == "A*") {
        path = AStar(marsTerrain, "start", "goal", energyLimit);
    }

    ofstream outputFile("output.txt");
    if (path.empty() || path.front() == "FAIL") {
        outputFile << "FAIL";
    } else {
        for (const auto& location : path) {
            outputFile << location << (location != path.back() ? " " : "");
        }
    }
    outputFile.close();
    return 0;
}