#ifndef SPD3_NEH_H
#define SPD3_NEH_H

#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <iostream> 
#include "problem.h"

class przegladZupelny{
private:
    problem &prob;
    int lmaszyn;
    int lzadan;
    int Cmax;
    std::vector<int> najlepszaKolejnosc;
    std::vector<int> IDzadan;

    int countCmax(std::vector<int>);
    
public:
    przegladZupelny(problem& p);
    int getCmax() const { return Cmax; };
    std::vector<int> getNajlepszaKolejnosc() const { return najlepszaKolejnosc; };
};

#endif