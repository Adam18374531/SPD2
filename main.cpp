#include <iostream>
#include "rozwiazanie.h"
int main() {

    std::vector<zadanie> wekZ={2,2,3};

    problem p(wekZ,2);
    rozwiazanie r(p);
    r.algorytmLPT();

    std::cout<<"Rozwiazanie LPT: "<<r.getKryterium()<<std::endl;

    return 0;
}
