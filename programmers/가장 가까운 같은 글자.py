def solution(s):
    answer = []
    idx = []
    pos = 0
    for i in range (0,26):
        idx.append(-1)
    
    for c in s:
        if (idx[ord(c)-ord('a')] == -1):
            idx[ord(c)-ord('a')] = pos
            answer.append(-1)
        else:
            answer.append(pos - idx[ord(c)-ord('a')])
            idx[ord(c)-ord('a')] = pos
        pos += 1
    return answer