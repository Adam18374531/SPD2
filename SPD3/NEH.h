//
// Created by adam9 on 21.05.2025.
//

#ifndef SPD3_NEH_H
#define SPD3_NEH_H

#include <vector>
#include "problem.h"
/*
 * Rozpoczyna on działanie od pewnego rozwiązania początkowego π_init, które określa kolejność zadań.
 * W wersji dla klasycznego problemu zadania są uszeregowane zgodnie z niemalejącą sumą czasów wykonywania operacji.
 * Następnie zadania z π_init,są kolejno wstawiane do rozwiązania końcowego π^*,
 * na taką pozycję, aby zminimalizować wartość kryterium Cmax(π^*).
 *
 *
  std::vector<int> suma_czasow(liczba_zadan, 0);
  for(int j=0;j<liczba_zadan;j++){
      for(int m=0; m<liczba_maszyn; ++m){
          suma_czasow[j] += p[j][m];
      }
  }

2. Posortuj zadania według suma_czasów[j] malejąco → lista_zadan_desc

 harmonogram.push(lista_zadan_desc[0]);

 int nowy_Cmax = 0;
 for(int i=1;i<liczba_zadan;i++){
       Cmax = INTMAXVALUE;
       std::vector<int> nowy_harmonogram;
       std::vector<string>::iterator k;
       for(k = harmonogram.begin(); k != harmonogram.end(); ++k){

           nowy_harmonogram := wstaw lista_zadan_desc[i] na pozycję k w harmonogramie

           nowy_Cmax = oblicz_Cmax(nowy_harmonogram, p);
           if(nowy_Cmax < Cmax){
               Cmax = nowy_Cmax;
               harmonogram = nowy_harmonogram;
           }
           nowy_harmonogram = harmonogram;
       }
    }

5. Zwróć harmonogram i jego Cmax

 */
class NEH {

    int sumapj;
    int Cmax;
    problem &prob;
    //std::vector<std::vector<int>> p(liczba_zadan, std::vector<int>(liczba_maszyn));
    std::vector<int>harmonogram; //kolejnosc zadan
public:
    NEH(problem &prob);
    int countCMax(std::vector<int> & harmonogram);
    std::vector<int> Alg_NEH();

};


#endif //SPD3_NEH_H
