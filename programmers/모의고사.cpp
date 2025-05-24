#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int point[3] = {};
    vector<int> answer;
    for (size_t i = 0; i < answers.size(); i++) {
        if ((answers[i])%5 == (i+1)%5)
            point[0]++;
        
        if ((answers[i] == 2) && (i%2 == 0))
            point[1]++;
        else if (((i+1)%8) == 2 && answers[i] == 1)
            point[1]++;
        else if (((i+1)%8) == 4 && answers[i] == 3)
            point[1]++;
        else if (((i+1)%8) == 6 && answers[i] == 4)
            point[1]++;
        else if (((i+1)%8) == 0 && answers[i] == 5)
            point[1]++;
        
        if ( ((i+1)%10) > 0 && (i+1)%10 < 3 && answers[i]==3)
            point[2]++;
        else if ( ((i+1)%10) > 2 && (i+1)%10 < 5 && answers[i]==1)
            point[2]++;
        else if ( ((i+1)%10) > 4 && (i+1)%10 < 7 && answers[i]==2)
            point[2]++;
        else if ( ((i+1)%10) > 6 && (i+1)%10 < 9 && answers[i]==4)
            point[2]++;
        else if ( (((i+1)%10) == 9 || (i+1)%10 == 0) && answers[i]==5)
            point[2]++;
    }
    int max = 0;
    for (size_t i = 0; i < 3; i++) {
        max = (max < point[i]) ? point[i] : max;
    }
    for (size_t i = 0; i < 3; i++) {
        if (max == point[i])
            answer.push_back(i+1);
    }
    return answer;
}