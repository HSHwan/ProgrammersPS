#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0, column_len = relation[0].size(), row_len = relation.size();
    set<string> relation_tuples;
    vector<int> candidate_keys;
    string relation_tuple;
    bool not_minimal;
    
    for (int i = 1; i < (1 << column_len); i++){
        not_minimal = false;
        for (const int& candidate_key : candidate_keys){
            if (!(candidate_key & ~i)){
                not_minimal = true; 
                break;
            }
        }
        if (not_minimal)    continue;
        for (int j = 0; j < row_len; j++){
            relation_tuple = ""; 
            for (int k = 0; k < column_len; k++){
                if (i & (1 << k))
                    relation_tuple += relation[j][k];
            }
            relation_tuples.insert(relation_tuple);
        }
        
        if (relation_tuples.size() == row_len){
            candidate_keys.push_back(i);
            answer++;
        }
        relation_tuples.clear();
    }
    
    return answer;
}