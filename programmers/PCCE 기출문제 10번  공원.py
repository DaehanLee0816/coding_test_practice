def solution(mats, park):
    mats = sorted(mats, reverse=True)
    park_height = len(park)
    park_width  = len(park[0])
    
    def check_mat(x_offset, y_offset, mat_size):
        for x in range(x_offset, x_offset + mat_size):
            for y in range(y_offset, y_offset + mat_size):
                if park[y][x] != "-1":
                    return False
        return True

    for mat in mats:
        for offsetY in range(park_height - mat + 1):
            for offsetX in range(park_width - mat + 1):
                if check_mat(offsetX, offsetY, mat):
                    return mat
    
    return -1