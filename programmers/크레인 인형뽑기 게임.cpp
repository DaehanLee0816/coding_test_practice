#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> list;
    int answer = 0;
    
    list.push_back(101);
    
    for (size_t i = 0; i < moves.size(); i++) {
        int i_th_move = moves[i];
        for (size_t j = 0; j < board.size(); j++) {
            if (board[j][i_th_move-1] != 0) {
                if (list.back() == board[j][i_th_move-1]) {
                    answer += 2;
                    list.pop_back();
                } else {
                    list.push_back(board[j][i_th_move-1]);
                }
                board[j][i_th_move-1] = 0;
                break;
            }
        }
    }
    return answer;
}