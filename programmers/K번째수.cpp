#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto it = commands.begin(); it != commands.end(); it++) {
        auto i_th_command = *it;
        vector<int> i_th_subarr;
        for (int i = i_th_command[0]; i <= i_th_command[1]; i++) {
            i_th_subarr.push_back(array[i-1]);
        }
        sort(i_th_subarr.begin(), i_th_subarr.end());
        answer.push_back(i_th_subarr[i_th_command[2] - 1]);
    }
    return answer;
}