// NEH.cpp
#include "NEH.h"
#include <algorithm>
#include <numeric>
#include <limits>

NEH::NEH(problem& p) : prob(p) {

}

int NEH::countCMax( std::vector<int>& harmonogram)  {
    std::vector<std::vector<int>> C(harmonogram.size(), std::vector<int>(prob.getLiczbaOperacji(), 0));

    for (int i = 0; i < harmonogram.size(); ++i) {
        int zad = harmonogram[i];
        for (int j = 0; j < prob.getLiczbaOperacji(); ++j) {
            if (i == 0 && j == 0)
                C[i][j] = prob.getDane()[zad][j];
            else if (i == 0)
                C[i][j] = C[i][j - 1] + prob.getDane()[zad][j];
            else if (j == 0)
                C[i][j] = C[i - 1][j] + prob.getDane()[zad][j];
            else
                C[i][j] = std::max(C[i - 1][j], C[i][j - 1]) + prob.getDane()[zad][j];
        }
    }

    return C.back().back();
}

std::vector<int> NEH::Alg_NEH() {
    std::vector<std::pair<int, int>> suma_zadan;
    for (int i = 0; i < prob.getLiczbaZadan(); ++i) {
        int suma = std::accumulate(prob.getDane()[i].begin(), prob.getDane()[i].end(), 0);
        suma_zadan.emplace_back(suma, i);
    }

    std::sort(suma_zadan.rbegin(), suma_zadan.rend());

    std::vector<int> kolejnosc;

    for (int i = 0; i < prob.getLiczbaZadan(); ++i) {
        int zadanie = suma_zadan[i].second;
        int najlepszy_Cmax = std::numeric_limits<int>::max();
        std::vector<int> najlepsza_kolejnosc;

        for (int pos = 0; pos <= kolejnosc.size(); ++pos) {
            std::vector<int> tmp = kolejnosc;
            tmp.insert(tmp.begin() + pos, zadanie);

            int cmax = countCMax(tmp);
            if (cmax < najlepszy_Cmax) {
                najlepszy_Cmax = cmax;
                najlepsza_kolejnosc = tmp;
            }
        }

        kolejnosc = najlepsza_kolejnosc;
    }

    return kolejnosc;
}
