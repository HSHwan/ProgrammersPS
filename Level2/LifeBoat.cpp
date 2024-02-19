#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, weight_sum;
    sort(people.begin(), people.end());
    while (!people.empty()){
        weight_sum = limit - people.back();
        people.pop_back();
        answer++;
        for (int i = people.size() - 1; i >= 0; i--){
            if (people[i] <= weight_sum){
                people.erase(people.begin() + i);
                weight_sum -= people[i];
            }
        }
    }
    return answer;
}