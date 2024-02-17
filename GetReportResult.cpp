#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    istringstream ss_parse;
    string user_id, report_id;
    vector<unordered_set<string>> report_list(id_list.size());
    unordered_map<string, int> user_id_idx;
    // user id => id_list index
    for (int i = 0; i < id_list.size(); i++)
        user_id_idx[id_list[i]] = i;
    // parse and record user id who reported another user
    for (const string& report_str : report){
        ss_parse.str(report_str);
        ss_parse >> user_id >> report_id;
        report_list[user_id_idx[report_id]].insert(user_id);
        ss_parse.clear();
    }
    // produce report result mail through the lisst 
    for (int i = 0; i < report_list.size(); i++){
        if (report_list[i].size() >= k){
            for (auto it = report_list[i].begin(); it != report_list[i].end(); it++){
                answer[user_id_idx[*it]]++;
            }
        }
    }
    return answer;
}