#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a) {
        int d = n/a;
        answer += b*d;
        n = n - d*a + b*d;
    }
    return answer;
}