#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, B_idx = -1;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for (const int& A_num : A){
        while (B_idx != B.size()){
            B_idx++;
            if (B[B_idx] > A_num){
                answer++;
                break;
            }
        }
    }
    return answer;
}