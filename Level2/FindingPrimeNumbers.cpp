#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int answer = 0, maxNum;
    string strNum;
    sort(numbers.begin(), numbers.end(), greater<int>());
    vector<int> numbersCount(10, 0), numCount;
    for (const char& number : numbers)
        numbersCount[number - '0']++;
    maxNum = stoi(numbers);
    vector<bool> isPrime(maxNum + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= maxNum; i++){
        bool impossible = false;
        if (isPrime[i]){
            for (int j = 2 * i; j <= maxNum; j += i){
                isPrime[j] = false;
            }
            strNum = to_string(i);
            numCount = numbersCount;
            for (const char& num : strNum){
                numCount[num - '0']--;
                if (impossible = numCount[num - '0'] < 0)
                    break;
            }
            if (!impossible)
                answer++;
        }
    }
    
    return answer;
}