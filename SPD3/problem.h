//
// Created by adam9 on 08.06.2025.
//

#ifndef SPD3_PROBLEM_H
#define SPD3_PROBLEM_H
#pragma once
#include <vector>
#include <iostream>


class problem {
    std::vector<std::vector<int>> dane;
    int liczba_zadan;
    int liczba_operacji;

public:
    int getLiczbaZadan() const;
    int getLiczbaOperacji() const;

    void setLiczbaZadan(int liczbaZadan) { liczba_zadan = liczbaZadan; };
    void setLiczbaOperacji(int liczbaOperacji) { liczba_operacji = liczbaOperacji; };
    void setdane(int lz, int lo, int czas){ dane[lz][lo] = czas; };

    void initDane() { dane.resize(liczba_zadan, std::vector<int>(liczba_operacji, 0)); };
    const std::vector<std::vector<int>> &getDane() const;
    void wypiszDane();
};


#endif //SPD3_PROBLEM_H
