#include <iostream>

struct Goldbach{
    int a;
    int b;
};

/**
 * [Sieve of Eratóstenes]
 * true: Not prime.
 * false: Prime.
 */
bool* getPrimeArray(int max){
    bool *array = new bool[max + 1];
    array[0] = true;
    array[1] = true;
    
    for(int i = 2; i * i <= max; i++){
        if(array[i] == false){
            for (int j = i * i; j <= max; j += i){
                array[j] = true;
            }
        }
    }
    return array;
}

struct Goldbach* checkGoldbach(bool* primeArray, int testcase){
    struct Goldbach* gb = new Goldbach;
    for(int i = 3; i <= testcase / 2; i++){
        if(primeArray[i] || primeArray[testcase - i]) continue;
        gb->a = i;
        gb->b = testcase - i;
        return gb;
    }
    return nullptr;
}

int main(int argc, char* argv[]){
    struct Goldbach* gb;
    const int max = 1000000;

    bool* primeArray = getPrimeArray(max);

    int n = -1;
    while(true){
        fscanf(stdin, "%d", &n);
        if (n == 0) break;
        gb = checkGoldbach(primeArray, n);
        
        if (gb == nullptr){
            fprintf(stdout, "Goldbach's conjecture is wrong.\n");
        }
        else{
            fprintf(stdout, "%d = %d + %d\n", n, gb->a, gb->b);
            delete(gb);
        }
    }

    return 0;
}