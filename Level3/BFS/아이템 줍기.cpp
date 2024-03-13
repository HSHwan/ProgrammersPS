#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int MAX_VAL = 50;

bool isMovable(const vector<vector<int>>& map, const vector<vector<bool>>& visited, const pair<int, int>& pos){
    if (pos.X >= 2 * (MAX_VAL + 1) || pos.Y >= 2 * (MAX_VAL + 1) || pos.X < 0 || pos.Y < 0)
        return false;
    if (visited[pos.X][pos.Y] || !map[pos.X][pos.Y])
        return false;
    return true;
}

int BFS(vector<vector<int>> map, pair<int, int> pos, pair<int, int> target){
    pair<int, int> nowPos = pos, nextPos;
    queue<pair<int, int>> posQ;
    vector<vector<bool>> visited(2 * (MAX_VAL + 1), vector<bool>(2 * (MAX_VAL + 1), false));
    posQ.push(nowPos);
    visited[nowPos.X][nowPos.Y] = true;
    
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    while (!posQ.empty()){
        nowPos = posQ.front();
        posQ.pop();
        if (nowPos == target)
            return (map[target.X][target.Y] - 1) / 2;
        for (int i = 0; i < 4; i++){
            nextPos.X = nowPos.X + dir[i].X;
            nextPos.Y = nowPos.Y + dir[i].Y;
            if (isMovable(map, visited, nextPos)){
                map[nextPos.X][nextPos.Y] = map[nowPos.X][nowPos.Y] + 1;
                posQ.push(nextPos);
                visited[nextPos.X][nextPos.Y] = true;
            }
        }
        
    }
}

void drawRectangle(vector<vector<int>>& map, const vector<int>& rectangle){
    for (int i = 2 * rectangle[0]; i <= 2 * rectangle[2]; i++){
        map[i][2 * rectangle[1]] = 1;
        map[i][2 * rectangle[3]] = 1;
    }
    for (int i = 2 * rectangle[1]; i <= 2 * rectangle[3]; i++){
        map[2 * rectangle[0]][i] = 1;
        map[2 * rectangle[2]][i] = 1;
    }
}

void eraseInnerRectangle(vector<vector<int>>& map, const vector<int>& rectangle){
    for (int i = 2 * rectangle[0] + 1; i < 2 * rectangle[2]; i++){
        for (int j = 2 * rectangle[1] + 1; j < 2 * rectangle[3]; j++)
            map[i][j] = 0;
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    pair<int, int> character = make_pair(2 * characterX, 2 * characterY);
    pair<int, int> item = make_pair(2 * itemX, 2 * itemY);
    vector<vector<int>> graph(2 * (MAX_VAL + 1), vector<int>(2 * (MAX_VAL + 1), 0));
    for (int i = 0; i < rectangle.size(); i++){
        drawRectangle(graph, rectangle[i]);
    }
    for (int i = 0; i < rectangle.size(); i++){
        eraseInnerRectangle(graph, rectangle[i]);
    }
    
    answer = BFS(graph, character, item);
    return answer;
}