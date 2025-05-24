#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    vector<int> list;
    int min;
    int GCD, LCM;
    
    min = (n > m) ? m : n;
    for (int i = 1; i <= min; i++) {
        if (n%i == 0 && m%i == 0)
            GCD = i;
    }
    
    LCM = GCD * (n/GCD) * (m/GCD);
    answer.push_back(GCD);
    answer.push_back(LCM);
    return answer;
}