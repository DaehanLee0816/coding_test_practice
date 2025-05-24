#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> list;
    
    while (n > 1) {
        list.push_back(n%10);
        n = n/10;
    }
    
    if (n == 1) {
        list.push_back(1);
    }
    
    sort(list.begin(), list.end());
    
    for (size_t i = 0; i < list.size(); i++) {
        answer += pow(10, i) * list[i];
    }
    return answer;
}