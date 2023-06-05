//
// Created by jakub on 5/3/2023.
//

#ifndef SDIZOPROJEKT2_PRIMA_H
#define SDIZOPROJEKT2_PRIMA_H
#include <iostream>
#include "../Tablica/tablica.h"
#include "../Kopiec/kopiec.h"
#include "../Lista/lista.h"
#include "../Graf.h"
#include "../node.h"
#include "../Slist/nList.h"

namespace std {

    class Prima {
    public:


        Graf graf;
        void zprimujMacierz(int start);
        int *drogi;
        bool *odwiedzoned;
        int *poprzednicy;
        void wyswietl();
        kopiec kolejka;
        nList list;
        Prima(int choice, int st,string nazwa);

        void zprimujListe(int start);

        void zprimujMacierzI(int start);
    };

} // std

#endif //SDIZOPROJEKT2_PRIMA_H
