def solution(diffs, times, limit):
    answer = 0
    find_ans = False
    lvl = 1

    # lvl==1일때 계산
    total_time = 0
    failed_dict = {}
    total_failed_time_for_each_lvl = 0
    for i, diff in enumerate(diffs):
        if diff <= lvl:
            total_time += times[i]
        else:
            if diff not in failed_dict:
                failed_dict[diff] = times[i] + times[i-1]
            else:
                failed_dict[diff] += times[i] + times[i-1]
            total_failed_time_for_each_lvl += times[i] + times[i-1]
            total_time += (diff - lvl)*(times[i] + times[i-1]) + times[i]
    if total_time <= limit:
        find_ans = True
        answer = lvl
    
    
    sorted_keys = sorted(failed_dict.keys())
    
    for key in sorted_keys:
        if total_time - (key - lvl)*total_failed_time_for_each_lvl > limit:
            total_time -= (key - lvl)*total_failed_time_for_each_lvl
            total_failed_time_for_each_lvl -= failed_dict[key]
            lvl = key
        else:
            break

    failed_dict = {k:v for k,v in failed_dict.items() if k > lvl}
    while not find_ans:
        lvl += 1
        for key in failed_dict.keys():
            if key >= lvl:
                total_time -= failed_dict[key]
        
        if lvl in failed_dict:
            del failed_dict[lvl]
        
        if total_time <= limit:
            find_ans = True
            answer = lvl
    
    return answer