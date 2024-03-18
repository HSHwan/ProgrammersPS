#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> airportVisit;
vector<string> answer;

void DFS(const vector<vector<string>>& tickets, const string& nowAirport){
    answer.push_back(nowAirport);
    
    if (answer.size() == tickets.size() + 1)
        return;
    
    for (int i = 0; i < tickets.size(); i++){
        if (!airportVisit[i] && tickets[i][0] == nowAirport){
            string nextAirport = tickets[i][1];
            airportVisit[i] = true;
            DFS(tickets, nextAirport);
            
            if (answer.size() != tickets.size() + 1){
                answer.pop_back();
                airportVisit[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<bool>(tickets.size(), false).swap(airportVisit);
    DFS(tickets, "ICN");
    
    return answer;
}