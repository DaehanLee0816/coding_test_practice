#include <iostream>
#include <cstring>


int main() {
    char in_char[1000001];
    int cnt = 0;
    std::cin.getline(in_char, 1000001);

    int len = std::strlen(in_char);

    for(int i=0; i<len; i++) {
        if (*(in_char+i)==' ') {
            cnt++;
        }
    }


    if (*in_char==' ') {
        cnt--;
    }
        
    if ((*(in_char+len-1))==' ') {
        cnt--;
    }
    
    cnt++;

    std::cout << cnt << std::endl;

    return 0;
}