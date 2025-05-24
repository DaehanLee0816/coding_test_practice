#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    
    int sum = 0;
    for (size_t i = 0; i < d.size(); i++) {
        if (budget >= sum + d[i]) {
            sum += d[i];
            answer++;
        } else {
            break;
        } 
    }
    return answer;
}