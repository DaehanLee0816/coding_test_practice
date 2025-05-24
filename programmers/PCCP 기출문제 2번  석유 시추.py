def solution(land):
    answer = 0
    n = len(land)
    m = len(land[0])
    
    visited = [[False for _ in range(m+2)] for _ in range(n+2)]
    oils = [[0 for _ in range(m+2)] for _ in range(n+2)]
    groups = [[0 for _ in range(m+2)] for _ in range(n+2)]
    group_idx = 1
    for i in land:
        i.insert(0, 0)
        i.append(0)
    
    land.insert(0, [0]*(m+2))
    land.append([0]*(m+2))
    
    for i in range(n+2):
        for j in range(m+2):
            if visited[i][j]:
                continue
            
            if land[i][j] == 0:
                visited[i][j] = True
                continue
            else:
                oil_list = [(i,j)]
                find_list = [(i,j)]
                visited[i][j] = True
                groups[i][j] = group_idx
                while len(find_list) != 0:
                    search = find_list[0]
                    x,y = search
                    if visited[x-1][y] == False and land[x-1][y] == 1:
                        oil_list.append((x-1,y))
                        find_list.append((x-1,y))
                        groups[x-1][y] = group_idx
                    visited[x-1][y] = True
                    if visited[x+1][y] == False and land[x+1][y] == 1:
                        oil_list.append((x+1,y))
                        find_list.append((x+1,y))
                        groups[x+1][y] = group_idx
                    visited[x+1][y] = True
                    if visited[x][y-1] == False and land[x][y-1] == 1:
                        oil_list.append((x,y-1))
                        find_list.append((x,y-1))
                        groups[x][y-1] = group_idx
                    visited[x][y-1] = True
                    if visited[x][y+1] == False and land[x][y+1] == 1:
                        oil_list.append((x,y+1))
                        find_list.append((x,y+1))
                        groups[x][y+1] = group_idx
                    visited[x][y+1] = True
                    
                    find_list.remove(search)
                    
                for pos in oil_list:
                    oils[pos[0]][pos[1]] = len(oil_list)
                
                group_idx += 1

    for w in range(1,m+1):
        oil_sum = 0
        visited_group = []
        for h in range(1,n+1):
            if land[h][w] > 0 and groups[h][w] not in visited_group:
                oil_sum += oils[h][w]
                visited_group.append(groups[h][w])
        answer = max(oil_sum, answer)

    return answer