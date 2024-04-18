#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> nextNumbers;
    for (auto it = numbers.rbegin(); it != numbers.rend(); it++){
        while (!nextNumbers.empty() && *it >= nextNumbers.top())
            nextNumbers.pop();
        int backGreaterNum = nextNumbers.empty() ? -1 : nextNumbers.top();
        answer.push_back(backGreaterNum);
        nextNumbers.push(*it);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}