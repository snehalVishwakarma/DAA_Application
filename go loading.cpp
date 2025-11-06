#include <iostream>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of packages: ";
    cin >> n;

    cout << "Enter truck capacity (in kg): ";
    cin >> capacity;

    int profit[20], weight[20];
    float ratio[20];

    cout << "Enter profit and weight of each package:\n";
    for (int i = 0; i < n; i++) {
        cin >> profit[i] >> weight[i];
        ratio[i] = (float)profit[i] / weight[i];
    }

    // Sort packages by profit/weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap profits
                int tempP = profit[i];
                profit[i] = profit[j];
                profit[j] = tempP;

                // Swap weights
                int tempW = weight[i];
                weight[i] = weight[j];
                weight[j] = tempW;
            }
        }
    }

    float totalProfit = 0.0;
    int remaining = capacity;

    cout << "\nPackages loaded:\n";
    cout << "Profit\tWeight\tTaken(%)\n";

    for (int i = 0; i < n; i++) {
        if (remaining == 0)
            break;

        if (weight[i] <= remaining) {
            // Take full package
            remaining -= weight[i];
            totalProfit += profit[i];
            cout << profit[i] << "\t" << weight[i] << "\t" << "100%\n";
        } else {
            // Take fractional part
            float fraction = (float)remaining / weight[i];
            totalProfit += profit[i] * fraction;
            cout << profit[i] << "\t" << weight[i] << "\t" << fraction * 100 << "%\n";
            remaining = 0;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}

