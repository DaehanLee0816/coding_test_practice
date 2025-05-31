def solution(dice):
    n = len(dice)
    half = n // 2
    from itertools import combinations, product
    from collections import Counter
    
    def get_sum_distribution(dice_list):
        # 주사위 조합의 모든 가능한 합계와 그 빈도를 계산
        return Counter(sum(roll) for roll in product(*dice_list))
    
    best_combination = None
    max_win_count = 0
    calculated = set()
    
    for comb in combinations(range(n), half):
        if comb in calculated:
            continue
            
        # A와 B의 주사위 조합
        a_dice = [dice[i] for i in comb]
        b_dice = [dice[i] for i in range(n) if i not in comb]
        b_comb = tuple(i for i in range(n) if i not in comb)
        
        calculated.add(comb)
        calculated.add(b_comb)
        
        # 각 조합의 합계 분포 계산
        a_sums = get_sum_distribution(a_dice)
        b_sums = get_sum_distribution(b_dice)
        
        # 승률 계산
        win_count = 0
        lose_count = 0
        
        for a_sum, a_count in a_sums.items():
            for b_sum, b_count in b_sums.items():
                if a_sum > b_sum:
                    win_count += a_count * b_count
                elif a_sum < b_sum:
                    lose_count += a_count * b_count
        
        if win_count > max_win_count:
            max_win_count = win_count
            best_combination = comb
        
        if lose_count > max_win_count:
            max_win_count = lose_count
            best_combination = b_comb
    
    return sorted([x + 1 for x in best_combination])