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

int main(int argc, char* argv[]){
    int i1, i2, t, n;
    std::cin >> t;

    for (int i = 0; i < t; i++){
        /**
         * 입력 값인 n의 범위가 (0, 1000000)에 속하므로,
         * 출력 값인 sum의 범위는 (0, 1000000000000)이다.
         * 따라서 int 대신 long long을 사용해야 한다.
         */
        long long sum = 0;
        std::cin >> n;

        int gcds[n];
        for (int j = 0; j < n; j++){
            std::cin >> gcds[j];
        }

        for (int j = 0; j < n - 1; j++){
            for (int k = j + 1; k < n; k++){
                sum += getGCD(gcds[j], gcds[k]);
            }
        }
        std::cout << sum << std::endl;
    }

    return 0;
}