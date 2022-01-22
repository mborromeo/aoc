#include "Y2015D02.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void Y2015D02::run() {
    const std::vector<Box> &boxes = loadBoxes();

    // part 1
    unsigned int required_wrapping_paper = 0;
    unsigned int i;
    for(i = 0; i < boxes.size(); i++) {
        std::vector<unsigned int> areas {
                (boxes[i].length * boxes[i].width),
                (boxes[i].width * boxes[i].height),
                (boxes[i].height * boxes[i].length)
        };
        std::sort(areas.begin(), areas.end());

        unsigned int boxArea = (2 * areas[0]) +
                               (2 * areas[1]) +
                               (2 * areas[2]);

        required_wrapping_paper += (boxArea + areas[0]);
    }

    std::cout << "Required wrapping paper: " << required_wrapping_paper << std::endl;

    // part 2
    unsigned int required_ribbon = 0;
    for(i = 0; i < boxes.size(); i++) {
        std::vector<unsigned int> dimensions {boxes[i].length, boxes[i].width, boxes[i].height};
        std::sort(dimensions.begin(), dimensions.end());

        unsigned int box_ribbon = ((dimensions[0]*2)+(dimensions[1]*2));
        unsigned int bow_ribbon = (dimensions[0] * dimensions[1] * dimensions[2]);

        required_ribbon += (box_ribbon + bow_ribbon);
    }

    std::cout << "Required ribbon: " << required_ribbon << std::endl;
}

Y2015D02::Box Y2015D02::parseBoxSizes(std::string box_sizes) {
    Box box = Box();
    unsigned long pos;

    std::string height = std::move(box_sizes);
    pos = height.find('x');
    box.length = std::stoi(height.substr(0, pos));
    height.erase(0, pos + 1);

    pos = height.find('x');
    box.width = std::stoi(height.substr(0, pos));
    height.erase(0, pos + 1);

    box.height = std::stoi(height);

    return box;
}

std::vector<Y2015D02::Box> Y2015D02::loadBoxes() {
    unsigned int i;
    std::vector<Box> boxes;
    std::string box_sizes;

    for(i = 0; i < Y2015D02::input_txt_len; i++) {
        if (char(Y2015D02::input_txt[i]) != '\n') {
            box_sizes += char(Y2015D02::input_txt[i]);

            // last line
            if (i == (Y2015D02::input_txt_len-1)) {
                boxes.push_back(parseBoxSizes(box_sizes));
            }
        } else {
            boxes.push_back(parseBoxSizes(box_sizes));
            box_sizes = "";
        }
    }

    return boxes;
}
