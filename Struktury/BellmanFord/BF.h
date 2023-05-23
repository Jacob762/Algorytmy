//
// Created by jakub on 5/20/2023.
//

#ifndef SDIZOPROJEKT2_BF_H
#define SDIZOPROJEKT2_BF_H
#include <iostream>
#include "../Kopiec/kopiec.h"
#include "../Graf.h"


namespace std {

    class BF {
    public:
        struct node{
            int id;
            int next;
            int val;
        };
        BF();
        Graf graf;
        //listaNode *listaNode;
        bool zfordujMacierz(int start);
        int *drogi;
        bool *odwiedzoned;
        int *poprzednicy;
        node *kolejka;
        void wyswietl();
        void zaladujListe(string nazwa);
        void poprawMacierz();

        bool zfordujListe(int start);
    };

} // std

#endif //SDIZOPROJEKT2_BF_H
