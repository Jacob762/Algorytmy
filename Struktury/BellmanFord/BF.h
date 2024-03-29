//
// Created by jakub on 5/20/2023.
//

#ifndef SDIZOPROJEKT2_BF_H
#define SDIZOPROJEKT2_BF_H
#include <iostream>
#include "../Kopiec/kopiec.h"
#include "../Graf.h"
#include "../Slist/nList.h"
#include "../node.h"

namespace std {

    class BF {
    public:
        BF(int choice, int st,string nazwa);
        Graf graf;
        nList *lista;
        bool zfordujMacierz(int start);
        int *drogi;
        bool *odwiedzoned;
        int *poprzednicy;
        void wyswietl();
        void zaladujListe(string nazwa);
        void poprawMacierz();
        int rozmiarL;
        bool zfordujListe(int start);
        nList* pop;
        void getLista();

        bool zfordujMacierzI(int start);
    };

} // std

#endif //SDIZOPROJEKT2_BF_H
