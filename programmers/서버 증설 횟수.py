def solution(players, m, k):
    answer = 0
    num_servers = [0]*24
    for t,users in enumerate(players):
        profit_num_server = users // m
        try:
            turned_on = 0
            for timedelta in range(1,k):
                if t - timedelta < 0:
                    break
                turned_on +=  num_servers[t - timedelta]
            num_server = profit_num_server - turned_on
        except:
            num_server = profit_num_server - turned_on
        
        if num_server > 0:
            answer += num_server
            num_servers[t] = num_server
            print(t, profit_num_server, num_server)
        else:
            num_servers[t] = 0
        
    return answer