#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& vector){
    for(std::vector<int>::iterator it1 = vector.begin(); it1 != vector.end(); it1++){
        for(std::vector<int>::iterator it2 = vector.begin(); it2 != vector.end(); it2++){
            if (*it1 < *it2){
                int tmp = *it1;
                *it1 = *it2;
                *it2 = tmp;
            }
        }
    }
}

int main(int argc, char* argv[]){
    const int REAL_DWARF_SUM = 100;
    const int DWARF_NUMBER = 9;
    std::vector<int> DWARF_VECTOR;
    
    int tmp = 0;
    for(int i = 0; i < DWARF_NUMBER; i++){
        scanf("%d", &tmp);
        DWARF_VECTOR.push_back(tmp);
    }

    int FAKE_DWARF_SUM = 0;
    for(std::vector<int>::iterator it = DWARF_VECTOR.begin(); it != DWARF_VECTOR.end(); it++){
        FAKE_DWARF_SUM += *it;
    }

    bool loop_flag = true;
    for(std::vector<int>::iterator it1 = DWARF_VECTOR.begin(); it1 != DWARF_VECTOR.end() && loop_flag; it1++){
        for(std::vector<int>::iterator it2 = DWARF_VECTOR.begin(); it2 != DWARF_VECTOR.end() && loop_flag; it2++){
            if(it1 == it2){
                continue;
            }

            if(FAKE_DWARF_SUM - (*it1 + *it2) == REAL_DWARF_SUM){
                DWARF_VECTOR.erase(it2);
                DWARF_VECTOR.erase(it1);
                loop_flag = false;
            }
        }
    }
    
    bubble_sort(DWARF_VECTOR);
    for(std::vector<int>::iterator it = DWARF_VECTOR.begin(); it != DWARF_VECTOR.end(); it++){
        std::cout << *it << std::endl;
    }
    return 0;
}