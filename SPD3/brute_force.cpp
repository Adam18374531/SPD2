#include "brute_force.h"

BruteForce::BruteForce(problem& p) : prob(p) {
    lzadan = p.getLiczbaZadan();
    if(lzadan > 12){
        std::cout<< "Przegląd zupełny dla więcej niż 12 zadań jest nieobliczalny. Pomijam." << std::endl;
        return;
    }
    lmaszyn = p.getLiczbaMaszyn();
    Cmax = __INT_MAX__;
    for(int i=0;i<lzadan;++i){
        IDzadan[i] = i;
    }

    int tempCmax;    
    do{
        tempCmax = countCmax(IDzadan);

        if(tempCmax < Cmax){
            Cmax = tempCmax;
            najlepszaKolejnosc = IDzadan;
        }
    } while (std::next_permutation(IDzadan.begin(), IDzadan.end()));
}

int BruteForce::countCmax(std::vector<int> kolejnoscZadan) {

    std::vector<std::vector<int>> C(kolejnoscZadan.size(), std::vector<int>(prob.getLiczbaOperacji(), 0));

    // 1. zadanie
    C[0][0] = prob.getDane()[kolejnoscZadan[0]][0];

    // 1. maszyna
    for (int j = 1; j < prob.getLiczbaOperacji(); ++j) {
        C[0][j] = C[0][ j-1 ] + prob.getDane()[kolejnoscZadan[0]][j];
    }

    // pozostałe maszyny i zadania
    for (int i = 1; i < kolejnoscZadan.size(); ++i) {
        int zad = kolejnoscZadan[i];
        C[i][0] = C[ i-1 ][0] + prob.getDane()[zad][0];

        for (int j = 1; j < prob.getLiczbaOperacji(); ++j) {
            C[i][j] = std::max(C[ i-1 ][j], C[i][ j-1 ]) + prob.getDane()[zad][j];
        }
    }

    return C.back().back();    
}
