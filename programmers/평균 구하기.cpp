#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        answer += (double)arr[i];
    }
    answer = answer/(double)arr.size();
    return answer;
}