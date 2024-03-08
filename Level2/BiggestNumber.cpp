#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string& ls, const string& rs){
    return ls + rs > rs + ls;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_nums;
    for (const int& num : numbers){
        str_nums.push_back(to_string(num));   
    }
    sort(str_nums.begin(), str_nums.end(), comp);
    if (str_nums.front() == "0")
        answer = "0";
    else {
        for (const string& num : str_nums)
            answer += num;  
    }

    return answer;
}