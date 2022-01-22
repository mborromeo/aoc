#include <vector>
#include <iostream>
#include "Y2015D03.h"

void Y2015D03::run() {
    std::map<int, std::map<int, int>> deliveries_alone{};
    std::map<int, std::map<int, int>> deliveries_with_robot{};

    unsigned int house_delivered_alone = 0;
    unsigned int house_delivered_with_robot = 0;

    std::map<bool, Pos> positions_alone{};
    std::map<bool, Pos> positions_with_robot{};

    deliveries_alone[positions_alone[false].x][positions_alone[false].y] = 1;
    house_delivered_alone++;

    deliveries_with_robot[positions_with_robot[true].x][positions_with_robot[true].y] = 1;
    deliveries_with_robot[positions_with_robot[false].x][positions_with_robot[false].y] = 1;
    house_delivered_with_robot++;

    for(unsigned int i = 0; i < input_txt_len; i++) {
        bool is_robot = (i % 2);

        process_command(deliveries_alone, house_delivered_alone, positions_alone, char(input_txt[i]), false);
        process_command(deliveries_with_robot, house_delivered_with_robot, positions_with_robot, char(input_txt[i]), is_robot);
    }

    std::cout << "Houses with at least one delivery without robot: " << house_delivered_alone << std::endl;
    std::cout << "Houses with at least one delivery with robot: " << house_delivered_with_robot << std::endl;
}

void Y2015D03::process_command(std::map<int, std::map<int, int>> &deliveries, unsigned int &house_delivered,
                              std::map<bool, Pos> &positions, char command, bool is_robot) {
    switch (command) {
        case '^':
            positions[is_robot].y--;
            break;
        case 'v':
            positions[is_robot].y++;
            break;
        case '>':
            positions[is_robot].x++;
            break;
        case '<':
            positions[is_robot].x--;
            break;
        default:
            break;
    }

    deliveries[positions[is_robot].x][positions[is_robot].y]++;
    if (deliveries[positions[is_robot].x][positions[is_robot].y] == 1) {
        house_delivered++;
    }
}
