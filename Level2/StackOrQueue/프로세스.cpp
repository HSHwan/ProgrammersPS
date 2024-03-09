#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, firstProcess;
    deque<int> process_queue(priorities.begin(), priorities.end());
    sort(priorities.begin(), priorities.end());
    vector<int>::iterator maxIter = --priorities.end();
    
    while (!process_queue.empty()){
        firstProcess = process_queue.front();
        process_queue.pop_front();
        if (firstProcess != *maxIter){
            process_queue.push_back(firstProcess);
            if (location)
                location--;
            else
                location = process_queue.size() - 1;
        }
        else {
            maxIter--;
            answer++;
            if (location)
                location--;
            else    break;            
        }
    }
    return answer;
}