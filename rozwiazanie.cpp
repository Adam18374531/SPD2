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
void problem::setLiczbaMaszyn(int lMaszyn) {
    liczbaMaszyn=lMaszyn;
    for(int i =0; i<lMaszyn;i++)
    {
        maszyna m(i);
        addMaszyna(m);
    }
}

int problem::getSumaPj(){
    int suma = 0;
    for(int i=0; i < getLiczbaZadan(); i++){
        suma += zadaniaWProblemie.at(i).getPj();
    }
    return suma;
}


int rozwiazanie::countCzasWykonania(std::vector<maszyna> m){
//    dla kazdej maszyny policz czas wykonywania i zwroc najwiekszy
    kryterium=0;

    for(int l=0; l<m.size(); l++)
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
    for(int i =0; i<P.getLiczbaMaszyn();i++)
    {
        if(P.getMaszyna(i).getSumaCzasuZadan() == 0)
            return i;
        if(P.getMaszyna(i).getSumaCzasuZadan() < MinCzas) {
            MinCzas = P.getMaszyna(i).getSumaCzasuZadan();
            ID = i;
        }
    }
    return ID;
}


void rozwiazanie::algorytmLPT()
{
    P.sort_pj();

    for (int i = 0; i < P.getLiczbaZadan(); i++)
    {
        int idMaszyny = getIDWolnejMaszyny();
        zadanie zad = P.getZadanie(i);
        P.getMaszyna(idMaszyny).dodajZadanie(zad);
    }

    countCzasWykonania(P.getMaszyny());
}

void rozwiazanie::algorytmLSA()
{
    for (int i = 0; i < P.getLiczbaZadan(); i++)
    {
        int idMaszyny = getIDWolnejMaszyny();
        zadanie zad = P.getZadanie(i);
        P.getMaszyna(idMaszyny).dodajZadanie(zad);
    }

    countCzasWykonania(P.getMaszyny());
}

void rozwiazanie::programowanieDynamiczne_P2_Cmax(){
   int Kl = P.getSumaPj()/2 +1;
   int n = P.getLiczbaZadan();

   bool T[n+1][Kl] = {};

   // kolumna 0 = zadanie 0 o zerowym czasie wykonywania
   for(int i=0; i <= n; i++){
       T[i][0] = 1;
   }

   for(int j=1; j <= n; j++){
       int pj = P.getZadanie(j-1).getPj();
       for(int k=1; k < Kl; k++)
           T[j][k] = (T[j-1][k]==1) || ( k >= pj && T[j-1][k-pj]==1 );
   }

    int maxK = 0;
    for(int k = Kl-1; k >= 0; k--){
        if(T[n][k]){
            maxK = k;
            break;
        }
    }
    kryterium = std::max(maxK, P.getSumaPj() - maxK);
}
