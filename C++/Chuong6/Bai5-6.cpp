#include <iostream>
#include <cfloat> // Bao gồm thư viện cfloat để sử dụng DBL_MAX và DBL_MIN
using namespace std;

int main() {
    const int MONKEYS = 3;
    const int DAYS = 5;
    double food[MONKEYS][DAYS];
    double totalFood = 0;
    double minFood = DBL_MAX;
    double maxFood = DBL_MIN;

    // Nhập dữ liệu lượng thức ăn cho mỗi con khỉ mỗi ngày trong tuần
    for (int i = 0; i < MONKEYS; ++i) {
        for (int j = 0; j < DAYS; ++j) {
            do {
                cout << "Nhập lượng thức ăn (pounds) cho con khỉ " << i + 1 << " vào ngày " << j + 1 << ": ";
                cin >> food[i][j];
                if (food[i][j] < 0) {
                    cout << "Lượng thức ăn không được là số âm. Vui lòng nhập lại." << endl;
                }
            } while (food[i][j] < 0);
            totalFood += food[i][j];
            if (food[i][j] < minFood) {
                minFood = food[i][j];
            }
            if (food[i][j] > maxFood) {
                maxFood = food[i][j];
            }
        }
    }

    // Tính lượng thức ăn trung bình mỗi ngày của cả gia đình khỉ
    double averageFoodPerDay = totalFood / (MONKEYS * DAYS);

    // Hiển thị báo cáo
    cout << "Lượng thức ăn trung bình mỗi ngày của cả gia đình khỉ: " << averageFoodPerDay << " pounds" << endl;
    cout << "Lượng ăn ít nhất trong cả tuần và mọi con khỉ: " << minFood << " pounds" << endl;
    cout << "Lượng ăn nhiều nhất trong cả tuần và mọi con khỉ: " << maxFood << " pounds" << endl;

    return 0;
}
