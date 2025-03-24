/*DauHaiPhong_SX_Nhanh.cpp*/
#include <iostream>
using namespace std;

// Hàm hiển thị mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Hàm hoán đổi hai phần tử
void swap(int &a, int &b, int arr[], int size) {
    int temp = a;
    a = b;
    b = temp;
    printArray(arr, size);
}

// Hàm phân hoạch (Chia mảng thành hai phần dựa vào phần tử chốt)
int partition(int arr[], int low, int high, int size) {
    int pivot = arr[high]; // Chọn phần tử chốt là phần tử cuối cùng
    int i = low - 1; // Chỉ mục của phần tử nhỏ hơn phần tử chốt

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot)  { // (4)Nếu phần tử lớn hơn phần tử chốt thì giảm dần
            i++;
            swap(arr[i], arr[j],arr,size);
        }
    }
    swap(arr[i + 1], arr[high],arr,size); // Đưa phần tử chốt về đúng vị trí
    return i + 1; // Trả về chỉ số của phần tử chốt sau khi sắp xếp
}

// Hàm QuickSort đệ quy
void quickSort(int arr[], int low, int high, int size) { //cho thêm 
    if (low < high) {
        int pivotIndex = partition(arr, low, high, size); // Lấy vị trí của phần tử chốt

        //(5,6) In ra từng bước sau mỗi lần phân hoạch

        quickSort(arr, low, pivotIndex - 1, size); // Sắp xếp phần bên trái của chốt
        quickSort(arr, pivotIndex + 1, high, size); // Sắp xếp phần bên phải của chốt
    }
}

// Hàm main để chạy chương trình
int main() {
    int arr[] = {4, 3, 1, 5, 7, 9, 6, 2}; //(3)Đổi số
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 3, size); //(7) Chỉnh số 0 -> 2 để bỏ 2 đầu 2 cuối
                                        //(6) Chỉnh size - 1 thành size - 3 để bỏ 2 cuối

    cout << "Mang sau khi sap xep: ";
    printArray(arr, size);

    return 0;
}