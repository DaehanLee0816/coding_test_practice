def solution(bandage, health, attacks):
    answer = 0
    time_band, health_band, advantage_health = bandage
    lask_attack = 0
    max_health = health
    for attack in attacks:
        attack_time, damage = attack
        time_gap = (attack_time-1) - lask_attack
        bandage_times = time_gap // time_band
        for i in range(bandage_times):
            health += (time_band*health_band + advantage_health)
        health += (time_gap%time_band)*health_band
        if health > max_health:
            health = max_health
        health -= damage
        if health <= 0:
            return -1
        lask_attack = attack_time
    
    return health