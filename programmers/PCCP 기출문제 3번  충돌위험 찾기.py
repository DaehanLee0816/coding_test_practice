def get_path(start, end, prev_path):
    s_x = start[0]
    s_y = start[1]
    e_x = end[0]
    e_y = end[1]
    while True:
        if s_x < e_x:
            s_x += 1
            prev_path.append((s_x, s_y))
        elif s_x > e_x:
            s_x -= 1
            prev_path.append((s_x,s_y))
        else:
            break
    
    while True:
        if s_y < e_y:
            s_y += 1
            prev_path.append((s_x, s_y))
        elif s_y > e_y:
            s_y -= 1
            prev_path.append((s_x,s_y))
        else:
            break
    
def solution(points, routes):
    answer = 0
    all_path = []
    max_length = 0
    for route in routes:
        path = []
        path.append(tuple(points[route[0] - 1]))
        for i in range(len(route)-1):
            get_path(points[route[i] - 1], points[route[i+1] - 1], path)
        max_length = max(len(path), max_length)
        all_path.append(path)
    
    for path in all_path:
        if len(path) < max_length:
            path += [(0,0) for _ in range(max_length - len(path))]
    
    for i in range(max_length):
        exists_path = set()
        crashed_path = set()
        for path in all_path:
            if path[i] != (0,0):
                if path[i] in exists_path:
                    if path[i] not in crashed_path:
                        crashed_path.add(path[i])
                        answer += 1
                else:
                    exists_path.add(path[i])
    return answer