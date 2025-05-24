#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> user_cnt;
    vector<double> fail_percent;
    vector<int> answer;
    
    user_cnt.assign(N+2, 0);
    fail_percent.assign(N+2, 0.0);
    
    for (size_t i = 0; i < stages.size(); i++) {
        user_cnt[stages[i]]++;
    }
    
    int stage_user_sum = stages.size();
    for (size_t i = 1; i < fail_percent.size(); i++) {
        stage_user_sum -= user_cnt[i-1];
        if (stage_user_sum == 0) {
            break;
        }
        fail_percent[i] = (double)user_cnt[i]/(double)stage_user_sum;
    }
    
    for (size_t i = 1; i <= N; i++) {
        if (answer.size() == 0) {
            answer.push_back(i);
            continue;
        }
        if (fail_percent[i] <= fail_percent[answer.back()]) {
            answer.push_back(i);
            continue;
        }
        for (size_t j = 0; j < answer.size(); j++) {
            if (fail_percent[i] > fail_percent[answer[j]]) {
                answer.insert(answer.begin()+j, i);
                break;
            }
        }
    }
    return answer;
}