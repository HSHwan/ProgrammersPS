#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<int>> applicantInfo;
vector<string> applicant(4);
int score;

void insertInfo(){
    for (int i = 0; i < 16; i++){
        string applyInfo = "";
        for (int j = 0; j < 4; j++){
            if (i & (1 << j)){
                applyInfo += "-";
            }
            else    applyInfo += applicant[j]; 
        }
        applicantInfo[applyInfo].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string strScore;
    
    for (int i = 0; i < info.size(); i++){
        istringstream iss_parse(info[i]);
        iss_parse >> applicant[0] >> applicant[1] >> applicant[2] >> applicant[3];
        iss_parse >> strScore;
        score = stoi(strScore);
        insertInfo();
    }
    
    for (auto infoItr = applicantInfo.begin(); infoItr != applicantInfo.end(); infoItr++){
        sort(infoItr->second.begin(), infoItr->second.end());
    }
    
    for (const string& condition : query){
        string allCondition = "", parseStr;
        istringstream iss_parse(condition);
        for (int i = 0; i < 7; i++){
            iss_parse >> parseStr;
            if (parseStr != "and"){
                allCondition += parseStr;
            }
        }
        iss_parse >> parseStr;
        int passScore = stoi(parseStr);
        int cutline = lower_bound(applicantInfo[allCondition].begin(), applicantInfo[allCondition].end(), passScore) - applicantInfo[allCondition].begin();
        answer.push_back(applicantInfo[allCondition].size() - cutline);
    }
    
    return answer;
}