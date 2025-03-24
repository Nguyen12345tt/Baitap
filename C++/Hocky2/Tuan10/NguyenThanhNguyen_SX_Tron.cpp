/*DauHaiPhong_SX_Tron.cpp*/
#include <iostream>
using namespace std;

// Hàm trộn hai nửa của mảng
int buoc = 1;
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo mảng tạm để lưu hai nửa
    int *L = new int[n1], *R = new int[n2];

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Trộn hai mảng con lại vào mảng chính
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) { //(4) Chỉnh dấu <= thành >= để sắp xếp giảm dần
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Giải phóng bộ nhớ
    delete[] L;
    delete[] R;
}

// Hàm đệ quy thực hiện thuật toán Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Gọi đệ quy để sắp xếp hai nửa
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn hai nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

// Hàm hiển thị mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Hàm main để chạy chương trình
int main() {
    int arr[] = {4, 3, 1, 5, 7, 9, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    printArray(arr, size);

    mergeSort(arr, 2, size - 1);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, size);

    return 0;
}