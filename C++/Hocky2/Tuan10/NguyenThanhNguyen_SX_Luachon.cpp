#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < 6; i++) {
        int maxIndex = i; // (4)Thay minIndex bằng maxIndex để sắp xếp giảm dần
        cout << "Bước " << i + 1 << ": ";

        // Tìm phần tử lớn nhất trong 6 phần tử đầu tiên
        for (int j = i + 1; j < 6; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        // Hoán đổi phần tử lớn nhất với phần tử đầu tiên của phần chưa sắp xếp
        swap(arr[i], arr[maxIndex]);

        // In mảng sau mỗi bước
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm main để chạy chương trình
int main() {
    int arr[] = {4, 3, 1, 5, 7, 9, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}