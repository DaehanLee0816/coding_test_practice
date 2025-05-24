#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
        } else if (s[i] >= 'a') {
            if (s[i] + n > 'z') {
                int temp = n - ('z' - s[i]);
                answer += ('a' + temp-1);
            } else {
                answer += (s[i] + n);
            }
        } else {
            if (s[i] + n > 'Z') {
                int temp = n - ('Z' - s[i]);
                answer += ('A' + temp-1);
            } else {
                answer += (s[i] + n);
            }
        }
    }
    return answer;
}