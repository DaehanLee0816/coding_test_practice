#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int get_power(int n) {
    int power = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            power++;
    }
    return power;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i = 1; i <= number; i++) {
        int p = get_power(i);
        if (p > limit)
            answer += power;
        else
            answer += p;
    }
    return answer;
}