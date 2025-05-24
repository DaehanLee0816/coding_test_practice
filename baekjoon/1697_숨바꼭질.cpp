#include <iostream>
#include <vector>

using namespace std;

void make_next_step(int* v, int K) {
   for(int i=0; i <=2*K; i++) {
       if (v[i] == 0) {
           continue;
       }
       int val = v[i];
       
       if (v[i+1] == 0 && i < 2*K) {
           v[i+1] = val+1;
       } else if (v[i+1] > val+1) {
           v[i+1] = val+1;
       }
       
       if (v[i-1] == 0 && i != 0 ) {
           v[i-1] = val+1;
       } else if (v[i-1] > val+1) {
           v[i-1] = val+1;
       }
       
       if (v[i*2] == 0 && i <= K && i != 0) {
           v[i*2] = val+1;
       } else if (v[i*2] > val+1) {
           v[i*2] = val+1;
       }
   }
    
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    if (N >= K) {
        cout << N-K;
        return 0;
    }
    int v[2*K+1] = { 0 };

    v[N] = 1;
    while(v[K] == 0) {
        make_next_step(v, K);
    }
    
    cout << v[K];
    return 0;
}