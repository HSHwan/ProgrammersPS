#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> work_rest(works.begin(), works.end());
    for (int i = 0; i < n && work_rest.top(); i++){
        work_rest.push(work_rest.top() - 1);
        work_rest.pop();
    }
    while (!work_rest.empty()){
        answer += work_rest.top() * work_rest.top();
        work_rest.pop();
    }
    return answer;
}