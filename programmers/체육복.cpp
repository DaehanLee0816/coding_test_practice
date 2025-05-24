#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int no_have_cnt = 0;

    vector<bool> is_lost;
    vector<bool> have_spare;
    
    is_lost.assign(32, false);
    have_spare.assign(32, false);
    
    for (auto it = lost.begin(); it != lost.end(); it++)
        is_lost[*it] = true;
    
    for (auto it = reserve.begin(); it != reserve.end(); it++)
        have_spare[*it] = true;
    
    for (size_t i = 0; i < is_lost.size(); i++) {
        if (is_lost[i] && have_spare[i]) {
            is_lost[i] = false;
            have_spare[i] = false;
        }
    }
    
    for (size_t i = 0; i < is_lost.size(); i++) {
        if (is_lost[i]) {
            if (have_spare[i-1]) {
                is_lost[i] = false;
                have_spare[i-1] = false;
            } else if (have_spare[i+1]) {
                is_lost[i] = false;
                have_spare[i+1] = false;
            }
        }
    }
    
    for (size_t i = 0; i < is_lost.size(); i++) {
        if (is_lost[i])
            no_have_cnt++;
    }
    answer = n - no_have_cnt;
    return answer;
}