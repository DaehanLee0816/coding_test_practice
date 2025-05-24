#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    bool num_arr[10] = {};
    int answer = 0;
    
    for (size_t i = 0; i < numbers.size(); i++) {
        num_arr[numbers[i]] = true;
    }
    
    for (size_t i = 0; i < 10; i++) {
        if (!num_arr[i])
            answer += i;
    }
    
    return answer;
}