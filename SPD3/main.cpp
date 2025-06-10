#include <iostream>
#include "wczytywanie.h"
#include "NEH.h"

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
    std::vector<int> wynik = neh.Alg_NEH();

    std::cout << "Kolejność zadań wg NEH: ";
    for (int z : wynik) std::cout << z << " ";
    std::cout << "\nCmax: " << neh.countCMax(wynik) << "\n";



    return 0;
}
