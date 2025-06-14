def solution(s):
    answer = ''
    num_list = s.split(' ')
    mi = int(num_list[0])
    ma = int(num_list[0])
    for str_n in num_list:
        mi = min(mi, int(str_n))
        ma = max(ma, int(str_n))
    answer = str(mi) + ' ' + str(ma)
    return answer