#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num_str;
    if (s[0] < '0' || s[0] > '9') {
        num_str = s.substr(1, s.length()-1);
    } else {
        num_str = s.substr(0, s.length());
    }
    int num = stoi(num_str);
    
    if (s[0] == '-') {
        answer = 0 - num;
    } else {
        answer = num;
    }
    return answer;
}