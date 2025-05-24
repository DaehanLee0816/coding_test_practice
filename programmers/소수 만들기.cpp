#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime_number (int num) {
    for (size_t i = 2; i <= sqrt(num) + 1; i++) {
        if (num%i == 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int num = 0;
    for (size_t i = 0; i < nums.size()-2; i++) {
        for (size_t j = i+1; j < nums.size()-1; j++) {
            for (size_t k = j+1; k < nums.size(); k++) {
                num += (nums[i] + nums[j] + nums[k]);
                if (is_prime_number(num))
                    answer++;
                num = 0;
            }
        }
    }

    return answer;
}