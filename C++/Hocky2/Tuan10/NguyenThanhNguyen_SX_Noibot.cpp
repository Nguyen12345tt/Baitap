#include <iostream>
using namespace std;

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    int buoc = 1; // Khởi tạo biến bước
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Biến kiểm tra xem có hoán đổi không

        // Duyệt qua mảng, đẩy phần tử lớn nhất về cuối
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // Sắp xếp giảm dần
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        cout << "Bước " << buoc << ": ";
        printArray(arr, n);
        buoc++;

        // Nếu không có hoán đổi nào, mảng đã được sắp xếp
        if (!swapped) break;
    }
}

int main() {
    int arr[] = {4, 3, 1, 5, 7, 9, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    printArray(arr, n);

    // Chỉ sắp xếp 4 phần tử giữa (bỏ 2 đầu, bỏ 2 cuối)
    bubbleSort(arr + 2, 4); //Cũng coi như là bỏ 2 cuối nếu arr,4 

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n); // In toàn bộ mảng để thấy chỉ 4 phần tử giữa thay đổi

    return 0;
}
