import math
def solution(r1, r2):
    answer = 0
    l = [x for x in range(1,r2)]
    for x in l:
        max_d = int(math.sqrt(r2**2 - x**2))
        if x < r1:
            min_d = math.ceil(math.sqrt(r1**2 - x**2))
        else:
            min_d = 1
        # print(x, min_d, max_d)
        answer += 4*(max_d - min_d + 1)
    answer += 4*(r2-r1+1)
    return answer