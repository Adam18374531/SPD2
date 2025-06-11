//
// Created by adam9 on 21.05.2025.
//

#ifndef SPD3_JOHNSON_H
#define SPD3_JOHNSON_H

#include "problem.h"
#include <limits>
#include <algorithm>

struct operacja{
    int czas_wykonania;
    int IDzadania;
    int IDmaszyny;
};

class Johnson {
    int Cmax;
    problem &prob;
    std::vector<int> najlepszaKolejnosc;

    int countCmax(std::vector<int>);

    void sort_pj(std::vector<struct operacja>& wszystkieOperacje) {
        std::sort(wszystkieOperacje.begin(), wszystkieOperacje.end(), [](const struct operacja& a, const struct operacja& b) {
            return a.czas_wykonania < b.czas_wykonania;
        });
    };

    void sort_pj(std::vector<int>& wszystkieOperacje) {
        std::sort(wszystkieOperacje.begin(), wszystkieOperacje.end(), [](const int& a, const int& b) {
            return a < b;
        });
    };

    bool jestZrobione(int zad, std::vector<int> zrobione){
        for(int i = 0; i< zrobione.size(); i++)
            if(zad == zrobione.at(i)) return true;

        return false;
    };

public:
    Johnson(problem&);
    int getCmax() const { return Cmax; };
    std::vector<int> getNajlepszaKolejnosc() const { return najlepszaKolejnosc; };
};


#endif //SPD3_JOHNSON_H