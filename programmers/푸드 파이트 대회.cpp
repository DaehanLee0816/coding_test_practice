#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int len = 0;
    int left_pos = 0, right_pos = 0;
    
    for (size_t i = 0; i < food.size(); i++) {
        len += (food[i] / 2) * 2;
    }
    
    //for water
    len++;
    
    right_pos = len - 1;
    
    answer.assign(len, '0');
    for (size_t i = 1; i < food.size(); i++) {
        int num_food = food[i] / 2;
        for (size_t j = 0; j < num_food; j++) {
            answer[left_pos]  += i - 0;
            answer[right_pos] += i - 0;
            left_pos++;
            right_pos--;
        }
    }
    return answer;
}