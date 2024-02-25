#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0, tangerine_cnt = k;
    map<int, int> all_tangerines;
    for (const int& tang : tangerine){
        if (all_tangerines.count(tang) > 0)
            all_tangerines[tang]++;
        else
            all_tangerines[tang] = 1;
    }
    vector<pair<int, int>> tangerine_sorted(all_tangerines.begin(), all_tangerines.end());
    sort(tangerine_sorted.begin(), tangerine_sorted.end(), [](const auto& a, const auto& b){ return a.second > b.second;});
    for (const auto& tang_cnt : tangerine_sorted){
        tangerine_cnt -= tang_cnt.second;
        answer++;
        if (tangerine_cnt <= 0)
            break;
    }
    return answer;
}