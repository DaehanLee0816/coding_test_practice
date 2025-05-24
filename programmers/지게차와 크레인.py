def solution(storage, requests):
    answer = 0
    storage = [list(s) for s in storage]
    h = len(storage)
    w = len(storage[0])

    answer = w*h
    open_map = [[1 for _ in range(w+2)] for _ in range(h+2)] # 1:open, 0:closed
    for i,row in enumerate(open_map):
        if i == 0 or i == len(open_map) - 1:
            continue
        else:
            row[1:w+1] = [0]*w

    def check_open(storage, open_map, i, j, req):
        if storage[i][j] == req:
            if open_map[i+1][j] == 1:
                return True
            elif open_map[i+1][j+2] == 1:
                return True
            elif open_map[i][j+1] == 1:
                return True
            elif open_map[i+2][j+1] == 1:
                return True
        return False
    
    candidate = []
    for req in requests:
        temp_map = [row[:] for row in open_map]

        if len(req) == 1:
            for i in range(h):
                for j in range(w):
                    if check_open(storage, open_map, i, j, req):
                        storage[i][j] = 'o'
                        temp_map[i+1][j+1] = 1
                        answer -= 1
        else:
            for i in range(h):
                for j in range(w):
                    if storage[i][j] == req[0]:
                        candidate.append((i,j))
                        storage[i][j] = 'c'
                        answer -= 1
                        # if check_open(storage, open_map, i, j, req[0]):
                        #     temp_map[i+1][j+1] = 1
        while True:
            cand_update = []
            find = False
            for cand in candidate:
                i,j = cand
                if temp_map[i+1][j] == 1 or temp_map[i+1][j+2] == 1 or temp_map[i][j+1] == 1 or temp_map[i+2][j+1] == 1:
                    temp_map[i+1][j+1] = 1
                    storage[i][j] = 'a'
                    find = True
                    continue
                else:
                    cand_update.append(cand)

            candidate = cand_update

            if not find:
                break
            if len(cand_update) == 0:
                break
        
        open_map = temp_map
    for s in storage:
        print(s)
    # for s in open_map:
    #     print(s)
    return answer