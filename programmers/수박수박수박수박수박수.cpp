#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    if (n == 1) {
        answer += "수";
    } else {
        for (int i = 1; i <= n/2; i++) {
            answer += "수박";
        }
    }
    
    if (n%2 == 1 && n > 1) {
        answer += "수";
    }
    return answer;
}