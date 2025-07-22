def solution(name, yearning, photo):
    answer = []
    scores = {n:y for n,y in zip(name,yearning)}
    for i_th_photo in photo:
        photo_score = 0
        for p in i_th_photo:
            photo_score += scores.get(p,0)
        answer.append(photo_score)
    return answer