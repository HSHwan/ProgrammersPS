#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string, bool> wordDict;
    char endChar = words[0].front();
    for (int i = 0; i < words.size(); i++){
        if (wordDict.count(words[i]) || endChar != words[i].front()){
            answer = {i % n + 1, i / n + 1};
            break;
        }
        wordDict[words[i]] = true;
        endChar = words[i].back();
    }

    return answer;
}