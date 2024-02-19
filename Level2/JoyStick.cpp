#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0, name_len = name.length(), move_cnt = name_len - 1, next_idx;
    for (int i = 0; i < name_len; i++){
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        next_idx = i + 1;
        while (next_idx < name_len && name[next_idx] == 'A')   next_idx++;
        move_cnt = min(move_cnt, i + name_len - next_idx + min(i, name_len - next_idx));
    }
    answer += move_cnt;
    return answer;
}