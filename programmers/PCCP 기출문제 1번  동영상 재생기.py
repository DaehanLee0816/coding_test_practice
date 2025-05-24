def time_compare(t1, t2):
    t1_m = int(t1[:2])
    t1_s = int(t1[3:])
    
    t2_m = int(t2[:2])
    t2_s = int(t2[3:])
    if t1_m > t2_m or (t1_m >= t2_m and t1_s >= t2_s):
        return True
    return False

def is_in_opening(op_s, op_e, t):
    if time_compare(t, op_s) and time_compare(op_e, t):
        return True
    return False

def go_prev(t):
    t_m = int(t[:2])
    t_s = int(t[3:])
    if t_s < 10:
        s = 60 - (10 - t_s)
        m = t_m - 1
        if t_m == 0:
            s = 0
            m = 0
    else:
        s = t_s - 10
        m = t_m
    
    if m < 10:
        m = '0' + str(m)
    else:
        m = str(m)
    if s < 10:
        s = '0' + str(s)
    else:
        s = str(s)
    
    return m + ":" + s

def go_next(t, end):
    t_m = int(t[:2])
    t_s = int(t[3:])
    if t_s >= 50:
        s = (10 + t_s) - 60
        m = t_m + 1
    else:
        s = t_s + 10
        m = t_m
    
    if m < 10:
        m = '0' + str(m)
    else:
        m = str(m)
    if s < 10:
        s = '0' + str(s)
    else:
        s = str(s)
    
    ans = m + ':' + s
    if time_compare(ans, end):
        return end
    else:
        return ans


def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    answer = pos
    for c in commands:
        if is_in_opening(op_start, op_end, answer):
            answer = op_end
    
        if c == 'prev':
            answer = go_prev(answer)
        else:
            answer = go_next(answer, video_len)

        if is_in_opening(op_start, op_end, answer):
            answer = op_end
    return answer