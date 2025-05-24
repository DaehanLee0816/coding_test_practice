#include <iostream>
#include <array>

int main() {

    int score[5];
    int sum=0;
    int avg;

    std::cin >> score[0];
    std::cin >> score[1];
    std::cin >> score[2];
    std::cin >> score[3];
    std::cin >> score[4];

    int size = sizeof(score)/sizeof(score[0]);

    for (int i=0; i < size; i++) {
        if(score[i] % 5 == 0) {
            if (score[i]<40) {
                score[i] = 40;
            }
            sum = sum + score[i];
        }
        else {
            std::cout << "error" << std::endl;
        }
    }
    avg = sum/size;

    std::cout << avg << std::endl;

    return 0;
}