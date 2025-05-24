#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p_cnt = 0, y_cnt = 0;
    
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it == 'p' || *it == 'P')
            p_cnt++;
        if (*it == 'y' || *it == 'Y')
            y_cnt++;
    }
    answer = (p_cnt == y_cnt) ? true : false;

    return answer;
}