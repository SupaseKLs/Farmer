#include <iostream>
#include <vector>

using namespace std;

int main() {
    // จำนวนจังหวัด
    int num_provinces;
    cout << "ป้อนจำนวนจังหวัด: ";
    cin >> num_provinces;

    // เมทริกซ์ราคา
    vector<vector<int>> prices(num_provinces, vector<int>(3));

    // เมทริกซ์จำนวน
    vector<int> quantities(3);

    // กรอกข้อมูลราคา
    for (int i = 0; i < num_provinces; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "ป้อนราคาผลไม้ชนิด " << j + 1 << " ของจังหวัด " << i + 1 << ": ";
            cin >> prices[i][j];
        }
    }

    // กรอกข้อมูลจำนวน
    for (int i = 0; i < 3; i++) {
        cout << "ป้อนจำนวนผลไม้ชนิด " << i + 1 << ": ";
        cin >> quantities[i];
    }

    // คำนวณกำไรสูงสุดสำหรับแต่ละจังหวัด
    vector<int> max_profits(num_provinces);
    for (int i = 0; i < num_provinces; i++) {
        max_profits[i] = 0;
        for (int j = 0; j < 3; j++) {
            max_profits[i] += prices[i][j] * quantities[j];
        }
    }

    // หาจังหวัดที่ให้กำไรสูงสุด
    int max_profit_province = 0;
    for (int i = 1; i < num_provinces; i++) {
        if (max_profits[i] > max_profits[max_profit_province]) {
            max_profit_province = i;
        }
    }

    // แสดงผลลัพธ์
    for (int i = 0; i < num_provinces; i++) {
        cout << "จังหวัด " << i + 1 << endl;
        cout << "  กำไรสูงสุดที่คาดหวัง: " << max_profits[i] << " บาท" << endl;
    }

    cout << endl;

    // แสดงผลลัพธ์จังหวัดที่ให้กำไรสูงสุด
    cout << "จังหวัดที่ควรไปส่งผลไม้เพื่อให้ได้กำไรสูงสุดคือ: " << max_profit_province + 1 << endl;
    cout << "กำไรสูงสุดที่คาดหวัง: " << max_profits[max_profit_province] << " บาท" << endl;

    return 0;
}
