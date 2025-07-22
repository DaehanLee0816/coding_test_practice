def solution(friends, gifts):
    answer = 0
    friends_idx = {f:i for i,f in enumerate(friends)}
    gift_map = [[0 for _ in range(len(friends))] for _ in range(len(friends))]
    for gift in gifts:
        splitter = gift.split(' ')
        sender = splitter[0]
        reciever = splitter[1]
        gift_map[friends_idx.get(sender)][friends_idx.get(reciever)] += 1
        gift_map[friends_idx.get(reciever)][friends_idx.get(sender)] -= 1
    score_list = [sum(g) for g in gift_map]
    for s_idx,g in enumerate(gift_map):
        score = 0
        for r_idx, send_num in enumerate(g):
            if send_num > 0:
                score += 1
            elif send_num == 0:
                if score_list[s_idx] > score_list[r_idx]:
                    score += 1
            else:
                 continue
        answer = max(answer, score)
    return answer