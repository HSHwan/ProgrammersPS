#include <string>
#include <vector>
#include <stack>

using namespace std;

int checkCorrectParentheses(const string& parenthesesStr){
    stack<char> readyParentheses;
    
    for (int i = 0; i < parenthesesStr.length(); i++){
        if (parenthesesStr[i] == '(' || parenthesesStr[i] == '[' || parenthesesStr[i] == '{')
            readyParentheses.push(parenthesesStr[i]);
        else if (!readyParentheses.empty()){
            switch (parenthesesStr[i]){
                case ')' : {
                    if (readyParentheses.top() == '(')
                        readyParentheses.pop();
                    break;
                }
                case ']' : {
                    if (readyParentheses.top() == '[')
                        readyParentheses.pop();
                    break;
                }
                case '}' : {
                    if (readyParentheses.top() == '{')
                        readyParentheses.pop();
                    break;
                }
                default : {
                    return 0;
                    break;
                }
            }
        }
        else return 0;
    }
    
    return readyParentheses.empty();
}

int solution(string s) {
    int answer = 0;
    answer += checkCorrectParentheses(s);
    for (int i = 0; i < s.length() - 1; i++){
        s = s.substr(1, s.length() - 1) + s[0];
        answer += checkCorrectParentheses(s);
    }
    return answer;
}