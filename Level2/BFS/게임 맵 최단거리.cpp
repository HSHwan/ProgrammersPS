#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

bool isMovable(const vector<vector<int>>& map, const vector<vector<bool>>& visit, const vector<int>& pos){
    if (pos[0] >= map.size() || pos[1] >= map[0].size() || pos[0] < 0 || pos[1] < 0)
        return false;
    if (visit[pos[0]][pos[1]] || !map[pos[0]][pos[1]])
        return false;
    return true;
}

int BFS(vector<vector<int>> map){
    vector<int> nowPos(2, 0), nextPos = nowPos;
    vector<vector<bool>> visit(map.size(), vector<bool>(map[0].size(), false));
    queue<vector<int>> posQ;
    posQ.push(nowPos);
    visit[0][0] = true;
    
    while (!posQ.empty()){
        nowPos = posQ.front();
        posQ.pop();
        for (int i = 0; i < 4; i++){
            nextPos[0] = nowPos[0] + dir[i][0];
            nextPos[1] = nowPos[1] + dir[i][1];
            if (isMovable(map, visit, nextPos)){
                map[nextPos[0]][nextPos[1]] = map[nowPos[0]][nowPos[1]] + 1;
                posQ.push(nextPos);
                visit[nextPos[0]][nextPos[1]] = true;
            }
        }
    }
    return map.back().back() != 1 ? map.back().back() : -1;
}

int solution(vector<vector<int>> maps){
    int answer = BFS(maps);
    return answer;
}