#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1, seq_sum;
    for (int i = (n + 1) / 2; i > 0; i--){
        seq_sum = i;
        for (int j = i - 1; j > 0; j--){
            seq_sum += j;
            if (seq_sum == n){
                answer++;
                break;
            }
            else if (seq_sum > n)
                break;
        }
    }
    return answer;
}