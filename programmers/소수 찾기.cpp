#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    vector<int> list;
    int answer = 1;
    
    list.push_back(2);
    for (int i = 3; i <= n; i+=2) {
        int divide_cnt = 0;
        for (int j = 0; j < list.size(); j++) {
            if (i%list[j] == 0) {
                divide_cnt++;
                break;
            }
            if (list[j] > sqrt(i) + 1)
                break;
        }
        if (divide_cnt == 0) {
            answer++;
            list.push_back(i);
        }
    }
    return answer;
}