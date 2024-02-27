#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#define arrow_info(x) get<0>(x)
#define arrow_count(x) get<1>(x)
#define arrow_score(x) get<2>(x)

using namespace std;

typedef tuple<vector<int>, int, int> score_info;

bool comp(const score_info& a, const score_info& b){
    if (arrow_score(a) == arrow_score(b)){
        for (int i = 10; i >= 0; i--){
            if (arrow_info(a)[i] != arrow_info(b)[i])
                return arrow_info(a)[i] > arrow_info(b)[i];
        }
    }
    return arrow_score(a) > arrow_score(b);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<score_info> score_cases(1, make_tuple(vector<int>(11, 0), n, 0));
    int case_cnt, arrow_cnt;
    score_info score_case;
    
    for (int i = 0; i < 10; i++){
        case_cnt = score_cases.size();
        for (int j = 0; j < case_cnt; j++){
            score_case = score_cases[j];
            arrow_score(score_cases[j]) -= info[i] ? 10 - i : 0;
            if (arrow_count(score_case) >= info[i] + 1){
                arrow_info(score_case)[i] = info[i] + 1;
                arrow_count(score_case) -= info[i] + 1;
                arrow_score(score_case) += 10 - i;
                score_cases.push_back(score_case);
            }
        }
    }
    for (score_info& sc : score_cases){
        arrow_info(sc).back() = arrow_count(sc);
        arrow_count(sc) = 0;
    }
    
    sort(score_cases.begin(), score_cases.end(), comp);

    if (arrow_score(score_cases[0]) > 0)
        answer = arrow_info(score_cases[0]);
    else
        answer = {-1};
    return answer;
}