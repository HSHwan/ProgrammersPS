#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while (s != "1"){
        string convertedStr = "";
        
        for (const char& ch : s){
            if (ch == '1')
                convertedStr += ch;
            else
                answer[1]++;
        }
        
        int strLen = convertedStr.length();
        convertedStr = "";
        while (strLen){
            convertedStr = to_string(strLen % 2) + convertedStr;
            strLen /= 2;
        }
        s = convertedStr;
        answer[0]++;
    }
    
    return answer;
}