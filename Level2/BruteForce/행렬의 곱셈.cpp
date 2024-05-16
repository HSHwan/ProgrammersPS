#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int resultRow = arr1.size();
    int resultColumn = arr2[0].size();
    int sameLength = arr2.size();
    
    vector<vector<int>> answer(resultRow, vector<int>(resultColumn, 0));
    for (int i = 0; i < resultRow; i++) {
        for (int j = 0; j < sameLength; j++) {
            for (int k = 0; k < resultColumn; k++) {
                answer[i][k] += arr1[i][j] * arr2[j][k];
            }
        }
    }
    return answer;
}