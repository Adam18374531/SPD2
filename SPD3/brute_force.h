#ifndef SPD3_BRUTEFORCE_H
#define SPD3_BRUTEFORCE_H

#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <iostream> 
#include "problem.h"

class BruteForce{
private:
    problem &prob;
    int lmaszyn; 
    int lzadan;
    int Cmax;
    std::vector<int> najlepszaKolejnosc;
    std::vector<int> IDzadan;

    int countCmax(std::vector<int>);
    
public:
    BruteForce(problem& p);
    int getCmax() const { return Cmax; };
    std::vector<int> getNajlepszaKolejnosc() const { return najlepszaKolejnosc; };
};

#endif