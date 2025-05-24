#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string solution(vector<int> numbers, string hand) {

    bool use_right;
    int l_x = 0;
    int l_y = 3;

    int r_x = 2;
    int r_y = 3;
    
    int x,y;

    string answer = "";

    use_right = hand.compare("right")==0 ? true : false;

    for (size_t i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num == 1 || num == 4 || num == 7) {
            l_x = 0;
            l_y = num/3;
            answer.push_back('L');
        }
        else if (num == 3 || num == 6 || num == 9) {
            r_x = 2;
            r_y = num/3 - 1;
            answer.push_back('R');
        }
        else if (num == 2 || num == 5 || num == 8 || num == 0) {
            int dist_left;
            int dist_right;
            if (num == 0) {
                num = 11;
            }
            dist_left = abs(l_y - num/3) + abs(l_x - 1);
            dist_right = abs(r_y - num/3) + abs(r_x - 1);
            if (dist_left < dist_right) {
                l_x = 1;
                l_y = num/3;
                answer.push_back('L');
            } else if (dist_left > dist_right) {
                r_x = 1;
                r_y = num/3;
                answer.push_back('R');
            } else {
                if (use_right) {
                    r_x = 1;
                    r_y = num/3;
                    answer.push_back('R');
                } else {
                    l_x = 1;
                    l_y = num/3;
                    answer.push_back('L');
                }
            }
        }
    }
    return answer;
}