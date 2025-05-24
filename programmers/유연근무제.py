def solution(schedules, timelogs, startday):
    answer = 0
    
    def get_safe_time(scheduled_time):
        scheduled_min = scheduled_time % 100
        if scheduled_min + 10 > 59:
            safe_time = ((scheduled_time // 100) + 1)*100 + (scheduled_min + 10 - 60)
        else:
            safe_time = scheduled_time + 10
        
        return safe_time
        
    
    for idx, employee in enumerate(schedules):
        day_count = 0
        safe_time = get_safe_time(employee)
        for days_idx, real_time in enumerate(timelogs[idx]):
            if ((startday + days_idx)%7 == 6) or ((startday + days_idx)%7 == 0):
                continue
            elif real_time > safe_time:
                break
            else:
                day_count += 1
        if day_count == 5:
            answer += 1
    return answer