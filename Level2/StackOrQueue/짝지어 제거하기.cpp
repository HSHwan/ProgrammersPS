#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s){
    int answer;
    stack<char> prevString;
    
    for (const char& ch : s){
        if (prevString.empty() || prevString.top() != ch)
            prevString.push(ch);
        else {
            prevString.pop();
        }
    }

    answer = prevString.empty();
    return answer;
}