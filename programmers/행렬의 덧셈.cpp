#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int row = arr1.size();
    int col = arr1[0].size();
    for (size_t i = 0; i < row; i++) {
        vector<int> i_th_row;
        for (size_t j = 0; j < col; j++) {
            i_th_row.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(i_th_row);
    }
    return answer;
}