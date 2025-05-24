#include <iostream>

int main() {
    int N;
    std::cin >> N ;

    for (int i=1; i<= 2*N-1; i++) {
        if(i <= N) {
            for (int j=1; j<=i; j++){
                std::cout << '*';
            }
            std::cout << std::endl;
        }
        else {
            for (int j=1; j<= 2*N-i; j++) {
                std::cout <<'*';
            }
            std::cout << std::endl;
        }
    }
    return 0;
}