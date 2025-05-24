#include <iostream>
#include <vector>

int main()
{
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> coin_vec;
    int money_sum = 0;
    int ret = 0;
    int share_of_division;
    int R_of_devision;
    
    for (int i=0; i < N; i++) {
        int i_th_coin;
        std::cin >> i_th_coin;
        if (i_th_coin <= K) {
            coin_vec.push_back(i_th_coin);   
        }
    }
    
    while (money_sum != K) {
        int biggest_coin = coin_vec.back();
        share_of_division = (K-money_sum)/biggest_coin;
        R_of_devision = (K-money_sum)&biggest_coin;
        
        ret += share_of_division;
        money_sum += share_of_division*biggest_coin;
        coin_vec.pop_back();
    }
    
    std::cout << ret;
    return 0;
    
}