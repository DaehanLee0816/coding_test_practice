#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        bool is_square = (sqrt(i) == (int)sqrt(i)) ? true : false;

        if (is_square) {
            answer -= i;
        } else {
            answer += i;
        }
    }
    return answer;
}