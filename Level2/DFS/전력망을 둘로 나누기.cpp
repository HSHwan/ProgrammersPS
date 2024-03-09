#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void searchTower(const vector<vector<int>>& graph, vector<bool>& visit, const int& pos){
    visit[pos] = true;
    for (int i = 0; i < graph[pos].size(); i++){
        if (!visit[graph[pos][i]])
            searchTower(graph, visit, graph[pos][i]);
    }
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n - 1, towerCount;
    vector<vector<int>> connectedTowers(n + 1);
    for (const vector<int>& wire : wires){
        connectedTowers[wire[0]].push_back(wire[1]);
        connectedTowers[wire[1]].push_back(wire[0]);
    }
    
    for (const vector<int>& wire : wires){
        vector<bool> visit(n + 1, false);
        visit[wire[1]] = true;
        searchTower(connectedTowers, visit, wire[0]);
        towerCount = count(visit.begin(), visit.end(), true) - 1;
        answer = min(answer, abs(n - 2 * towerCount));
    }
    
    return answer;
}