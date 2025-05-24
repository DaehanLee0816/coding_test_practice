#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int apple_num[10];
    
    for (size_t i = 0; i < 10; i++) {
        apple_num[i] = 0;
    }
    for (size_t i = 0; i < score.size(); i++) {
        apple_num[score[i]]++;
    }
    
    for (size_t i = 9; i >= 1; i--) {
        int num_box = apple_num[i] / m;
        int remaining = apple_num[i] % m;
        
        answer += i*num_box*m;
        apple_num[i-1] += remaining;
        
    }
    return answer;
}