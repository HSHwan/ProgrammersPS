#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2, 0), route_dir, next_pos;
    unordered_map<char, vector<int>> route_dirs({{'E', {0, 1}}, {'W', {0, -1}}, {'S', {1, 0}}, {'N', {-1, 0}}});
    char route_op;
    string route_len;
    int route_len_int, park_w = park.size(), park_h = park.front().length();
    bool start_set = false;
    istringstream ss_parse;
    for (int i = 0; i < park.size() && !start_set; i++){
        for (int j = 0; j < park[i].length(); j++){
            if (park[i][j] == 'S'){
                answer[0] = i;
                answer[1] = j;
                start_set = true;
                break;
            }
        }
    }
    
    for (const string& cmd : routes){
        ss_parse.str(cmd);
        ss_parse >> route_op >> route_len;
        route_len_int = stoi(route_len);
        route_dir = route_dirs[route_op];
        next_pos = answer;

        for (int i = 0; i < route_len_int; i++){
            next_pos[0] += route_dir[0];
            next_pos[1] += route_dir[1];
            if (next_pos[0] >= park_w || next_pos[1] >= park_h || next_pos[0] < 0 || next_pos[1] < 0 || park[next_pos[0]][next_pos[1]] == 'X'){
                next_pos = answer;
                break;
            }
        }
        answer = next_pos;
        ss_parse.clear();
    }
    
    return answer;
}