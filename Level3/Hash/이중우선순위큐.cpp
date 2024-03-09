#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0, 0};
    int data;
    map<int, bool> double_priority_queue;
    auto data_itr = double_priority_queue.begin();
    for (const string& op : operations){
        if (op[0] == 'I'){
            data = stoi(op.substr(2, op.length() - 2));
            double_priority_queue[data] = true;
        }
        else if (double_priority_queue.empty())  continue;
        if (op == "D 1"){
            data_itr = --double_priority_queue.end();
            double_priority_queue.erase(data_itr);
        }
        else if (op == "D -1"){
            data_itr = double_priority_queue.begin();
            double_priority_queue.erase(data_itr);
        }
    }
    if (!double_priority_queue.empty())
        answer = {(--double_priority_queue.end())->first, double_priority_queue.begin()->first};
    return answer;
}