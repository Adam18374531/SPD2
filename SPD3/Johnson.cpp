//
// Created by adam9 on 21.05.2025.
//

#include "Johnson.h"

Johnson::Johnson(problem& p) : prob(p) {
    if(prob.getLiczbaOperacji() != 2){
        std::cout<<"Algorytm Johnsona działa optymalnie dla dwóch maszyn. Inne konfiguracje nie zostały uwzględnione." << std::endl;
        return;
    }
    std::vector<struct operacja> wszystkieOperacje;
    for(int zad=0; zad < prob.getLiczbaZadan(); zad++){
        for(int m=0; m < prob.getLiczbaOperacji(); m++){
            wszystkieOperacje.push_back( {prob.getDane()[zad][m], zad, m} );
        }
    }
    // Sort vector in ascending order
    sort_pj(wszystkieOperacje);

    std::vector<int> od_poczatku;
    std::vector<int> od_konca;

    std::vector<int> zrobioneZadania;

    for(auto operacja : wszystkieOperacje){
        if( !jestZrobione(operacja.IDzadania, zrobioneZadania) ){
            zrobioneZadania.push_back(operacja.IDzadania);

            std::cout << operacja.IDzadania<< ": " <<operacja.IDmaszyny<<": "<< operacja.czas_wykonania<<std::endl;

            operacja.IDmaszyny==0 ? od_poczatku.push_back(operacja.IDzadania) : od_konca.push_back(operacja.IDzadania);
        }
    }

    sort_pj(od_poczatku);
    sort_pj(od_konca);

    najlepszaKolejnosc.insert(std::end(najlepszaKolejnosc), std::begin(od_poczatku), std::end(od_poczatku));
    najlepszaKolejnosc.insert(std::end(najlepszaKolejnosc), std::begin(od_konca), std::end(od_konca));

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