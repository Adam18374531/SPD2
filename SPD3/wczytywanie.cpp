//
// Created by adam9 on 08.06.2025.
//

#include "wczytywanie.h"
bool wczytywanie(const std::string &nazwaPliku, problem &prob)
{

    std::ifstream plik(nazwaPliku);


    if(!plik) {
        std::cout << "Nieprawidlowy plik" << std::endl;
        std::cout << "Aktualny katalog: " << system("cd") << std::endl;
        return 0;
    }
    int lZadan;
    int lOperacji;
    plik >> lZadan>>lOperacji;

    prob.setLiczbaZadan(lZadan);
    prob.setLiczbaOperacji(lOperacji);
    prob.initDane();
    int pj;
    for (int i = 0; i < lZadan; ++i) {
        for (int j = 0; j < lOperacji; ++j) {

            int id, czas;
            plik >> id >> czas;
//            std::cout<<"AAAA "<<std::endl;
            prob.setdane(i,j,czas);
//            std::cout<<"prob.getDane()[i][j]"<<" ";
        }

    }

    plik.close();
    return 1;

}