#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> tupleSet;

bool comp(const vector<int>& a, const vector<int>& b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer, miniSet;
    string setNum;
    for (int i = 1; i < s.length() - 1; i++){
        if (s[i] == '{'){
            setNum = "";
            while (true){
                i++;
                if (s[i] == ','){
                    miniSet.push_back(stoi(setNum));
                    setNum = "";
                }
                else if (s[i] == '}'){
                    miniSet.push_back(stoi(setNum));
                    break;
                }
                else {
                    setNum += s[i];
                }
            }
            
            tupleSet.push_back(miniSet);
            miniSet.clear();
        }
    }
    
    sort(tupleSet.begin(), tupleSet.end(), [](const auto& a, const auto& b){ return a.size() < b.size(); });
    unordered_map<int, bool> tupleElementCheck;
    for (const vector<int>& set : tupleSet){
        for (const int& element : set){
            if (!tupleElementCheck.count(element)){
                tupleElementCheck[element] = true;
                answer.push_back(element);
                break;
            }
        }
    }

    return answer;
}