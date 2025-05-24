#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct_num = 0;
    int deleted_num = 0;
    const int len = 6;
    
    for (int i = 0; i < len; i++) {
        if (lottos[i] == 0) {
            deleted_num++;
            continue;
        }
        for (int j = 0; j < len; j++) {
            if (lottos[i] == win_nums[j]) {
                correct_num++;
                break;
            }
        }
    }
    
    int best_rank = (len + 1) - (deleted_num + correct_num);
    int worst_rank = (len + 1) - (correct_num);

    if (best_rank == len + 1)
        best_rank--;

    if (worst_rank == len + 1)
        worst_rank--;

    answer.push_back(best_rank);
    answer.push_back(worst_rank);
    return answer;
}