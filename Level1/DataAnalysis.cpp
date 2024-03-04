#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    vector<string> data_seq = {"code", "date", "maximum", "remain"};
    int ext_idx = find(data_seq.begin(), data_seq.end(), ext) - data_seq.begin(),
        sort_idx = find(data_seq.begin(), data_seq.end(), sort_by) - data_seq.begin();
    
    for (const vector<int>& d : data){
        if (d[ext_idx] < val_ext){
            answer.push_back(d);
        }
    }
    
    sort(answer.begin(), answer.end(), [&sort_idx](const vector<int>& a, const vector<int>& b){ return a[sort_idx] < b[sort_idx];});
    
    return answer;
}