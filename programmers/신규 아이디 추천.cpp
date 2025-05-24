#include <string>
#include <vector>

using namespace std;

char UpperToLower(char ch) {
    if ('A' <= ch && ch <= 'Z') {
        return ch - 'A' + 'a';
    } else {
        return ch;
    }
}

string solution(string new_id) {
    string answer = "";
    
    for (int i = 0; i < new_id.size(); i++) {
        char ch = UpperToLower(new_id[i]);
        answer.push_back(ch);
    }
    
    int delete_cnt = 0;
    int len = answer.size();
    for (int i = 0; i < len; i++) {
        char ch = answer[i - delete_cnt];
        if ('a' <= ch && ch <= 'z') {
            continue;
        } else if ('0' <= ch && ch <= '9') {
            continue;
        } else if (ch == '-' || ch == '_' || ch == '.') {
            continue;
        } else {
            answer.erase(i - delete_cnt, 1);
            delete_cnt++;
        }
    }
    delete_cnt = 0;
    int dot_pos = -2;
    len = answer.size();
    for (int i = 0; i < len; i++) {
        char ch = answer[i - delete_cnt];
        if (ch == '.' ) {
            if (dot_pos == i-1) {
                answer.erase(i - delete_cnt, 1);
                delete_cnt++;
            }
            dot_pos = i;
        }
    }
    
    if (answer.front() == '.') {
        answer.erase(0, 1);
    }
    
    if (answer.back() == '.') {
        answer.pop_back();
    }
    
    if (answer.empty()) {
        answer.push_back('a');
    }
    
    if (answer.size() > 15) {
        answer.erase(15, answer.size()-15);
        if (answer.back() == '.') {
            answer.pop_back();
        }
    }
    
    if (answer.size() <= 2) {
        char ch = answer.back();
        while (answer.size() != 3) {
            answer.push_back(ch);
        }
    }
    
    return answer;
}