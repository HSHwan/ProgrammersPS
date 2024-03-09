#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0, fatigue = 0, picks_sum = picks[0] + picks[1] + picks[2];
    map<string, int> mineFatigue;
    vector<int> intervalFatigueSum, mineralsCount;
    
    mineFatigue["diamond"] = 100;
    mineFatigue["iron"] = 10;
    mineFatigue["stone"] = 1;
    
    while(picks_sum * 5 < minerals.size()) minerals.pop_back();
    for (int i = 0; i < minerals.size() - 1; i++){
        fatigue += mineFatigue[minerals[i]];
        if (i % 5 == 4){
            intervalFatigueSum.push_back(fatigue);
            fatigue = 0;
        }
    }
    intervalFatigueSum.push_back(fatigue + mineFatigue[minerals.back()]);
    sort(intervalFatigueSum.begin(), intervalFatigueSum.end(), greater<int>());
    for (int i = 0; i < intervalFatigueSum.size(); i++){
        mineralsCount = {intervalFatigueSum[i] / 100, (intervalFatigueSum[i] / 10) % 10, intervalFatigueSum[i] % 10};
        if (i < picks[0]){
            answer += mineralsCount[0] + mineralsCount[1] + mineralsCount[2];
        }
        else if (i < picks[0] + picks[1]){
            answer += 5 * mineralsCount[0] + mineralsCount[1] + mineralsCount[2];
        }
        else {
            answer += 25 * mineralsCount[0] + 5 * mineralsCount[1] + mineralsCount[2];
        }
    }
    
    return answer;
}