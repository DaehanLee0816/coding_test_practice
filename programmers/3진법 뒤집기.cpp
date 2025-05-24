#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    bool is_big = false;
    int trit_digit = 0;
    vector<int> n_trit;
    
    int answer = 0;
    cout << n << endl;
    
    while (!is_big) {
        if (n >= pow(3, trit_digit) && n < pow(3, trit_digit+1)) {
            is_big = true;
        } else {
            trit_digit++;
        }
    }
    
    for (int i = trit_digit; i >= 0; i--) {
        if (n >= pow(3, i) && n < pow(3,i) * 2) {
            n_trit.push_back(1);
            n -= pow(3, i);
        } else if (n >= pow(3, i) * 2) {
            n_trit.push_back(2);
            n -= pow(3, i) * 2;
        } else {
            n_trit.push_back(0);
        }
    }
    
    for (int i = n_trit.size()-1; i >= 0; i--) {
        answer += (n_trit[i] * pow(3, i));
    }

    return answer;
}