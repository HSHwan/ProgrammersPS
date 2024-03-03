#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, presentTime = 0, jobCount = 0;
    vector<int> job;
    priority_queue<vector<int>, vector<vector<int>>, compare> jobsTopPriority;
    sort(jobs.begin(), jobs.end());
    
    while (jobCount < jobs.size() || !jobsTopPriority.empty()){
        if (jobCount < jobs.size() && jobs[jobCount][0] <= presentTime){
            jobsTopPriority.push(jobs[jobCount++]);
            continue;
        }
        if (!jobsTopPriority.empty()){
            job = jobsTopPriority.top();
            presentTime += job[1];
            answer += presentTime - job[0];
            jobsTopPriority.pop();
        }
        else {
            presentTime = jobs[jobCount][0];
        }
    }
    answer /= jobCount;
    return answer;
}