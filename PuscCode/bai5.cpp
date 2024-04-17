#include "newImplement/object/Pedestrian"
#include "bai4.cpp"
#include "newImplement/object/Ward"
#include <map>
// gia su co numVisitor tu bai truoc

int chon_1_ward(unordered_map<int,int>& mp){
    int wardMax = *(mp.begin()).first;
    for (auto it : mp){
        if (it.second > mp[wardMax]) wardMax = it.first;
    }
    mp[wardMax]--;
    if (mp[wardMax] == 0) mp.erase[wardMax];
    return wardMax;
}

vector<int> chon_3_ward(unordered_map<int,int>& mp){
    vector<pair<int, int>> pairs(myMap.begin(), myMap.end());

    // Sắp xếp vector theo giá trị (value) giảm dần
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    // Tạo một vector chứa 3 key lớn nhất
    vector<int> top3Keys;
    for (int i = 0; i < min(3, (int)pairs.size()); ++i) {
        top3Keys.push_back(pairs[i].first);
        mp[pairs[i].first]--;
        if (mp[pairs[i].first] == 0) mp.erase[pairs[i].first];
    }
    return top3Keys;
}

void bai5(vector<Pedestrian*>& pedestrians, vector<Ward>& wards){
    int single = numVisitor;
    int triple = pedestrians.size() - single;
            unordered_map<int,int> mp; // key la index cua pair , value la gia tri pair.second
    do{
        mp.clear();
        vector<pair<Ward, int>> WardCounter  = generatePairs(wards, triple ,single);
        for (int i=0;i< WardCounter.size();++i){
            mp[i] = WardCounter[i].second;
        }
        for (auto it : pedestrians){
            if (it->getType() == visitor) {
                vector<Ward> hisJourney;
                hisJourney.push_back(WardCounter[chon_1_ward(mp)].first);
                it->setJourney(hisJourney);
            }
            else {
                vector<Ward> hisJourney;
                vector<int> a = chon_3_ward(mp);
                for (int i=0;i<3;++i){
                    isJourney.push_back(WardCounter[a[i]].first);
                }
            }   
        }
    }
    while(!mp.empy());

    
}
