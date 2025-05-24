#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if (s.size() != 4 && s.size() != 6)
        return false;
    
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it > '9' || *it < '0') {
            return false;
        }
    }
    
    return answer;
}