#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n, bitCount = __builtin_popcount(n);
    while (__builtin_popcount(++answer) != bitCount){
        
    }
    return answer;
}