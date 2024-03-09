#include <string>
#include <vector>
#include <deque>
#include <algorithm>

#define INF (~0U >> 2)
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int minPrice = INF, priceSeconds = prices.size();
    deque<int> afterPrices;
    
    for (int i = 0; i < priceSeconds; i++){
        if (prices.back() <= minPrice){
            minPrice = prices.back();
            afterPrices.clear();
            answer.push_back(i);
        }
        else {
            for (int j = 0; j < afterPrices.size(); j++){
                if (prices.back() > afterPrices[j]){
                    answer.push_back(j + 1);
                    break;
                }
            }
        }
        afterPrices.push_front(prices.back());
        prices.pop_back();
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}