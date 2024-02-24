#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> gift_numbers, next_month_gifts;
    istringstream iss_parse;
    string sender_name, receiver_name;
    for (int i = 0; i < friends.size(); i++){
        gift_numbers[friends[i]] = 0;
        next_month_gifts[friends[i]] = 0;
        for (int j = 0; j < friends.size(); j++){
            if (friends[i] == friends[j])   continue;
            gift_numbers[friends[i] + " " + friends[j]] = 0;
        }
    }
    
    for (const string& gift : gifts){
        gift_numbers[gift]++;
        iss_parse.str(gift);
        iss_parse >> sender_name >> receiver_name;
        gift_numbers[sender_name]++;
        gift_numbers[receiver_name]--;
        iss_parse.clear();
    }
    
    for (int i = 0; i < friends.size(); i++){
        for (int j = 0; j < friends.size(); j++){
            if (friends[i] == friends[j])   continue;
            if (gift_numbers[friends[i] + " " + friends[j]] > gift_numbers[friends[j] + " " + friends[i]])
                next_month_gifts[friends[i]]++;
            else if (gift_numbers[friends[i] + " " + friends[j]] == gift_numbers[friends[j] + " " + friends[i]]){
                if (gift_numbers[friends[i]] > gift_numbers[friends[j]])
                    next_month_gifts[friends[i]]++;
            }
        }
    }
    
    answer = max_element(next_month_gifts.begin(), next_month_gifts.end(), [](const auto& a, const auto& b){ return a.second < b.second;})->second;
    return answer;
}