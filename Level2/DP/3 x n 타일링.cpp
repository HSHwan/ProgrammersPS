#include <string>
#include <vector>

using namespace std;
const int MOD = 1000000007;

int solution(int n) {
    int answer = 0;
    vector<long long> nthRectangles(n + 1, 0);
    nthRectangles[0] = 1;
    nthRectangles[2] = 3;
    
    for (int i = 4; i <= n; i += 2){
        nthRectangles[i] = (nthRectangles[i - 2] * 3) % MOD;
        for (int j = 0; j <= i - 4; j += 2){
            nthRectangles[i] += (nthRectangles[j] * 2) % MOD;
        }
    }
    answer = nthRectangles[n] % MOD;
    return answer;
}