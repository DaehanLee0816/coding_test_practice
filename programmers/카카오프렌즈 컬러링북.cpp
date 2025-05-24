#include <vector>
#include <iostream>

using namespace std;

#define max_len 100
bool visited[max_len][max_len];

void DFS(int m, int n, vector<vector<int>> &picture, int &area, int val) {
    if (m < 0 || n < 0 || m >= picture.size() || n >= picture[0].size())
        return;

    if (visited[m][n])
        return;
    
    if (picture[m][n] == 0)
        return;
    
    if (val != picture[m][n])
        return;
    
    visited[m][n] = true;
    area++;
    DFS(m-1, n, picture, area, val);
    DFS(m+1, n, picture, area, val);
    DFS(m, n-1, picture, area, val);
    DFS(m, n+1, picture, area, val);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    
    for (int i = 0; i < max_len; i++) {
        for (int j = 0; j < max_len; j++) {
            visited[i][j] = false;
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int area = 0;
            if ((visited[i][j] == false) && (picture[i][j] != 0)) {
                answer[0]++;
                DFS(i, j, picture, area, picture[i][j]);
            }
            if (area > answer[1])
                answer[1] = area;
        }
    }

    return answer;
}