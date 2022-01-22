#include "Y2015D01.h"
#include <iostream>

void Y2015D01::run() {
    int current_floor = 0;
    unsigned int position = 0;
    unsigned int i;

    for(i = 0; i < Y2015D01::input_txt_len; i++) {
        char instruction = char(Y2015D01::input_txt[i]);

        switch (instruction) {
            case '(':
                current_floor++;
                break;

            case ')':
                current_floor--;
                break;

            default:
                break;
        }

        if(current_floor == -1 && position == 0) {
            position = i+1;
        }
    }

    std::cout << "Floor: " << current_floor << "\n";
    std::cout << "Position: " << position << "\n";
}