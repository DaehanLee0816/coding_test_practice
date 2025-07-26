def solution(players, callings):
    rank_dict = {p:i for i,p in enumerate(players)}
    for call in callings:
        idx = rank_dict[call]
        rank_dict[call] = idx - 1
        rank_dict[players[idx - 1]] = idx
        players[idx] = players[idx-1]
        players[idx-1] = call
    return players