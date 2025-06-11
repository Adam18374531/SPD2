#include <iostream>
#include "wczytywanie.h"
#include "NEH.h"
#include "brute_force.h"
#include "Johnson.h"
#include <windows.h>

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
    if (!wczytywanie("test/10_2_1-20.txt", prob)) return 1;


    NEH neh(prob);

    LARGE_INTEGER freq, start, stop;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);


    if(prob.getLiczbaZadan()<13){
        BruteForce PrzegZup(prob);
        std::vector<int> PrzegZupwynik = PrzegZup.getNajlepszaKolejnosc();
        std::cout << "Przeglad zupelny:\nKolejnosc zadan: ";
        for (int z : PrzegZupwynik) std::cout << z << " ";
        std::cout << "\nCmax: " << PrzegZup.getCmax() << "\n";
    }
    QueryPerformanceCounter(&stop);

    // Czas w nanosekundach
    double czas_s = (1000.0 * (stop.QuadPart - start.QuadPart)) / freq.QuadPart;



    LARGE_INTEGER freq2, start2, stop2;
    QueryPerformanceFrequency(&freq2);
    QueryPerformanceCounter(&start2);

    std::cout << "Czas wykonania: " << czas_s << " s\n";
    std::vector<int> NEHwynik = neh.Alg_NEH();
    std::cout << "NEH:\nKolejnosc zadan: ";
    for (int z : NEHwynik) std::cout << z << " ";
    std::cout << "\nCmax: " << neh.countCMax(NEHwynik) << "\n";

    QueryPerformanceCounter(&stop2);
    double czas_s2 = (1000.0 * (stop2.QuadPart - start2.QuadPart)) / freq2.QuadPart;
    std::cout << "Czas wykonania: " << czas_s2 << " s\n";

    LARGE_INTEGER freq3, start3, stop3;
    QueryPerformanceFrequency(&freq3);
    QueryPerformanceCounter(&start3);
    Johnson jasiek(prob);
    if(prob.getLiczbaOperacji()==2){
        std::cout << "Johnson:\nKolejnosc zadan: ";
        std::vector<int> johnWynik = jasiek.getNajlepszaKolejnosc();
        if(!johnWynik.empty()) for (int z : johnWynik) std::cout << z << " ";
        std::cout << "\nCmax: " << jasiek.getCmax() << "\n";
    }

    QueryPerformanceCounter(&stop3);

    // Czas w nanosekundach
    double czas_s3 = (1000.0 * (stop3.QuadPart - start3.QuadPart)) / freq3.QuadPart;

    std::cout << "Czas wykonania: " << czas_s3 << " s\n";
    return 0;
}
