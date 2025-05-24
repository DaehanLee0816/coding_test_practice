#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> NumList;
    vector<char> OptionList;
    
    for (size_t i = 0; i < dartResult.length();) {
        int num = 0;
        if (dartResult[i] == '1') {
            if (dartResult[i+1] == '0') {
                num = 10;
                i += 2;
            } else {
                num = 1;
                i++;
            }
        } else {
            num = dartResult[i] - '0';
            i++;
        }
        
        if (dartResult[i] == 'D') {
            num = pow(num, 2);
            i++;
        } else if (dartResult[i] == 'T') {
            num = pow(num, 3);
            i++;
        } else {
            i++;
        }
        
        NumList.push_back(num);
        
        if (dartResult[i] == '*') {
            OptionList.push_back('*');
            i++;
        } else if (dartResult[i] == '#') {
            OptionList.push_back('#');
            i++;
        } else {
            OptionList.push_back('n');
        }
    }
    
    for (size_t i = 0; i < OptionList.size(); i++) {
        if (OptionList[i] == '*') {
            if (i == 0) {
                NumList[i] *= 2;
            } else {
                NumList[i] *= 2;
                NumList[i-1] *= 2;
            }
        }
    }
    
    for (size_t i = 0; i < OptionList.size(); i++) {
        if (OptionList[i] == '#') {
            answer -= NumList[i];
        } else {
            answer += NumList[i];
        }
    }
    return answer;
}