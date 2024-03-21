#include <string>
#include <vector>

using namespace std;

vector<vector<int>> nodeEdge;
vector<bool> nodeVisit;

int BFS(const int& startVertex){
    vector<int> nextVertex = {startVertex};
    vector<int> nowVertex;
    nodeVisit[1] = true;
    
    while (!nextVertex.empty()){
        nowVertex = nextVertex;
        nextVertex.clear();
        for (int i = 0; i < nowVertex.size(); i++){
            for (const int& vertex : nodeEdge[nowVertex[i]]){
                if (!nodeVisit[vertex]){
                    nextVertex.push_back(vertex);
                    nodeVisit[vertex] = true;
                }
            }
        }
    }
    
    return nowVertex.size();
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>>(n + 1).swap(nodeEdge);
    vector<bool>(n + 1, false).swap(nodeVisit);
    for (const vector<int>& oneEdge : edge){
        nodeEdge[oneEdge[0]].push_back(oneEdge[1]);
        nodeEdge[oneEdge[1]].push_back(oneEdge[0]);
    }
    
    answer = BFS(1);
    return answer;
}