#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0, tangerine_cnt = k, maxTangerineSize = *max_element(tangerine.begin(), tangerine.end());
    vector<int> all_tangerines(maxTangerineSize + 1, 0);
    for (const int& tang : tangerine){
        all_tangerines[tang]++;
    }
    sort(all_tangerines.begin(), all_tangerines.end(), greater<int>());
    for (const int& tang_cnt : all_tangerines){
        tangerine_cnt -= tang_cnt;
        answer++;
        if (tangerine_cnt <= 0)
            break;
    }
    return answer;
}