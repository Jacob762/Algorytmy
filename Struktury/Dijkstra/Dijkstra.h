//
// Created by jakub on 5/3/2023.
//

#ifndef SDIZOPROJEKT2_DIJKSTRA_H
#define SDIZOPROJEKT2_DIJKSTRA_H
#include <iostream>
#include "../Tablica/tablica.h"
#include "../Kopiec/kopiec.h"
#include "../Lista/lista.h"
#include "../Graf.h"
#include "../Lista/listaElement.h"


namespace std {

    class Dijkstra {
    public:
        struct node{
            int id;
            int next;
            int val;
        };
        Dijkstra();
        Graf graf;
        void zdijkstruj(int start);
        int *drogi;
        bool *odwiedzoned;
        int *poprzednicy;
        node *kolejka;
        void wyswietl();
    };

} // std

#endif //SDIZOPROJEKT2_DIJKSTRA_H
