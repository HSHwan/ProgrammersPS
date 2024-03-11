#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0, productCount;
    unordered_map<string, int> productNumber;
    
    for (int i = 0; i < want.size(); i++){
        productNumber[want[i]] = i;
    }
    
    for (int i = 0; i < discount.size() - 9; i++){
        vector<int> wantNumber = number;
        productCount = 10;
        for (int j = i; j < i + 10; j++){
            if (productNumber.count(discount[j]) && wantNumber[productNumber[discount[j]]]){
                wantNumber[productNumber[discount[j]]]--;
                productCount--;
            }
            else break;
        }
        if (!productCount)
            answer++;
    }
    
    return answer;
}