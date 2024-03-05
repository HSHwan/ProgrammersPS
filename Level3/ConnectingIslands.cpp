#include <string>
#include <vector>
#include <algorithm>

#define INF (~0U >> 2)
using namespace std;

int getSmallNode(const vector<bool>& visit, const vector<int>& vCost){
    int minVal = INF, minPos = 0;
    for (int i = 0; i < vCost.size(); i++){
        if (vCost[i] < minVal && !visit[i]){
            minVal = vCost[i];
            minPos = i;
        }
    }
    return minPos;
}

int dijkstra(const vector<vector<int>>& vCosts, const int& start){
    int N = vCosts.size(), minNodeNum, costSum = 0;
    vector<int> vStart = vCosts[start];
    vector<bool> visit(N, false);
    visit[start] = true;
    
    for (int i = 0; i < N - 1; i++){
        minNodeNum = getSmallNode(visit, vStart);
        visit[minNodeNum] = true;
        for (int j = 0; j < N; j++){
            if (!visit[j]){
                vStart[j] = min(vStart[j], vCosts[minNodeNum][j]);
            }
        }
    }
    
    for (const int& cost : vStart)
        costSum += cost;
        
    return costSum;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> vertexCosts(n, vector<int>(n, INF));
    for (int i = 0; i < costs.size(); i++){
        vertexCosts[costs[i][0]][costs[i][1]] = costs[i][2];
        vertexCosts[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    vertexCosts[0][0] = 0;
    answer = dijkstra(vertexCosts, 0);

    return answer;
}