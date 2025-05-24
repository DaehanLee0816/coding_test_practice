def cal_time_diff(cur_time_list, privacy_time):
    privacy_time_list = []
    privacy_str_list = privacy_time.split('.')
    privacy_time_list.append(int(privacy_str_list[0]))
    privacy_time_list.append(int(privacy_str_list[1]))
    privacy_time_list.append(int(privacy_str_list[2]))
    ans = 0

    if cur_time_list[0] > privacy_time_list[0]:
        ans += (cur_time_list[0] - privacy_time_list[0])*12
    
    ans += (cur_time_list[1] - privacy_time_list[1])
    
    if (cur_time_list[2] >= privacy_time_list[2]):
        return ans + 1
    else:
        return ans
    

def check_privacy_is_valid(cur_time, privacy, term_dic):
    privacy_duration = term_dic[privacy.split(' ')[1]]
    time_diff = cal_time_diff(cur_time, privacy.split(' ')[0])

    if (privacy_duration >= time_diff):
        return True
    else:
        return False
    

def solution(today, terms, privacies):
    answer = []
    today_str_list = today.split('.')
    
    today_list = []
    today_list.append(int(today_str_list[0]))
    today_list.append(int(today_str_list[1]))
    today_list.append(int(today_str_list[2]))
    
    term_dic = {}
    for term in terms:
        key = term.split(' ')[0]
        val = int(term.split(' ')[1])
        term_dic[key] = val

    idx = 1
    for privacy in privacies:
        if check_privacy_is_valid(today_list, privacy, term_dic) == False:
            answer.append(idx)
        idx += 1
            
    return answer