#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    
    int min = arr[0];
    
    for (size_t i = 1; i < arr.size(); i++) {
        min = min > arr[i] ? arr[i] : min;
    }
    
    for (size_t i = 0; i < arr.size(); i++) {
        if (min == arr[i])
            continue;
        answer.push_back(arr[i]);
    }
    return answer;
}