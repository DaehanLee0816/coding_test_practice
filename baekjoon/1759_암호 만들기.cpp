#include <iostream>
#include <algorithm>

using namespace std;

static char vowel[5] = {'a','e','i','o','u'};

void make_pos_shift(char *cand, int *pos, int N, int C) {
    pos[N-1]++;
    if (pos[N-1] <= C-1) {
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (pos[N-i] >= C-i) {
            continue;
        } else {
            pos[N-i]++;
            for (int j = N-i+1; j < N; j++) {
                pos[j] = pos[j-1]+1;
            }
            break;
        }
    }
}

int count_vowel_num(char *cand, int *pos, int N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            if (vowel[j] == cand[pos[i]]) {
                cnt++;
                continue;
            }
        }
    }
    return cnt;
}

void print(char *cand, int *pos, int N, int C) {
    int num_vowel = count_vowel_num(cand, pos, N);
    if (num_vowel == 0 || N-num_vowel < 2) {
        return;
    }
    for (int i = 0; i < N; i++) {
        cout << cand[pos[i]];
    }
    cout << endl;
}

int main()
{
    int N, C;
    cin >> N >> C;
    
    char candidiate[C];
    int  pos[N];
    for (int i = 0; i < C; i++) {
        char ch;
        cin >> ch;
        candidiate[i] = ch;
    }
    
    sort(candidiate, candidiate+C);
    
    for (int i = 0; i < N; i++) {
        pos[i] = i;
    }
    
    while(pos[0] != C-N) {
        print(candidiate, pos, N, C);
        make_pos_shift(candidiate, pos, N, C);
    }
    
    int last_vowel_num = 0;
    for (int i =0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            if (candidiate[C-N+i] == vowel[j]) {
                last_vowel_num++;
            }
        }
    }
    if (last_vowel_num >=1 && (N-last_vowel_num) >=2) {
        for (int i = 0; i < N; i++) {
            cout << candidiate[C-N+i];
        }
        cout << endl;
    }
    return 0;
}