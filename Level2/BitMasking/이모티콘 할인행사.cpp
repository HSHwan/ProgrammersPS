#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2, 0);
    int emoticonNum = emoticons.size();
    vector<float> discount = {0.4, 0.3, 0.2, 0.1}, emoticonDiscount(emoticonNum);
    
    
    for (int i = 0; i < (1 << emoticonNum * 2); i++){
        for (int j = 0; j < emoticonNum; j++){
            for (int k = 0; k < 4; k++){
                int jthTwoBit = (i >> 2 * j) & 3;
                if (jthTwoBit == k){
                    emoticonDiscount[j] = discount[k];
                    break;
                }
            }
        }
        
        int emoticonPriceSum = 0, emoticonPlusCount = 0;
        for (const vector<int>& user : users){
            int userPriceSum = 0;
            
            for (int j = 0; j < emoticonNum; j++){
                if (100 * emoticonDiscount[j] >= user[0]){
                    userPriceSum += emoticons[j] * (1 - emoticonDiscount[j]);
                }
            }
            if (userPriceSum >= user[1])
                emoticonPlusCount++;
            else
                emoticonPriceSum += userPriceSum;

        }
        
        if (answer[0] < emoticonPlusCount || 
           (answer[0] == emoticonPlusCount && answer[1] < emoticonPriceSum)){
            answer = {emoticonPlusCount, emoticonPriceSum};
        }
    }
    return answer;
}