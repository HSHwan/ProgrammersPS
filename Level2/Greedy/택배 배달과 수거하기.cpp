#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int maxMoveLen = -1;
    for (int i = n - 1; i > 0; i--){
        deliveries[i - 1] += deliveries[i];
        pickups[i - 1] += pickups[i];
        if (deliveries[i] + pickups[i])
            maxMoveLen = max(maxMoveLen, i);
    }
    
    if (n == 1)
        answer = 2 * max(deliveries[0] / cap + !!(deliveries[0] % cap), pickups[0] / cap + !!(pickups[0] % cap));
    
    long long deliveryCapSum = 0, pickupCapSum = 0;
    while (maxMoveLen >= 0){
        deliveryCapSum += cap;
        pickupCapSum += cap;
        
        answer += (maxMoveLen + 1) * 2;
        for (int i = maxMoveLen; i >= 0; i--){
            if (deliveryCapSum >= deliveries[i] && pickupCapSum >= pickups[i])
                maxMoveLen--;
            else
                break;
        }
    }
    return answer;
}