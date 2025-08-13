/*DauHaiPhong_SX_Chen.cpp*/
#include <iostream>
using namespace std;

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertionSort(int arr[], int n) {
	for (int i = 2; i < n - 2; i++) { //(7) Sửa n -> n-2 để không sắp xếp 2 phần tử cuối
        int key = arr[i];  // Lấy phần tử hiện tại
        int j = i - 1;
		
        // Dịch các phần tử lớn hơn key sang phải
        while (j >= 2 && arr[j] < key) {//(4) Chuyển > thành < để sắp xếp giảm dần
            arr[j + 1] = arr[j];
            j--;
        }
        //(8) sửa j>=0 -> j>=2 ở dòng 18 để giữ 2 số đầu và số cuối
        // Chèn key vào đúng vị trí
        arr[j + 1] = key;
        cout<<"Buoc "<<i<<":"; //(6) In thêm Buoc 1,2,3,...
        printArray(arr, n);//(5) In mảng sau mỗi bước
    }
}


// Hàm main để chạy chương trình
int main() {
    int arr[] = {4,3,1,5,7,9,6,2};//(3)Nhập dãy số mới
    int n = sizeof(arr) / sizeof(arr[0]);//Tìm kích thước của mảng

    cout << "Mang ban dau: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}