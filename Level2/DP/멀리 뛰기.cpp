#include <string>
#include <vector>

using namespace std;

vector<vector<long long>> combination;

long long comb(int n, int r){
    if (combination[n][r])
        return combination[n][r];
    else {
        return combination[n][r] = (comb(n - 1, r - 1) + comb(n - 1, r)) % 1234567;
    }
}

long long solution(int n) {
    long long answer = 0;
    vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)).swap(combination);
    for (int i = 1; i <= n; i++){
        combination[i][i] = 1;
        combination[i][0] = 1;
    }
    
    for (int i = 0; i <= n / 2; i++){
        answer += comb(n - i, i);
        answer %= 1234567;
    }
    return answer;
}