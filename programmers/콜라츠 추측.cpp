#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long n = (long) num;
    
    if (n == 0) {
        answer = 1;
    }
    while (n > 1) {
        if (n%2 == 0) {
            n = n/2;
        } else {
            n = 3*n + 1;
        }
        answer++;
        if (answer >= 500) {
            answer = -1;
            break;
        }
    }
    return answer;
}