def solution(sequence, k):
    n = len(sequence)
    answer = []
    left = 0
    right = 0
    total = sequence[0]
    min_len = float('inf')

    while left <= right and right < n:
        if total == k:
            if right - left < min_len:
                answer = [left, right]
                min_len = right - left
            total -= sequence[left]
            left += 1
        elif total < k:
            right += 1
            if right < n:
                total += sequence[right]
        else:
            total -= sequence[left]
            left += 1
    return answer