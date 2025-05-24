#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(string a, string b) {
    string a_car_num = a.substr(6, 4);
    string b_car_num = b.substr(6, 4);
    if (a_car_num < b_car_num) {
        return true;
    } else if (a_car_num == b_car_num) {
        string a_time = a.substr(0, 5);
        string b_time = b.substr(0, 5);
        if (a_time <= b_time) {
            return true;
        }
        return false;
    }
    return false;
}

int change_time_str_to_int(string a, string b) {
    int num_ten = (int)(b[0] - '0') - (int)(a[0] - '0');
    int num = (int)(b[1] - '0') - (int)(a[1] - '0');
    return (10*num_ten + num);
    
}

int calc_time(string a, string b) {
    string a_hour = a.substr(0, 2);
    string a_minute = a.substr(3, 2);
    string b_hour = b.substr(0, 2);
    string b_minute = b.substr(3, 2);
    
    int hour = change_time_str_to_int(a_hour, b_hour);
    int minute = change_time_str_to_int(a_minute, b_minute);
    
    if (minute >= 0) {
        return 60*(hour) + minute;
    } else {
        return 60*(hour-1) + (60 + minute);
    }
}

int calc_fee(vector<int> &fees, int time) {
    if (time <= fees[0]) {
        return fees[1];
    } else {
        int remaining_time = time - fees[0];
        if (remaining_time%fees[2] == 0) {
            return fees[1] + (remaining_time/fees[2])*fees[3];
        } else {
            return fees[1] + (remaining_time/fees[2] + 1)*fees[3];
        }
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    sort(records.begin(), records.end(), comp);
    
    for (size_t i = 0; i < records.size();) {
        int pos = 0;
        while(records[i].substr(6,4) == records[i+pos].substr(6,4)) {
            pos++;
            if (i + pos == records.size()) {
                break;
            }
        }
        int fee = 0;
        int time = 0;
        for (size_t j = 0; j < pos;) {
            if (j+1 < pos) {
                time += calc_time(records[i+j], records[i+j+1]);
                j = j+2;
            } else {
                string latest = "23:59";
                time += calc_time(records[i+j], latest);
                j++;
            }
        }
        cout << time << endl;
        fee += calc_fee(fees, time);
        
        answer.push_back(fee);
        i += pos;
    }
    return answer;
}