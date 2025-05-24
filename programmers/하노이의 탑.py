pillas = [1,2,3]

def get_solution(n, start, end):
    if n == 1:
        return [[start, end]]
    
    half_left_start = start
    half_left_end   = [x for x in pillas if x != start and x != end][0]
    
    move_n_block = [[start, end]]
    
    half_right_start = half_left_end
    half_right_end   = end
    
    return get_solution(n-1, half_left_start, half_left_end) + move_n_block + get_solution(n-1, half_right_start, half_right_end)
    

def solution(n):
    
    answer = get_solution(n, 1, 3)
    return answer