#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> ans_list;
    string num_str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    size_t pos = 0;
    while (pos < s.length()) {
        if (s[pos] < '0' || s[pos] > '9') {
            for (int i = 0; i < 10; i++) {
                if (s[pos] == 'z') {
                    ans_list.push_back(0);
                    pos += num_str[0].length();
                } else if (s[pos] == 'o') {
                    ans_list.push_back(1);
                    pos += num_str[1].length();
                } else if (s[pos] == 't') {
                    if (s[pos+1] == 'w') {
                        ans_list.push_back(2);
                        pos += num_str[2].length();
                    } else {
                        ans_list.push_back(3);
                        pos += num_str[3].length();
                    }
                } else if (s[pos] == 'f') {
                    if (s[pos+1] == 'o') {
                        ans_list.push_back(4);
                        pos += num_str[4].length();
                    } else {
                        ans_list.push_back(5);
                        pos += num_str[5].length();
                    }
                } else if (s[pos] == 's') {
                    if (s[pos+1] == 'i') {
                        ans_list.push_back(6);
                        pos += num_str[6].length();
                    } else {
                        ans_list.push_back(7);
                        pos += num_str[7].length();
                    }
                } else if (s[pos] == 'e') {
                    ans_list.push_back(8);
                    pos += num_str[8].length();
                } else if (s[pos] == 'n') {
                    ans_list.push_back(9);
                    pos += num_str[9].length();
                }
            }
        }
        else {
            int num = s[pos] - '0';
            ans_list.push_back(num);
            pos++;
        }
    }
    
    for (size_t i = 0; i < ans_list.size(); i++) {
        answer += ans_list[i] * pow(10, ans_list.size() - i - 1);
    }
    return answer;
}