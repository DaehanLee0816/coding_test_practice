#include <iostream>
#include <array>

int main() {
    int N;
    std::cin >> N;
    char array[N][51];
    char ans[51];

    std::cin.ignore(51, '\n');
    for(int i=0; i<N; i++){
        std::cin.getline(array[i], 51);
    }

    for(int j=0; j<51; j++) {
        ans[j]=array[0][j];
    }

    for(int i=1; i<N; i++) {
        for(int j=0; j<51; j++) {
            if(array[i][j]==ans[j]) {
                ans[j] = array[i][j];
            }

            else {
                ans[j] = '?';
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;    
}