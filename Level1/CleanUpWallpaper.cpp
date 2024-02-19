#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer, dotS_min(2, 50), dotE_max(2, 0);
    for (int i = 0; i < wallpaper.size(); i++){
        for (int j = 0; j < wallpaper[i].length(); j++){
            if (wallpaper[i][j] == '#'){
                dotS_min = {min(dotS_min[0], i), min(dotS_min[1], j)};
                dotE_max = {max(dotE_max[0], i + 1), max(dotE_max[1], j + 1)};
            }
        }
    }
    answer = {dotS_min[0], dotS_min[1], dotE_max[0], dotE_max[1]};
    return answer;
}