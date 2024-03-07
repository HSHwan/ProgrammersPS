#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool comp(string l, string r){
    for (int i = 0; i < l.length() && i < r.length(); i++)
        if (l[i] != r[i])   return l[i] < r[i];
    return l.length() < r.length();
}

int solution(string word) {
    int answer = 0, dictLen, startPos = -1;
    vector<string> dict = {"A", "E", "I", "O", "U"};
    for (int i = 0; i < 4; i++){
        dictLen = dict.size();
        startPos += pow(5, i); 
        for (int j = startPos; j < dictLen; j++){
            dict.push_back(dict[j] + "A");
            dict.push_back(dict[j] + "E");
            dict.push_back(dict[j] + "I");
            dict.push_back(dict[j] + "O");
            dict.push_back(dict[j] + "U");
        }
    }
    sort(dict.begin(), dict.end());
    answer = find(dict.begin(), dict.end(), word) - dict.begin() + 1;
    return answer;
}