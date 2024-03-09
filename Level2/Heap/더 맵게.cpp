#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, least_spicy;
    priority_queue<int, vector<int>, greater<int>> scoville_sorted(scoville.begin(), scoville.end());
    while (scoville_sorted.size() >= 2 && scoville_sorted.top() < K){
        least_spicy = scoville_sorted.top();
        scoville_sorted.pop();
        scoville_sorted.push(least_spicy + scoville_sorted.top() * 2);
        scoville_sorted.pop();
        answer++;
    }
    if (scoville_sorted.top() < K)  answer = -1;
    return answer;
}