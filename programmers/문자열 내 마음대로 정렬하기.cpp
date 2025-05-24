#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp (pair<char, string> &a, pair<char, string> &b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return false;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<char, string>> list;
    
    for (size_t i = 0; i < strings.size(); i++) {
        pair<char, string> val(strings[i][n], strings[i]);
        cout << val.first << " " << val.second << endl;
        list.push_back(val);
    }
    
    sort(list.begin(), list.end(), cmp);
    for (size_t i = 0; i < list.size(); i++) {
        answer.push_back(list[i].second);
    }
    
    return answer;
}