#include <iostream>
using namespace std;

int step = 1; // Biến đếm số bước

// Hàm hoán đổi hai phần tử
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm chia mảng theo phần tử chốt (pivot)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử chốt là phần tử cuối
    int i = low - 1;       // Vị trí phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) { // Sắp xếp giảm dần (>= thay vì <=)
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // Đưa pivot về đúng vị trí
    return i + 1;
}

// Hàm Quick Sort đệ quy
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // In ra từng bước
        cout << "Bước " << step << ": ";
        for (int i = low; i <= high; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        step++;

        quickSort(arr, low, pi - 1);  // Sắp xếp nửa trái
        quickSort(arr, pi + 1, high); // Sắp xếp nửa phải
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm main
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 8, 15}; // Mảng có 8 phần tử
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mảng ban đầu: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr, n);

    return 0;
}
