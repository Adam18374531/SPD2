//
// Created by adam9 on 08.06.2025.
//

#ifndef SPD3_PROBLEM_H
#define SPD3_PROBLEM_H
#include <vector>
#include <iostream>


class problem {
    std::vector<std::vector<int>> dane;
    int liczba_zadan;
    int liczba_maszyn;
    int liczba_operacji;

public:

    void setLiczbaZadan(int liczbaZadan){liczba_zadan = liczbaZadan;}
    void setLiczbaOperacji(int liczbaOperacji){liczba_operacji = liczbaOperacji;}
    void initDane(){dane.resize(liczba_zadan, std::vector<int>(liczba_operacji, 0));};
    void setLiczbaMaszyn(int liczbaMaszyn){liczba_maszyn= liczbaMaszyn;}

    const std::vector<std::vector<int>> &getDane() const;
    void setdane(int lz, int lo, int czas){dane[lz][lo] = czas;}
    int getLiczbaZadan() const;

    int getLiczbaMaszyn() const;

    int getLiczbaOperacji() const;


    void wypiszDane();



};


#endif //SPD3_PROBLEM_H
