#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0, diffCount;
    queue<string> wordQ;
    map<string, int> wordsCount;
    vector<bool> visited(words.size(), false);
    string nowWord = begin;
    wordQ.push(begin);
    wordsCount[begin] = 0;
    
    while (!wordQ.empty()){
        nowWord = wordQ.front();
        wordQ.pop();
        if (nowWord == target){
            answer = wordsCount[nowWord];
            break;
        }
            
        for (int i = 0; i < words.size(); i++){
            if (visited[i])
                continue;
            diffCount = 0;
            for (int j = 0; j < nowWord.size() && diffCount < 2; j++){
                if (nowWord[j] != words[i][j])
                    diffCount++;
            }
            if (diffCount == 1){
                wordsCount[words[i]] = wordsCount[nowWord] + 1;
                wordQ.push(words[i]);
                visited[i] = true;
            } 
        }
    }
    return answer;
}