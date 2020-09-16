#include <iostream>

/**
 * 최소공배수 (GCD)
 * GCD(N, M) = GCD(M, N % M)
 */
int getGCD(int i1, int i2) {
    int N, M, MOD;
    N = i1;
    M = i2;

    while(M != 0){
        MOD = N % M;
        N = M;
        M = MOD;
    }

    return N;
}

/**
 * 최대공약수 (LCM)
 * LCM(N, M) = (N * M) / GCM(N, M)
 */
int getLCM(int i1, int i2){
    return (i1 * i2) / getGCD(i1, i2);
}

int main(int argc, char* argv[]){
    int i1, i2, testcase;
    std::cin >> testcase;

    for (int i = 0; i < testcase; i++){
        std::cin >> i1 >> i2;
        std::cout << getLCM(i1, i2) << std::endl;
    }

    return 0;
}