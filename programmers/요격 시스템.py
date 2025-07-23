def solution(targets):
    answer = 0
    sorted_targets = sorted(targets, key = lambda x: (x[1], [0]))
    end_misile = 0
    for start, end in sorted_targets:
        if end_misile == 0:
            end_misile = end
        if start >= end_misile:
            answer += 1
            end_misile = end
    return answer + 1