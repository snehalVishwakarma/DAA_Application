#include <iostream>
using namespace std;

// Function to find the index of the minimum element in the array
int findMin(int arr[], int n) {
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) { // -1 indicates already used
            if (minIndex == -1 || arr[i] < arr[minIndex])
                minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    int files[n];
    cout << "Enter file sizes: ";
    for (int i = 0; i < n; i++)
        cin >> files[i];

    int totalCost = 0;

    // Repeat until all files are merged
    for (int count = 0; count < n - 1; count++) {
        // Find two smallest files
        int i = findMin(files, n);
        int first = files[i];
        files[i] = -1; // mark as used

        int j = findMin(files, n);
        int second = files[j];

        // Merge them and put the merged file back
        files[j] = first + second;

        // Add cost
        totalCost += first + second;
    }

    cout << "Minimum total merge cost: " << totalCost << endl;

    return 0;
}

