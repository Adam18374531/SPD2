#include "wczyt.h"


bool wczytywanie(const std::string & nazwaPliku, problem &prob, int LiczbaM)
{

    std::ifstream plik(nazwaPliku);


    if(!plik) {
        std::cout << "Nieprawidlowy plik" << std::endl;
        std::cout << "Aktualny katalog: " << system("cd") << std::endl;
        return 0;
    }
    int lZadan;
    plik >> lZadan;
    prob.setPoczatkowaLiczbaZadan(lZadan);
    prob.setLiczbaMaszyn(LiczbaM);

    int pj;
    for(int i = 0; i<prob.getPoczatkowaLiczbaZadan();i++)
    {
        if(plik >> pj) {
            zadanie zad(pj);
            prob.addZadanie(zad);
        }

    }

    plik.close();
    return 1;

}
