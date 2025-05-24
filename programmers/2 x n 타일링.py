def solution(n):
    answer = 0
    prev_list = [1, 2]
    if n == 1:
        return prev_list[0]
    if n == 2:
        return prev_list[1]
    
    cur = 3

    while (cur <= n):
        temp = (prev_list[0] + prev_list[1])%1000000007
        prev_list[0] = prev_list[1]
        prev_list[1] = temp
        cur += 1
        
    return prev_list[1]