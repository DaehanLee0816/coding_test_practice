#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum_each_digit = 0;
    int temp = x;
    if (temp == 1) {
        return answer;
    }
    while (temp > 1) {
        sum_each_digit += temp%10;
        temp = temp/10;
        if (temp == 1) {
            sum_each_digit++;
            break;
        }
    }
    
    answer = (x%sum_each_digit == 0) ? true : false;
    
    return answer;
}