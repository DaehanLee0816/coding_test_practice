#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str;
    std::string num1;
    std::string num2;

    std::getline(std::cin, str);

    std::reverse(str.begin(), str.end());

    num1 = str.substr(0,3);
    num2 = str.substr(4,3);

    int a, b;

    a = atoi(num1.c_str());
    b = atoi(num2.c_str());

    if (a >= b) {
        std::cout << a << std::endl;
    }

    else {
        std::cout << b << std::endl;
    }

    return 0;
}