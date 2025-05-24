#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int i;
    
    for (i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            break;    
        }
    }
    
    string answer = "김서방은 ";
    
    answer += to_string(i);
    answer += "에 있다";
    return answer;
}