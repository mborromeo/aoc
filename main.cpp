#include <iostream>

#include "puzzles/ipuzzle.h"
#include "puzzles/2015/01/Y2015D01.h"
#include "puzzles/2015/02/Y2015D02.h"

int main(int argc, char* argv[]) {
    map_puzzle puzzles;

    if (argc != 2) {
        std::cout << "Usage: aoc YYYY-DD" << std::endl;
        return 1;
    }

    puzzles["2015-01"] = &createInstance<Y2015D01>;
    puzzles["2015-02"] = &createInstance<Y2015D02>;

    if (puzzles.find(argv[1]) != puzzles.end()) {
        puzzles[argv[1]]()->run();
    } else {
        std::cout << "Unsupported puzzle" << std::endl;
        return 1;
    }

    return 0;
}