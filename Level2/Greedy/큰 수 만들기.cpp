#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    string::iterator numIt = number.begin(), maxIt;
    int nextCnt, lastLen = number.length() - k;
    
    while (answer.length() < lastLen && k > 0){
        maxIt = max_element(numIt, next(numIt, k + 1));
        answer += *maxIt;
        nextCnt = maxIt - numIt;
        advance(numIt, nextCnt + 1);
        k -= nextCnt;
    }

    answer += number.substr(numIt - number.begin(), lastLen - answer.length());
    return answer;
}