#include <string>
#include <vector>

using namespace std;
// General Dynamic Programming Problem
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> pos_dp(101, vector<int>(101, 0));
    for (const vector<int>& puddle : puddles){
        pos_dp[puddle[0]][puddle[1]] = -1;
    }
    pos_dp[1][1] = 1;
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (pos_dp[i][j] == -1)
                pos_dp[i][j] = 0;
            else
                pos_dp[i][j] += (pos_dp[i - 1][j] + pos_dp[i][j - 1]) % 1000000007;
        }
    }
    answer = pos_dp[m][n];
    return answer;
}