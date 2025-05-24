def solution(n, w, num):
    height = [0 for _ in range(w)]
    answer = 0
    box_num = 1
    move_right = True
    while box_num <= n:
        if move_right:
            height[box_num%w - 1] += 1
        else:
            height[0 - box_num%w] += 1

        if num == box_num:
            if move_right:
                find_idx = box_num%w - 1
                find_height = height[find_idx]
            else:
                find_idx = 0 - box_num%w
                find_height = height[find_idx]
        
        if box_num%w == 0:
            move_right = not move_right
        
        box_num += 1
    
    return height[find_idx] - find_height + 1
        