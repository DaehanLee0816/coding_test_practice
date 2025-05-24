#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    
    for (auto it = arr.begin(); it != arr.end();) {
        if (q.size() == 0) {
            q.push(*it);
            it++;
        } else if (q.back() == *it) {
            it++;
        } else {
            q.push(*it);
            it++;
        }
    }
    
    size_t size = q.size();
    
    for (size_t i = 0; i < size; i++) {
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}