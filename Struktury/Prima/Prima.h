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

namespace std {

    class Prima {
    public:
        struct node{
            int id;
            int next;
            int val;
        };
        Graf graf;
        void zprimujMacierz(int start);
        int *drogi;
        bool *odwiedzoned;
        int *poprzednicy;
        void wyswietl();
        kopiec kolejka;

        Prima();

        void zprimujListe(int start);
    };

} // std

#endif //SDIZOPROJEKT2_PRIMA_H
