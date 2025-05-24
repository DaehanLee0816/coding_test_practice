#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int day_sum = 0;
    string answer = "";
    vector<string> day = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> day_num_month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for (int i = 0; i < a-1; i++) {
        day_sum += day_num_month[i];
    }
    day_sum += b;
    
    int which_day = (day_sum-1)%7;
    answer = day[which_day];
    return answer;
}