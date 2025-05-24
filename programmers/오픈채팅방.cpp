#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid_list;
    string action;
    unordered_map<string, string> m;

    for (size_t i = 0; i < record.size(); i++) {
        string uid;
        string name;
        action += record[i][0];

        size_t start = record[i].find(" ");

        if (record[i][0] == 'L') {
            uid = record[i].substr(start + 1);
        } else {
            size_t end = record[i].rfind(" ");
            uid = record[i].substr(start + 1, (end-1) - start);
            name = record[i].substr(end + 1);
            m[uid] = name;
        }
        uid_list.push_back(uid);
    }

    for (size_t i = 0; i < record.size(); i++) {
        if (action[i] == 'C')
            continue;

        string i_th_action = "";
        if (action[i] == 'E') {
            i_th_action += m[uid_list[i]];
            i_th_action += "님이 들어왔습니다.";
        } else {
            i_th_action += m[uid_list[i]];
            i_th_action += "님이 나갔습니다.";
        }
        answer.push_back(i_th_action);
    }
    return answer;
}

