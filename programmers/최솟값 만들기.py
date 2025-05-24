def solution(A,B):
    answer = 0
    sorted_a = sorted(A)
    sorted_b = sorted(B, reverse=True)
    
    for i, a in enumerate(sorted_a):
        answer += a*sorted_b[i]

    return answer