/*NguyenThanhNguyen_TimKiemNhiPhan.cpp*/
#include <iostream>
using namespace std;

// Hàm tìm kiếm nhị phân (Iterative)
int binarySearch(int arr[], int right, int left, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        //In ra các cặp số so sánh
        cout<<"So sánh : "<<arr[mid]<<"\t"<<target<<endl;
        // Nếu phần tử nằm ở vị trí giữa
        if (arr[mid] == target)
            return mid;

        // Nếu phần tử lớn hơn target, tìm ở bên trái
        if (arr[mid] > target)
            right = mid - 1;
        else // Nếu nhỏ hơn target, tìm ở bên phải
            left = mid + 1;
    }
    return -1; // Không tìm thấy
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,9}; //(1) Đổi dãy số đã được sắp xếp
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3; //(2)Thay số 10 -> 3 để tìm giá trị 3

    int result = binarySearch(arr, n - 4, n - 1, target); //(3) Sửa 0 -> n-4 để luôn tìm 4 phần tử cuối
    if (result != -1)
        cout << "Phan tu duoc tim thay tai chi so: " << result << endl;
    else
        cout << "Phan tu khong ton tai trong mang" << endl;

    return 0;
}