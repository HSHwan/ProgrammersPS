#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    int pos;
    unordered_map<string, int> players_pos;
    for (int i = 0; i < players.size(); i++){
        players_pos[players[i]] = i;
    }
    
    for (const string& call : callings){
        pos = players_pos[call];
        swap(answer[pos], answer[pos - 1]);
        players_pos[answer[pos]]++;
        players_pos[answer[pos - 1]]--;
    }
    return answer;
}