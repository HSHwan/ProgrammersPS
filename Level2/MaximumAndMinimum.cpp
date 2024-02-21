#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    istringstream ss_parse(s);
    vector<int> nums;
    string str_num;
    while(ss_parse >> str_num){
        nums.push_back(stoi(str_num));
    }
    sort(nums.begin(), nums.end());
    string answer = to_string(nums.front()) + " " + to_string(nums.back());
    return answer;
}