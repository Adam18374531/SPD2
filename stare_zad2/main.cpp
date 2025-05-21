#include <iostream>
#include "rozwiazanie.h"
#include "wczyt.h"
#include <windows.h>

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

    LARGE_INTEGER freq, start, stop;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
//        r.algorytmLSA();
//        r.algorytmLPT();
        r.programowanieDynamiczne_P2_Cmax();
    QueryPerformanceCounter(&stop);

    // Czas w nanosekundach
    double czas_ns = (1e9 * (stop.QuadPart - start.QuadPart)) / freq.QuadPart;

    std::cout << "Czas wykonania: " << czas_ns << " ns\n";





    std::cout<<"Rozwiazanie: "<<r.getKryterium()<<std::endl;


    return 0;
}
