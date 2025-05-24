from itertools import combinations
def solution(n, q, ans):
    answer = 0
    candidate = [i for i in range(1,n+1)]
    for i, keys in enumerate(q):
        if ans[i] == 0:
            for k in keys:
                if k in candidate:
                    candidate.remove(k)
    
    key_cands = list(combinations(candidate, 5))
    for k in key_cands:
        find = True
        for idx, inputs in enumerate(q):
            finds = 0
            for i in inputs:
                if i in k:
                    finds += 1
            if finds == ans[idx]:
                continue
            else:
                find = False
                break
        if find:
            answer += 1
    return answer