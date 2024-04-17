//-----------------------------------------------------------
#include <json/json.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <random>

class Ward {
public:
    string name;
private:
    Point3f entrance;
    Point3f exit;
    vector<Point3f> walls;
};

// Hàm trả về một vector các pair <Ward, int>
vector<pair<Ward, int>> generatePairs(vector<Ward>& wards, int triple, int single) {
    std::ifstream json_file("du_lieu.json", std::ifstream::binary);
    Json::Value root;
    json_file >> root;

    // Truy cập giá trị 'value' của 'numOfAgents'
    int numOfAgentsValue = root["numOfAgents"]["value"].asInt();
    
    if ((triple + single) != numOfAgentsValue) 
    {
        cout << "Errol";
    } 
    else 
    {    vector<pair<Ward, int>> result;

        // Tính tổng giá trị int của các pair
        int totalValue = triple * 3 + single;

        // Tạo một phân phối chuẩn (normal distribution) cho các giá trị int
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<> dist(totalValue / (triple + single), 10); // Điều chỉnh độ lệch chuẩn tùy ý

        // Tạo các pair và gán giá trị int
        for (const Ward& ward : wards) {
            int value = static_cast<int>(dist(gen));
            result.emplace_back(ward, value);
        }

        return result;
    }
}