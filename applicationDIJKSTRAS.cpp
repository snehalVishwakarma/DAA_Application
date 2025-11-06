#include <iostream>
using namespace std;

#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX], visited[MAX], pred[MAX];
    int i, j, count, mindistance, nextnode;

    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
        distance[i] = graph[start][i];
        visited[i] = 0;
        if (graph[start][i] != INF && i != start)
            pred[i] = start;
        else
            pred[i] = -1;
    }

    distance[start] = 0;
    visited[start] = 1;

    for (count = 1; count < n; count++) {
        mindistance = INF;
        // Find the next unvisited node with minimum distance
        for (i = 0; i < n; i++)
            if (!visited[i] && distance[i] < mindistance) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        // Update distances of adjacent nodes
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + graph[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + graph[nextnode][i];
                    pred[i] = nextnode;
                }
    }

    // Print the shortest distances
    cout << "\nShortest distances from city " << start << ":\n";
    for (i = 0; i < n; i++) {
        cout << "To city " << i << " = " << distance[i] << "\n";
    }
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter adjacency matrix (use 0 if no direct road):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF; // represent no road as INF
        }

    cout << "Enter starting city: ";
    cin >> start;

    dijkstra(graph, n, start);

    return 0;
}

