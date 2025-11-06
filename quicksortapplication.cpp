#include <iostream>
using namespace std;
void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}
int partition(float arr[], int low, int high) {
    float pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(salary, 0, n - 1);
    cout << "\nSalaries sorted in ascending order:\n";
    for (int i = 0; i < n; i++)
        cout << salary[i] << "  ";
    cout << endl;
    return 0;
}

