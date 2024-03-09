#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return min(a[0], a[1]) < min(b[0], b[1]);
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    const int MAX_LEN = 30000;
    vector<int> common_area(2, MAX_LEN + 1);
    sort(routes.begin(), routes.end());
    
    for (vector<int> route : routes){
        if (route[0] > route[1])    swap(route[0], route[1]);
        if (common_area[0] <= route[0] && common_area[1] >= route[0]){
            common_area = {max(common_area[0], route[0]), min(common_area[1], route[1])};
        }
        else {
            common_area = route;
            answer++;
        }
    }
    return answer;
}