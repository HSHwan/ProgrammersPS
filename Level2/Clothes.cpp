#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, vector<string>> clothes_combination;
    for (const vector<string>& one_clothes : clothes){
        clothes_combination[one_clothes[1]].push_back(one_clothes[0]);
    }
    for (auto it = clothes_combination.begin(); it != clothes_combination.end(); it++){
        answer *= it->second.size() + 1;
    }
    answer--;
    return answer;
}