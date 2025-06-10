#include <iostream>
#include "wczytywanie.h"
#include "NEH.h"
#include "brute_force.hpp"

void testWczytywanie(problem &p) {
    std::cout << p.getLiczbaZadan()<<" "<<p.getLiczbaOperacji() << std::endl;

    for (int i = 0; i < p.getLiczbaZadan(); i++) {
        for (int j = 0; j < p.getLiczbaOperacji(); j++) {
            std::cout<< j<<" "<< p.getDane()[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}

int main() {

    problem prob;
    if (!wczytywanie("test1.txt", prob)) return 1;

    NEH neh(prob);
    przegladZupelny PrzegZup(prob);
    std::vector<int> NEHwynik = neh.Alg_NEH();
    std::vector<int> PrzegZupwynik = PrzegZup.getNajlepszaKolejnosc();

    std::cout << "Przegląd zupełny:\nKolejność zadań: ";
    for (int z : PrzegZupwynik) std::cout << z << " ";
    std::cout << "\nCmax: " << PrzegZup.getCmax() << "\n";

    std::cout << "NEH:\nKolejność zadań: ";
    for (int z : NEHwynik) std::cout << z << " ";
    std::cout << "\nCmax: " << neh.countCMax(NEHwynik) << "\n";

    return 0;
}
