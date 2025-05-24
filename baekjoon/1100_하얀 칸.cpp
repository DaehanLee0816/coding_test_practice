#include <iostream>

int main() {
    char chess[8][9];
    int cnt = 0;

    std::cin.getline(chess[0], 9);
    std::cin.getline(chess[1], 9);
    std::cin.getline(chess[2], 9);
    std::cin.getline(chess[3], 9);
    std::cin.getline(chess[4], 9);
    std::cin.getline(chess[5], 9);
    std::cin.getline(chess[6], 9);
    std::cin.getline(chess[7], 9);



    for(int i=0; i<8; i++) {
        for(int j=0; j<4; j++) {
            if(i%2==0 && chess[i][2*j]=='F') {
                cnt++;
            }

            if(i%2==1 && chess[i][2*j +1]=='F') {
                cnt++;
            }
        }


    }

    std::cout << cnt << std::endl;

    return 0;
}