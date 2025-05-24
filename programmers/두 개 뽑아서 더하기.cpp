#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (size_t i = 0; i < numbers.size() - 1; i++) {
        for (size_t j = i+1; j < numbers.size(); j++) {
            int num = numbers[i] + numbers[j];
            answer.push_back(num);
        }
    }
    
    sort(answer.begin(), answer.end());
    for (auto it = answer.begin(); it != answer.end(); it++) {
        if (it == answer.end()-1) {
            break;
        }
        
        while (*it == *(it+1)) {
            if (it == answer.end() -1) {
                break;
            }
            it = answer.erase(it);
        }
    }
    return answer;
}