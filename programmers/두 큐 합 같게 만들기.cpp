#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    long long sum1 = 0, sum2 = 0;
    int max1 = 0, max2 = 0, max;
    int pos1 = 0, pos2 = 0;
    bool find = false;
    
    size_t len = queue1.size();
    vector<int> arr1;
    vector<int> arr2;
    
    arr1.reserve(2*len);
    arr2.reserve(2*len);
    
    for (int i = 0; i < len; i++) {
        int num1 = queue1[i];
        int num2 = queue2[i];
        arr1[i] = num1;
        arr2[len + i] = num1;
        arr2[i] = num2;
        arr1[len + i] = num2;
        sum1 += num1;
        sum2 += num2;
        max1 = num1 > max1 ? num1 : max1;
        max2 = num2 > max2 ? num2 : max2;
    }

    
    max = max1 > max2 ? max1 : max2;

    if ((sum1 + sum2)%2 == 1)
        return answer;

    if (2*max > (sum1 + sum2))
        return answer;
    
    answer = 0;
    while (pos1 < 2*len || pos2 < 2*len ) {
        if (sum1 > sum2) {
            sum2 += arr1[pos1];
            sum1 -= arr1[pos1];
            pos1++;
            answer++;
        } else if (sum1 < sum2) {
            sum1 += arr2[pos2];
            sum2 -= arr2[pos2];
            pos2++;
            answer++;
        } else {
            find = true;
            break;
        }
    }
    
    if (!find)
        return -1;
    
    return answer;
}