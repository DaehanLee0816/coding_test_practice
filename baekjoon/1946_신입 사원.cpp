#include <iostream>
#include <vector>
using namespace std;

void pass_check(int *i_ranking, int num_vol, vector<int> &ret) {
    int cnt = 1;
    int min = i_ranking[0];
    for (int i = 0; i < num_vol; i++) {
        if (i_ranking[i] < min) {
            cnt++;
            min = i_ranking[i];
        }
    }
    ret.push_back(cnt);
}

int main()
{
    int num_interview;
    cin >> num_interview;

    vector<int> test_pass;
    for (int i = 0; i < num_interview; i++) {
        int num_volunteer;
        cin >> num_volunteer;
        int ranking_interview[num_volunteer];
        for (int j = 0; j < num_volunteer; j++) {
            int paper_ranking, interview_ranking;
            cin >> paper_ranking >> interview_ranking;
            ranking_interview[paper_ranking-1] = interview_ranking;
        }
        pass_check(ranking_interview, num_volunteer, test_pass);
    }
    
    for (int i = 0; i < num_interview; i++) {
        cout << test_pass[i] << endl;
    }
    
    return 0;
}