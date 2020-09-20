#include <iostream>

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

int main(int argc, char* argv[]){
    int N;
    std::cin >> N;
    bool* primeArray = getPrimeArray(1000);

    int array[N];
    for(int i = 0; i < N; i++){
        std::cin >> array[i];
    }

    int count = 0;
    for(int i = 0; i < N; i++){
        if(!primeArray[array[i]]) count++;
    }
    std::cout << count << std::endl;

    return 0;
}