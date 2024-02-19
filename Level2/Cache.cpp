#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if (!cacheSize)
        return 5 * cities.size();
    
    deque<string> cache_db(cacheSize, "");
    deque<string>::iterator cache_it;
    for (string city : cities){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        if ((cache_it = find(cache_db.begin(), cache_db.end(), city)) != cache_db.end()){
            answer++;
            cache_db.erase(cache_it);
            cache_db.push_front(city);
        }
        else {
            answer += 5;
            cache_db.push_front(city);
            if (cache_db.size() > cacheSize)
                cache_db.pop_back();
        }
    }
    return answer;
}