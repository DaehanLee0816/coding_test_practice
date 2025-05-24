#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            idx = 0;
            continue;
        }
        
        if (idx%2 == 0) {
            if (s[i] > 'Z') {
                answer += s[i] - ('a'-'A');
            } else {
                answer += s[i];
            }
        } else {
            if (s[i] > 'Z') {
                answer += s[i];
            } else {
                answer += s[i] + ('a' - 'A');
            }
        }
        idx++;
    }
    return answer;
}