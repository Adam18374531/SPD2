#include <iostream>
#include "rozwiazanie.h"
#include "wczyt.h"

void testWczytywanie(problem &p){
    std::cout<<p.getLiczbaZadan()<<std::endl;

    for(int i = 0;i<p.getLiczbaZadan();i++ )
    {
        zadanie z = p.getZadanie(i);
        std::cout<<"zad "<<i<<": "<<z.getPj()<<std::endl;

    }
    std::cout<<std::endl;
}


int main() {

//    std::vector<zadanie> wekZ;

    problem p;
    if(wczytywanie("DANE.txt", p,2))
        testWczytywanie(p);
    rozwiazanie r(p);
    r.algorytmLPT();
//    r.algorytmLSA();
    std::cout<<"Rozwiazanie: "<<r.getKryterium()<<std::endl;




    return 0;
}
