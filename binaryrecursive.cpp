#include <iostream>
using namespace std;

int Binsearch(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1;  // Element not found
    }

    int mid = (low + high) / 2;

    if (arr[mid] == x) {
        return mid;
    } else if (x < arr[mid]) {
        return Binsearch(arr, low, mid - 1, x);
    } else {
        return Binsearch(arr, mid + 1, high, x);
    }
}

int main() {
    int arr[100], n, x;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> x;

    int result = Binsearch(arr, 0, n - 1, x);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

