#include <string>
#include <vector>

using namespace std;

int trans_choice_to_score(int choice) {
    if (choice == 1 || choice == 7) {
        return 3;
    }
    else if (choice == 2 || choice == 6) {
        return 2;
    }
    else if (choice == 3 || choice == 5) {
        return 1;
    }
    return 0;
}

void add_score_with_index(vector<int> &arr, int idx, bool is_first, int choice) {
    int score = trans_choice_to_score(choice);
    
    if (is_first && choice < 4) {
        arr[2*idx - 1] += score;
    } else if (is_first && choice > 4) {
        arr[2*idx] += score;
    } else if (!is_first && choice < 4) {
        arr[2*idx] += score;
    } else if (!is_first && choice > 4) {
        arr[2*idx - 1] += score;
    }
}

void check_score (vector<int> &arr, string survey, int choice) {
    if (survey == "RT") {
        add_score_with_index(arr, 1, true, choice);
    } else if (survey == "TR") {
        add_score_with_index(arr, 1, false, choice);
    } else if (survey == "CF") {
        add_score_with_index(arr, 2, true, choice);
    } else if (survey == "FC") {
        add_score_with_index(arr, 2, false, choice);
    } else if (survey == "JM") {
        add_score_with_index(arr, 3, true, choice);
    } else if (survey == "MJ") {
        add_score_with_index(arr, 3, false, choice);
    } else if (survey == "AN") {
        add_score_with_index(arr, 4, true, choice);
    } else if (survey == "NA") {
        add_score_with_index(arr, 4, false, choice);
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    string MBTI = " RTCFJMAN";
    // R - 1, T - 2, C - 3, F - 4, J - 5, M - 6, A - 7, N - 8
    vector<int> score_arr(9);
    
    for (size_t i = 0; i < survey.size(); i++) {
        check_score(score_arr, survey[i], choices[i]);
    }
    
    for (int i = 1; i <= 4; i++) {
        if (score_arr[2*i - 1] >= score_arr[2*i]) {
            answer += MBTI[2*i - 1];
        } else {
            answer += MBTI[2*i];
        }
    }
    return answer;
}