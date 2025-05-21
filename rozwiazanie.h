//
// Created by adam9 on 23.04.2025.
//
#ifndef SPD2_ROZWIAZANIE_H
#define SPD2_ROZWIAZANIE_H
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


class zadanie{
private:
    int Pj;
public:
    zadanie(int czasP):Pj(czasP){};
    const int getPj()const{return Pj;};

    bool operator==(const zadanie &z) const {
        return (Pj == z.Pj);
    }
};


class maszyna{
private:
    std::vector<zadanie> zadaniaWMaszynie;
    int ID; //od 0
    int sumaCzasuZadan=0;
public:
    int getSumaCzasuZadan(){return sumaCzasuZadan;};
    maszyna(int id):ID(id){};
    int getID();
    std::vector<zadanie> getZadaniaWMaszynie();
    const bool isEmpty() { return zadaniaWMaszynie.empty(); };
    void dodajZadanie(zadanie zad){zadaniaWMaszynie.push_back(zad);
                                    sumaCzasuZadan+=zad.getPj();};
    void usunZadanie(int ID){zadaniaWMaszynie.erase(zadaniaWMaszynie.begin() + ID);};
};


class problem{
    std::vector<maszyna> maszyny;
    std::vector<zadanie> zadaniaWProblemie;
    int liczbaZadan;
    int liczbaMaszyn;

public:
    problem(){};
    problem(std::vector<zadanie> zWP, int lM );
    const int getLiczbaZadan() const { return zadaniaWProblemie.size(); };
    const int getPoczatkowaLiczbaZadan() const { return liczbaZadan; };
    int getLiczbaMaszyn() const {return liczbaMaszyn;};
    const std::vector<zadanie> getzadaniaWProblemie() const {return zadaniaWProblemie;};
    std::vector<maszyna>& getMaszyny() { return maszyny; };
    zadanie getZadanie(int ID){return zadaniaWProblemie.at(ID);};
    maszyna& getMaszyna(int ID) { return maszyny.at(ID); };
    const int getIDMaszyny(maszyna j){return j.getID();};
    int getSumaPj();

    const bool isEmpty(){ return zadaniaWProblemie.empty() or maszyny.empty(); };//czy vector niepusty
    void addZadanie(zadanie zad){zadaniaWProblemie.push_back(zad);};
    void addMaszyna(maszyna m) { maszyny.push_back(m); };
    void setPoczatkowaLiczbaZadan(int lZadan){liczbaZadan = lZadan;};
    void setLiczbaMaszyn(int lMaszyn);

    void sort_pj();
};


class rozwiazanie{
private:
//    std::vector<maszyna> wektor_Maszyn;
    std::vector<std::vector<int>> rozw;
    int kryterium;
    problem P;
public:
    rozwiazanie(problem p):P(p){};
    int getKryterium(){return kryterium;};
    void programowanieDynamiczne_P2_Cmax();
    void setKryterium(int kryt){kryterium = kryt;};
    int countCzasWykonania(std::vector<maszyna> m);  //porownuje maszyny mozna to rozdzielic na 2 funkcje
    void addToKryterium(int czas){kryterium += czas;}
    void addIxZadania(int IDMaszyny, int IDZadania) { rozw.push_back({IDMaszyny, IDZadania}); };
    int getIDWolnejMaszyny();

    void algorytmLSA();
    void algorytmLPT();
};




#endif //SPD2_ROZWIAZANIE_H
