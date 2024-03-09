#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> terms_idx;
    string terms_type, terms_date;
    istringstream ss_parse;
    int year_diff, month_diff, day_diff, dead_line_day;
    for (int i = 0; i < terms.size(); i++){
        terms_idx[terms[i].front()] = i;
    }
    
    for (int i = 0; i < privacies.size(); i++){
        ss_parse.str(terms[terms_idx[privacies[i].back()]]);
        ss_parse >> terms_type >> terms_date;       
        dead_line_day = stoi(terms_date) * 28;
        year_diff = stoi(today.substr(0, 4)) - stoi(privacies[i].substr(0, 4));
        month_diff = stoi(today.substr(5, 2)) - stoi(privacies[i].substr(5, 2));
        day_diff = stoi(today.substr(8, 2)) - stoi(privacies[i].substr(8, 2));
        if (dead_line_day <= 12 * 28 * year_diff + 28 * month_diff + day_diff)
            answer.push_back(i + 1);
        ss_parse.clear();
    }
    return answer;
}