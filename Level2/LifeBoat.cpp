#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, restWeight;
    vector<int> weightPeopleNumber(limit + 1, 0);
    sort(people.begin(), people.end(), greater<int>());
    
    for (const int& weight : people){
        weightPeopleNumber[weight]++;
    }
    
    for (int i = 0; i < people.size(); i++){
        restWeight = limit;
        if (weightPeopleNumber[people[i]]){
            weightPeopleNumber[people[i]]--;
            restWeight -= people[i];
            for (int j = restWeight; j > 0; j--){
                if (weightPeopleNumber[j]){
                    weightPeopleNumber[j]--;
                    break;
                }
            }
            answer++;
        }
    }
    
    return answer;
}