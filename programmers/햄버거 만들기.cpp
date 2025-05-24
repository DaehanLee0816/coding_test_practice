#include <string>
#include <vector>
#include <stack>

using namespace std;

void make_burger(stack<int> &s, int cur, int &ans) {
    if (cur != 1) {
        s.push(cur);
    } else {
        int a[4];
        a[3] = s.top();
        s.pop();
        a[2] = s.top();
        s.pop();
        a[1] = s.top();
        s.pop();
        for (int i = 1; i <= 3; i++) {
            if (a[i] != i) {
                s.push(a[1]);
                s.push(a[2]);
                s.push(a[3]);
                s.push(cur);
                return;
            }
        }
        ans++;
    }
}

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> s;
    
    s.push(0);
    s.push(0);
    s.push(0);
    
    for (size_t i = 0; i < ingredient.size(); i++) {
        if (i == 0) {
            s.push(ingredient[i]);
            continue;
        }
        make_burger(s, ingredient[i], answer);
    }
    return answer;
}