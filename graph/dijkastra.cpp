#include <iostream>
#include <vector>
#include <queue>
#include <climits> // Required for INT_MAX

using namespace std;

// Define a pair: {weight, node_index}
// We use 'weight' first because the Priority Queue sorts by the first element.
typedef pair<int, int> pii;

// Function to run Dijkstra's Algorithm
vector<int> dijkstra(int V, vector<vector<pii>>& graph, int start_node) {
    // 1. Create the Min-Priority Queue
    // Syntax: priority_queue<Type, Container, Comparator>
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // 2. Initialize distances to "Infinity"
    vector<int> dist(V, INT_MAX);

    // 3. Set Source distance to 0 and add to queue
    dist[start_node] = 0;
    pq.push({0, start_node}); // {distance, node}

    while (!pq.empty()) {
        // 4. Get the node with the smallest distance
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // 5. Lazy Deletion (Optimization)
        // If we found a shorter path to this node previously, skip this "stale" entry.
        if (current_dist > dist[current_node]) {
            continue;
        }

        // 6. Explore Neighbors
        for (auto edge : graph[current_node]) {
            int neighbor = edge.first;     // The connected node
            int edge_weight = edge.second; // Cost to get there

            // 7. Relaxation Step
            // If (path to current) + (edge weight) is shorter than (known path to neighbor)
            if (dist[current_node] + edge_weight < dist[neighbor]) {
                dist[neighbor] = dist[current_node] + edge_weight;
                
                // Push the new, better path to the queue
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}

int main() {
    // Mapping Nodes to Integers for C++:
    // S = 0, A = 1, B = 2, C = 3
    int V = 4;
    int source = 0; // Node S

    // Create Adjacency List
    // graph[u] contains pairs of {neighbor, weight}
    vector<vector<pii>> graph(V);

    // Adding the edges from our Example:
    // 1. S -> A (Cost 4)
    graph[0].push_back({1, 4});
    // 2. S -> B (Cost 2)
    graph[0].push_back({2, 2});
    // 3. B -> A (Cost 1) ** The Shortcut **
    graph[2].push_back({1, 1});
    // 4. B -> C (Cost 5)
    graph[2].push_back({3, 5});
    // 5. A -> C (Cost 1)
    graph[1].push_back({3, 1});

    // Run Algorithm
    vector<int> shortest_paths = dijkstra(V, graph, source);

    // Print Results
    cout << "Shortest Paths from Node S (0):" << endl;
    cout << "-------------------------------" << endl;
    cout << "Node S (0): " << shortest_paths[0] << endl;
    cout << "Node A (1): " << shortest_paths[1] << endl;
    cout << "Node B (2): " << shortest_paths[2] << endl;
    cout << "Node C (3): " << shortest_paths[3] << endl;

    return 0;
}