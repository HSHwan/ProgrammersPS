#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w){
    int answer = 0, noWaveMinIdx = 1, noWaveMaxIdx;
    for (const int& station : stations){
        noWaveMaxIdx = station - w - 1;
        if (noWaveMaxIdx >= noWaveMinIdx){
            answer += 1 + (noWaveMaxIdx - noWaveMinIdx) / (1 + 2 * w);
        }
        noWaveMinIdx = station + w + 1;
    }
    if (noWaveMinIdx <= n){
        answer += 1 + (n - noWaveMinIdx) / (1 + 2 * w);
    }
    return answer;
}