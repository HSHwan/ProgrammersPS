#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, currentWeight = 0;
    deque<int> waitingTrucks(truck_weights.begin(), truck_weights.end()), bridge(bridge_length, 0);
    
    while (!waitingTrucks.empty() || currentWeight){
        currentWeight -= bridge.front();
        bridge.pop_front();
        if (!waitingTrucks.empty() && currentWeight + waitingTrucks.front() <= weight){
            bridge.push_back(waitingTrucks.front());
            currentWeight += waitingTrucks.front();
            waitingTrucks.pop_front();
        }
        else    bridge.push_back(0);
        answer++;
    }
    
    return answer;
}