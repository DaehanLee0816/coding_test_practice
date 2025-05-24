#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int sum = 0;
    
    for(size_t a = 0; a < number.size(); a++) {
        for (size_t b = a; b < number.size(); b++) {
            for (size_t c = b; c < number.size(); c++) {
                sum = number[a] + number[b] + number[c];
                if (sum == 0 && (a != b) && (b != c))
                    answer++;
                    
            }
        }
    }
    return answer;
}