#include <string>
#include <vector>

using namespace std;

vector<int> fibonacci;

int solution(int n) {
    int answer = 0;
    vector<int>(n + 1, 0).swap(fibonacci);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i <= n; i++)
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 1234567;
    answer = fibonacci[n];
    
    return answer;
}