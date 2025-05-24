#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long tot_price = 0;
    for (int i = 1; i <= count; i++) {
        tot_price += i*price;
    }
    
    if ((long long)money>=tot_price)
        return 0;
    
    return tot_price - money;
}