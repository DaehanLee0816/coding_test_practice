def solution(info, n, m):
    answer = 0
    queue = set()
    for i in info:
        temp = set()
        if len(queue) == 0:
            if i[0] < n:
                queue.add((i[0], 0))
            if i[1] < m:
                queue.add((0, i[1]))
            
            if len(queue) == 0:
                return -1
            continue
        for x in queue:
            sum_n = (x[0] + i[0], x[1])
            if sum_n[0] < n and sum_n not in temp:
                temp.add(sum_n)

            sum_m = (x[0], x[1] + i[1])
            if sum_m[1] < m and sum_m not in temp:
                temp.add(sum_m)
        queue = temp
        if len(queue) == 0:
            return -1
    answer = 121
    for cand in queue:
        answer = min(answer, cand[0])
    return answer