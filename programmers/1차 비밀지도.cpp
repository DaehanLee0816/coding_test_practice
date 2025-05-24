#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> num_to_map(int n, int num) {
    vector<bool> map;
    for (int i = n-1; i >= 0; i--) {
        if (num >= pow(2, i)) {
            map.push_back(true);
            num -= pow(2, i);
        } else {
            map.push_back(false);
        }
    }
    return map;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++) {
        vector<bool> map1 = num_to_map(n, arr1[i]);
        vector<bool> map2 = num_to_map(n, arr2[i]);
        
        string j_th_row = "";
        
        for (int j = 0; j < n; j++) {
            if (map1[j] || map2[j]) {
                j_th_row += "#";
            } else {
                j_th_row += " ";
            }
        }
        answer.push_back(j_th_row);
    }
    return answer;
}