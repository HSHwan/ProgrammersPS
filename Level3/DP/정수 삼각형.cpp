#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// General Dynamic Programming Problem
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for (int i = 0; i < triangle.size() - 1; i++){
        triangle[i + 1].front() += triangle[i].front();
        triangle[i + 1].back() += triangle[i].back();
        for (int j = 1; j < triangle[i + 1].size() - 1; j++){
            triangle[i + 1][j] += max(triangle[i][j - 1], triangle[i][j]);
        }
    }
    vector<int> result = triangle.back();
    answer = *max_element(result.begin(), result.end());
    return answer;
}