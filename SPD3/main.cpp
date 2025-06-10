#include <iostream>
#include "wczytywanie.h"
#include "NEH.h"
#include "brute_force.h"
#include "Johnson.h"

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

    BruteForce PrzegZup(prob);

    NEH neh(prob);
    std::vector<int> NEHwynik = neh.Alg_NEH();

    Johnson jasiek(prob);

    if(prob.getLiczbaZadan()<13){
        std::vector<int> PrzegZupwynik = PrzegZup.getNajlepszaKolejnosc();
        std::cout << "Przegląd zupełny:\nKolejność zadań: ";
        for (int z : PrzegZupwynik) std::cout << z << " ";
        std::cout << "\nCmax: " << PrzegZup.getCmax() << "\n";
    }

    std::cout << "NEH:\nKolejność zadań: ";
    for (int z : NEHwynik) std::cout << z << " ";
    std::cout << "\nCmax: " << neh.countCMax(NEHwynik) << "\n";

    if(prob.getLiczbaMaszyn()==2){
        std::cout << "Johnson:\nKolejność zadań: ";
        std::vector<int> johnWynik = jasiek.getNajlepszaKolejnosc();
        for (int z : johnWynik) std::cout << z << " ";
        std::cout << "\nCmax: " << jasiek.getCmax() << "\n";
    }

    return 0;
}
