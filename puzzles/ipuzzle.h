#ifndef AOC_IPUZZLE_H
#define AOC_IPUZZLE_H

#include <map>
#include <string>

class IPuzzle {
public:
    virtual void run() = 0;
};

template<typename T> IPuzzle * createInstance() { return new T; }
typedef std::map<std::string, IPuzzle*(*)()> map_puzzle;

#endif //AOC_IPUZZLE_H
