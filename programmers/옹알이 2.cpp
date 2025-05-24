#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_made(string &str, string *list) {
    string substr1;
    string substr2;
    size_t pos = 0;
    int prev = -1;
    
    while (pos < str.length()) {
        substr1 = str.substr(pos, 3);
        if (substr1 == list[0] && prev != 0) {
            pos += 3;
            prev = 0;
            continue;
        }
        if (substr1 == list[2] && prev != 2) {
            pos += 3;
            prev = 2;
            continue;
        }
        
        substr2 = str.substr(pos, 2);
        if (substr2 == list[1] && prev != 1) {
            pos += 2;
            prev = 1;
            continue;
        }
        if (substr2 == list[3] && prev != 3) {
            pos += 2;
            prev = 3;
            continue;
        }
        break;
    }
    
    if (pos < str.length())
        return false;
    
    return true;
}

int solution(vector<string> babbling) {
    string list[4] = {"aya", "ye", "woo", "ma"};
    int answer = 0;
    for (size_t i = 0; i < babbling.size(); i++) {
        string str = babbling[i];
        if (is_made(str, list)) {
            cout << str << endl;
            answer++;
        }
    }
    return answer;
}