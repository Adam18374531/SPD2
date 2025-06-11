#include "brute_force.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // dla std::numeric_limits

BruteForce::BruteForce(problem& p) : prob(p) {
    lzadan = p.getLiczbaZadan();

    if (lzadan > 12) {
        std::cout << "Przeglad zupelny dla wiecej niz 12 zadan jest nieobliczalny. Pomijam." << std::endl;
        return;
    }

    lmaszyn = p.getLiczbaOperacji();
    Cmax = std::numeric_limits<int>::max();

    std::vector<int> IDzadan(lzadan);
    for (int i = 0; i < lzadan; ++i) {
        IDzadan[i] = i;
    }

    int tempCmax;
    do {
        tempCmax = countCmax(IDzadan);
        if (tempCmax < Cmax) {
            Cmax = tempCmax;
            najlepszaKolejnosc = IDzadan;
        }
    } while (std::next_permutation(IDzadan.begin(), IDzadan.end()));
}

int BruteForce::countCmax(std::vector<int> kolejnoscZadan) {
    size_t n = kolejnoscZadan.size();
    size_t m = prob.getLiczbaOperacji();

    std::vector<std::vector<int>> C(n, std::vector<int>(m, 0));

    // 1. zadanie
    C[0][0] = prob.getDane()[kolejnoscZadan[0]][0];

    // 1. maszyna
    for (size_t j = 1; j < m; ++j) {
        C[0][j] = C[0][j - 1] + prob.getDane()[kolejnoscZadan[0]][j];
    }

    // pozostałe zadania i maszyny
    for (size_t i = 1; i < n; ++i) {
        int zad = kolejnoscZadan[i];
        C[i][0] = C[i - 1][0] + prob.getDane()[zad][0];
        for (size_t j = 1; j < m; ++j) {
            C[i][j] = std::max(C[i - 1][j], C[i][j - 1]) + prob.getDane()[zad][j];
        }
    }

    return C[n - 1][m - 1];
}
