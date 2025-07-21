#include <iostream>
using namespace std;
int main() {
    // Giá trị giỏ hàng
    int cartValue = 95; // đô

    // Tỷ lệ phần trăm thuế bán hàng của tiểu bang và quận
    int stateTaxPercent = 4; // phần trăm
    int countyTaxPercent = 2; // phần trăm

    // Tính thuế bán hàng của tiểu bang và quận
    int stateTax = (cartValue * stateTaxPercent) / 100;
    int countyTax = (cartValue * countyTaxPercent) / 100;

    // Tính tổng thuế bán hàng
    int totalTax = stateTax + countyTax;

    // In kết quả
    cout << "Tổng thuế bán hàng trên giỏ hàng 95 đô là: " << totalTax << " đô" << endl;

    return 0;
}
