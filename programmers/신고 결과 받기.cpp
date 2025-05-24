#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<vector<size_t>> report_list;
    vector<int> id_report_cnt;
    string space_delimiter = " ";
    
    answer.assign(id_list.size(), 0);
    id_report_cnt.assign(id_list.size(), 0);
    for (size_t i = 0; i < id_list.size(); i++) {
        vector<size_t> report_cnt;
        report_cnt.assign(id_list.size(), 0);
        report_list.push_back(report_cnt);
    }

    for (size_t i = 0; i < report.size(); i++) {
        string i_report = report[i];
        string reporter;
        string reported_user;
        
        size_t pos = i_report.find(space_delimiter);
        reporter = i_report.substr(0, pos);
        reported_user = i_report.substr(pos+1);
        
        for (size_t j = 0; j < id_list.size(); j++) {
            if (!reporter.compare(id_list[j])) {
                for (size_t m = 0; m < id_list.size(); m++) {
                    if (!reported_user.compare(id_list[m])) {
                        report_list[j][m]++;
                        break;
                    }
                }
                break;
            }
        }
    }
    
    for (size_t i = 0; i < id_list.size(); i++) {
        for (size_t j = 0; j < id_list.size(); j++) {
            if (report_list[i][j] > 0) {
                id_report_cnt[j]++;
            }
        }
    }
    
    for (size_t i = 0; i < id_list.size(); i++) {
        for (size_t j = 0; j < id_list.size(); j++) {
            if (report_list[i][j] > 0 && id_report_cnt[j] >= k) {
                answer[i]++;
            }
        }
    }
    return answer;
}