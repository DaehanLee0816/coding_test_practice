def solution(babbling):
    answer = 0
    say_list = ["aya", "ye", "woo", "ma"]
    for b in babbling:
        sentence = b
        while True:
            if len(sentence) == 0:
                answer += 1
                break
            if sentence[:3] in say_list:
                sentence = sentence[3:]
                continue
            if sentence[:2] in say_list:
                sentence = sentence[2:]
                continue
            break
    return answer