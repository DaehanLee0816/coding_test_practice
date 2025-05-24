#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for (int n = 1; n <= s.length()/2; n++) {
        int cmp_cnt = s.length()/n;
        int remainder = s.length()%n;
        int len = 0;
        int cnt = 1;
        for (size_t i = 0; i < cmp_cnt - 1; i++) {
            string substr = s.substr(i*n, n);
            string cmp_substr = s.substr(i*n+n, n);
            if (substr == cmp_substr) {
                cnt++;
            } else {
                len += n;
                if (cnt > 1)
                    len += (int)log10(cnt) + 1;
                cnt = 1;
            }
        }
        if (cnt > 1) {
            len += (int)log10(cnt) + 1;
        }
        len += n;
        len += remainder;
        answer = min(answer, len);
    }
    
    return answer;
}