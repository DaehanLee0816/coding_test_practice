#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_x = 0;
    int max_y = 0;
    for (size_t i = 0; i < sizes.size(); i++) {
        sort(sizes[i].begin(), sizes[i].end());
    }
    
    for (size_t i = 0; i < sizes.size(); i++) {
        max_x = max(max_x, sizes[i][0]);
        max_y = max(max_y, sizes[i][1]);
    }
    
    return max_x*max_y;
}