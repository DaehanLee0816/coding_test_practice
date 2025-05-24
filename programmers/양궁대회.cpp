#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_score_diff(vector<int> info, vector<bool> visited) {
    int champ_score = 0;
    int challenger_score = 0;
    
    for (size_t i = 0; i < info.size(); i++) {
        if (visited[i]) {
            champ_score += (10 - i);
        } else if (info[i]) {
            challenger_score += (10 - i);
        }
    }
    return champ_score - challenger_score;
}

bool change_when_same_diff(vector<bool> visited, vector<bool> res) {
    int cur_smallest_visit_idx = 0;
    int result_smallest_visit_idx = 0;
    for (size_t i = 0; i < visited.size(); i++) {
        if (visited[i])
            cur_smallest_visit_idx = i;
    }
    for (size_t i = 0; i < res.size(); i++) {
        if (res[i])
            result_smallest_visit_idx = i;
    }

    if (cur_smallest_visit_idx > result_smallest_visit_idx) {
        return true;
    }
    
    return false;
}

void DFS(vector<int> info, vector<bool> &visited, int idx, int n,
         int &arrow_cnt, int &max_diff, bool contain, vector<bool> &result)
{
    if (idx == 10) {
        if (contain) {
            if (n >= arrow_cnt + info[idx] + 1) {
                visited[idx] = true;
                int score_diff = get_score_diff(info, visited);

                if (score_diff >= max_diff) {
                    max_diff = score_diff;
                    result.assign(visited.begin(), visited.end());
                }
            } else {
                int score_diff = get_score_diff(info, visited);

                if (score_diff > max_diff) {
                    max_diff = score_diff;
                    result.assign(visited.begin(), visited.end());
                } else if (score_diff == max_diff) {
                    if (change_when_same_diff(visited, result))
                        result.assign(visited.begin(), visited.end());
                }
            }
            arrow_cnt += (info[idx] + 1);
        } else {
            int score_diff = get_score_diff(info, visited);

            if (score_diff > max_diff) {
                max_diff = score_diff;
                result.assign(visited.begin(), visited.end());
            } else if (score_diff == max_diff) {
                if (change_when_same_diff(visited, result))
                    result.assign(visited.begin(), visited.end());
            }
        }
        return;
    }

    if (contain) {
        if (n == arrow_cnt + info[idx] + 1) {
            visited[idx] = true;
        
            int score_diff = get_score_diff(info, visited);

            if (score_diff > max_diff) {
                max_diff = score_diff;
                result.assign(visited.begin(), visited.end());
            } else if (score_diff == max_diff) {
                if (change_when_same_diff(visited, result))
                    result.assign(visited.begin(), visited.end());
            }
            arrow_cnt += (info[idx] + 1);
            return;
        } else if (n < arrow_cnt + info[idx] + 1) {
            int score_diff = get_score_diff(info, visited);

            if (score_diff > max_diff) {
                max_diff = score_diff;
                result.assign(visited.begin(), visited.end());
            } else if (score_diff == max_diff) {
                if (change_when_same_diff(visited, result))
                    result.assign(visited.begin(), visited.end());
            }
            arrow_cnt += (info[idx] + 1);
            return;
        }
        visited[idx] = true;
        arrow_cnt += (info[idx] + 1);
    }
    
    DFS(info, visited, idx+1, n, arrow_cnt, max_diff, true, result);
    arrow_cnt -= (info[idx+1] + 1);
    visited[idx+1] = false;
    DFS(info, visited, idx+1, n, arrow_cnt, max_diff, false, result);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<bool> visited;
    vector<bool> visited_res;
    int arrow_cnt = 0;
    int real_arrow_cnt = 0;
    int max_diff = 0;
    
    visited.assign(info.size(), false);
    
    DFS(info, visited, 0, n, arrow_cnt, max_diff, true, visited_res);
    arrow_cnt -= (info[0] + 1);
    visited[0] = false;
    DFS(info, visited, 0, n, arrow_cnt, max_diff, false, visited_res);
    
    if (max_diff == 0) {
        answer.push_back(-1);
        return answer;
    }
    
    for (size_t i = 0; i < info.size() - 1; i++) {
        if (visited_res[i]) {
            answer.push_back(info[i] + 1);
            real_arrow_cnt += (info[i] + 1);
        } else {
            answer.push_back(0);
        }
    }
    
    if (n-real_arrow_cnt > 0) {
        answer.push_back(n-real_arrow_cnt);
    } else {
        answer.push_back(0);
    }

    return answer;
}