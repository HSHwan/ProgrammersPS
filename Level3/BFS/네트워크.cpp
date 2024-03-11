#include <string>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& vertexs, vector<bool>& visited, const int& start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()){
        int parentComputer = q.front();
        q.pop();
        for (int i = 0; i < vertexs.size(); i++){
            if (!visited[i] && vertexs[parentComputer][i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);
    for (int i = 0; i < n; i++){
        if (!visit[i]){
            BFS(computers, visit, i);
            answer++;
        }
    }
    
    return answer;
}