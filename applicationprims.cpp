#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    int cost[10][10];
    cout << "Enter the cost matrix (0 if no direct connection):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999; // replace 0 with large value
        }
    }

    int visited[10] = {0};
    visited[0] = 1; // start from city 0
    int edges = 0, minCost = 0;

    cout << "\nConnections used for minimum cost network:\n";
    while (edges < n - 1) {
        int min = 999, a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            cout << "Connect City " << a << " to City " << b << "  Cost: " << min << endl;
            visited[b] = 1;
            minCost += min;
            edges++;
        }
    }

    cout << "\nTotal Minimum Cable Cost = " << minCost << endl;

    return 0;
}

