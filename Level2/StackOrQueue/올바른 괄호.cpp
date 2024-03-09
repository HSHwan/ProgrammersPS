#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s){
    bool answer = true;
    stack<char> openBrackets;
    
    for (const char& ch : s){
        if (ch == ')'){
            if (openBrackets.empty()){
                answer = false;
                break;
            }
            else
                openBrackets.pop();
        }
        else    openBrackets.push('(');
    }
    if (!openBrackets.empty())
        answer = false;

    return answer;
}