#include <iostream>
#include <vector>

std::vector<int> getPrimeList(int max){
    int i, j;
    std::vector<int> list;
    for(i = 2; i <= max; i++){
        for(j = 2; j < i; j++){
            if (i % j == 0){
                break;
            }
        }
        if (i == j){
            list.push_back(i);
        }
    }
    return list;
}

int main(int argc, char* argv[]){
    int N;
    std::cin >> N;
    std::vector<int> primeList = getPrimeList(1000);

    int arr[N];
    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    int count = 0;
    for(int i = 0; i < N; i++){
        for (std::vector<int>::iterator it = primeList.begin(); it != primeList.end(); it++){
            if (arr[i] == *it){
                count++;
                break;
            }
        }
    }
    std::cout << count << std::endl;

    return 0;
}