#include <iostream>
#include <cmath>

using namespace std;
void DFS(int N, int R, int C, int &ret);
void CheckQuarter(int N, int R, int C, int &ret) {
    if (R <= pow(2, N-1)-1 && C <= pow(2, N-1)-1) {
        DFS(N-1, R, C, ret);
    }
    else if (R <= pow(2, N-1)-1 && C > pow(2, N-1)-1) {
        ret += pow(2, 2*N-2);
        DFS(N-1, R, C-pow(2,N-1), ret);
    }
    else if (R > pow(2, N-1)-1 && C <= pow(2, N-1)-1) {
        ret += pow(2, 2*N-1);
        DFS(N-1, R-pow(2, N-1), C, ret);
    } else {
        ret += 3*pow(2, 2*N-2);
        DFS(N-1, R-pow(2, N-1), C-pow(2,N-1), ret);
    }
}

void DFS(int N, int R, int C, int &ret) {
    if (N == 0) {
        return;
    }
    CheckQuarter(N, R, C, ret);
}

int main()
{
    int N, R, C;
    cin >> N >> R >> C;
    int ret = 0;
    DFS(N, R, C, ret);
    cout << ret;
    return 0;
}