#include <iostream>
#include <string>
using namespace std;
string mixmaus(string mau1, string mau2) {
    if ((mau1 == "red" && mau2 == "blue") || (mau1 == "blue" && mau2 == "red")) {
        return "purple";
    } else if ((mau1 == "red" && mau2 == "yellow") || (mau1 == "yellow" && mau2 == "red")) {
        return "orange";
    } else if ((mau1 == "blue" && mau2 == "yellow") || (mau1 == "yellow" && mau2 == "blue")) {
        return "green";
    } else {
        return "error";
    }
}

int main() {
    string mau1, mau2;
    cout << "Nhập màu thứ nhất (red, blue, yellow): ";
    cin >> mau1;
    cout << "Nhập màu thứ hai (red, blue, yellow): ";
    cin >> mau2;

    string result = mixmaus(mau1, mau2);
    if (result == "error") {
        cout << "Lỗi: Nhập sai màu rồi." << endl;
    } else {
        cout << "2 màu trộn với nhau " << mau1 << " và " << mau2 << " là " << result << endl;
    }

    return 0;
}
