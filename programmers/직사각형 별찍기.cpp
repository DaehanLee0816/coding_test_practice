#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a;
    int b;
    string stars = "";
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        stars += "*";
    }
    
    for (int i = 0; i < b; i++) {
        cout << stars << endl;
    }
    return 0;
}