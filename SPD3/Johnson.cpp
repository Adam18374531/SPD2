//
// Created by adam9 on 21.05.2025.
//

#include "Johnson.h"

Johnson::Johnson(problem& p) : prob(p) {
    if(prob.getLiczbaMaszyn() != 2){
        std::cout<<"Algorytm Johnsona działa optymalnie dla dwóch maszyn. Inne konfiguracje nie zostały uwzględnione." << std::endl;
        return;
    }
    
    najlepszaKolejnosc.resize(prob.getLiczbaOperacji(), 0);

    std::vector<struct operacja> wszystkieOperacje;
    for(int zad=0; zad < prob.getLiczbaZadan(); zad++){
        for(int m=0; m < prob.getLiczbaMaszyn(); m++){
            wszystkieOperacje.push_back( {prob.getDane().at(zad).at(m), zad, m} );
        }
    }
    // Sort vector in ascending order
    sort_pj(wszystkieOperacje);

    int lewy_ix = 0;
    int prawy_ix = prob.getLiczbaZadan()-1;
    std::vector<int> zrobioneZadania;

    for(auto operacja : wszystkieOperacje){

        if( !jestZrobione(operacja.IDzadania, zrobioneZadania) ){
            zrobioneZadania.push_back(operacja.IDzadania);

            operacja.IDmaszyny==0 ? najlepszaKolejnosc[lewy_ix++] = operacja.IDzadania : najlepszaKolejnosc[prawy_ix--] = operacja.IDzadania;
        }
    }

    Cmax = countCmax(najlepszaKolejnosc);
}

int Johnson::countCmax(std::vector<int> kolejnoscZadan) {

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