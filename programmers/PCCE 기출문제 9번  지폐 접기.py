def solution(wallet, bill):
    answer = 0
    maxW = max(wallet)
    minW = min(wallet)
    maxB = max(bill)
    minB = min(bill)
    while (maxB > maxW or minB > minW):
        answer += 1
        maxB = maxB // 2
        if maxB > minB:
            continue
        else:
            tempMinB = maxB
            maxB = minB
            minB = tempMinB
    return answer