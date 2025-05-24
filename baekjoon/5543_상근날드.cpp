#include <iostream>

int main() {
    int burger1, burger2, burger3, drink1, drink2;
    int cheap_burger, cheap_drink;

    std::cin >> burger1;
    std::cin >> burger2;
    std::cin >> burger3;
    std::cin >> drink1;
    std::cin >> drink2;

    if (burger1 <= burger2) {
        cheap_burger = burger1;
        if(burger1 <= burger3) {
            cheap_burger = burger1;
        }
        else {
            cheap_burger = burger3;
        
        }
    }

    else {
        cheap_burger = burger2;
        if(burger2 <= burger3) {
            cheap_burger = burger2;
        }

        else{
            cheap_burger = burger3;
        }
    }

    if(drink1 <= drink2) {
        cheap_drink = drink1;
    }
    else{
        cheap_drink = drink2;
    }

    int cheap_set;
    cheap_set = cheap_burger + cheap_drink - 50;

    std::cout << cheap_set << std::endl;

    return 0;
}