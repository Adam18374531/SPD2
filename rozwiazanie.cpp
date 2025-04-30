#include "rozwiazanie.h"

problem::problem(std::vector<zadanie> zWP, int lM ):zadaniaWProblemie(zWP), liczbaMaszyn(lM){

    for(int i =0;i <liczbaMaszyn;i++)
    {
        maszyna m(i);
        maszyny.push_back(m);
    }
    liczbaZadan = zadaniaWProblemie.size();


};



void problem::sort_pj() {
    std::sort(zadaniaWProblemie.begin(), zadaniaWProblemie.end(), [](const zadanie& a, const zadanie& b) {
        return a.getPj() < b.getPj();
    });
}


int rozwiazanie::countCzasWykonania(std::vector<maszyna> m){
//    dla kazdej maszyny policz czas wykonywania i zwroc najwiekszy
    kryterium=0;

    for(int l=0; l<m.size();l++)
    {
//        policz czas wykonywania
        if(kryterium<m.at(l).getSumaCzasuZadan())
            kryterium = m.at(l).getSumaCzasuZadan();

    }

    return kryterium;
}

int rozwiazanie::getIDWolnejMaszyny() {

    int ID;
    int MinCzas=INT16_MAX;
    for(int i =0; i<P.getMaszyny().size();i++)
    {
        if(P.getMaszyny().at(i).getSumaCzasuZadan() == 0)
            return i;
        if(P.getMaszyny().at(i).getSumaCzasuZadan()<MinCzas) {
            MinCzas = P.getMaszyny().at(i).getSumaCzasuZadan();
            ID = i;
        }
    }
    return ID;
}

void rozwiazanie::algorytmLPT()
{
    P.sort_pj();
    for(int i = 0; i <P.getLiczbaZadan(); i++)
    {
        // znajdź wolną maszyne i prezypisz jej maszynę, ktora ???!
        //P.getMaszyny().at(getIDWolnejMaszyny()) = P.getMaszyna(i%P.getLiczbaMaszyn());


        P.getMaszyny().at(getIDWolnejMaszyny()).dodajZadanie(P.getProblem().at(i));
    }

    countCzasWykonania(P.getMaszyny());

}




/*
void rozwiazanie::algorytmLSA()
{

    for(int i = 0; i <liczbaZadan; i++)
    {
        if(sumaPJ >= czas)
            masz = getMaszyna(i%liczbaMaszyn);
            masz.dodajZadanie(zadanieWProblemie.at(i);
        czas++;
    }

    countKryterium();

}


*/
