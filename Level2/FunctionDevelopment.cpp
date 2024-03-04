#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int function_count, period;
    const int MAX_PROGRESS = 100;
    deque<int> progresses_period(progresses.begin(), progresses.end());
    for (int i = 0; i < progresses_period.size(); i++){
        progresses_period[i] = 100 - progresses_period[i];
        progresses_period[i] = progresses_period[i] / speeds[i] + !!(progresses_period[i] % speeds[i]);
    }
    
    while (!progresses_period.empty()){
        period = progresses_period.front();
        progresses_period.pop_front();
        function_count = 1;
        while (!progresses_period.empty() && period >= progresses_period.front()){
            progresses_period.pop_front();
            function_count++;
        }
        answer.push_back(function_count);
    }
    return answer;
}