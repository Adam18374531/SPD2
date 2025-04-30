//
// Created by adam9 on 23.04.2025.
//

#ifndef SPD2_ROZWIAZANIE_H
#define SPD2_ROZWIAZANIE_H
#include <iostream>
#include <vector>


class zadanie{
private:
    int Pj;
public:
    zadanie(int Pj);
    int getPj();

    bool operator==(const zadanie &z) const {
        return (Pj == z.Pj);
    }




};




class maszyna{
private:
    std::vector<zadanie> zadaniaWMaszynie;
    int ID; //od 0
public:
    maszyna(int ID);
    int getID();
    std::vector<zadanie> getZadaniaWMaszynie();
    const bool isEmpty() { return zadaniaWMaszynie.empty(); };
    void dodajZadanie(zadanie zad);
    void usunZadanie(int ID);




};



class problem{
    std::vector<maszyna> maszyny;
    std::vector<zadanie> zadaniaWProblemie;
    int liczbaZadan;
    int liczbaMaszyn;
public:

    const std::vector<zadanie> getProblem() { return zadaniaWProblemie; };
    const int getLiczbaZadan(){ return zadaniaWProblemie.size(); };
    const bool isEmpty(){ return zadaniaWProblemie.empty() or maszyny.empty(); };//czy vector niepusty

    void addMaszyna(maszyna m) { maszyny.push_back(m); };
    const int getIDMaszyny(maszyna j){return j.getID();};

    maszyna getMaszyna(int ID){return maszyny.at(ID);};
    std::vector<maszyna> getMaszyny(){return maszyny;};
    int getLiczbaMaszyn(){return liczbaMaszyn;};
    const std::vector<zadanie> getzadaniaWProblemie() const {return zadaniaWProblemie;};
    void setPoczatkowaLiczbaZadan(int lZadan){liczbaZadan = lZadan;};
    const int getPoczatkowaLiczbaZadan(){ return liczbaZadan; };



};

class rozwiazanie{
private:
    std::vector<maszyna> masz;
    std::vector<std::vector<int>> rozw;
    int kryterium;
public:

    int getKryterium(){return kryterium;};
    void setKryterium(int kryt){kryterium = kryt;};
    int countCzasWykonania(std::vector<maszyna> m);  //porownuje maszyny mozna to rozdzielic na 2 funkcje
    void addToKryterium(int czas){kryterium += czas;}
    void addIxZadania(int IDMaszyny, int IDZadania) { rozw.push_back({IDMaszyny, IDZadania}); };

    void algorytmLSA();
    void algorytmLPT();

};







#endif //SPD2_ROZWIAZANIE_H
