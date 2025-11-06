#include <iostream>
using namespace std;
// Function to merge two subarrays
void merge(float arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    float L[50], R[50]; // temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
// Merge Sort function
void mergeSort(float arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    float salary[50];
    cout << "Enter number of employees: ";
    cin >> n;
    cout << "\nEnter the salaries of " << n << " employees:\n";
    for (int i = 0; i < n; i++) {
        cout << "Salary of Employee " << i + 1 << ": ";
        cin >> salary[i];
    }
    mergeSort(salary, 0, n - 1);
    cout << "\nSalaries sorted in ascending order:\n";
    for (int i = 0; i < n; i++)
        cout << salary[i] << "  ";
    cout << endl;
    return 0;
}

