#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void push_que(queue<int> &q, vector<int> &vec, vector<bool> &visited) {
    vector<int> next_node;
    while(!q.empty()) {
        int popped = q.front();
        visited[popped-1] = true;
        for (int i = 0; i < vec.size(); i++) {
            if (visited[popped + vec[i]-1] == false) {
                next_node.push_back(popped+vec[i]);
            }
        }
        q.pop();
    }
    
    for (int i = 0; i < next_node.size(); i++)
        q.push(next_node[i]);
    return;
}

int main()
{
    int num_size, trial_cnt;
    cin >> num_size;
    
    vector<int> num_vec;
    queue<int> q;
    
    for (int i = 0; i < num_size; i++) {
        int i_th_num;
        cin >> i_th_num;
        num_vec.push_back(i_th_num);
        q.push(i_th_num);
    }
    
    cin >> trial_cnt;
    int cnt = 1;
    
    vector<bool> visited;
    visited.assign(1000, false);
    
    
    while (cnt <= trial_cnt) {
        push_que(q, num_vec, visited);
        cnt++;
        if (cnt > trial_cnt) {
            break;
        }
    }
    
    for (int i = 0; i < 1000; i++) {
        if (visited[i] == false) {
            if ((i+1)%2 == 1) {
                cout << "jjaksoon win at " << (i+1);
            } else {
                cout << "holsoon win at " << (i+1);
            }
            break;
        }
    }
    
    return 0;
    
}