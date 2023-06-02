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
#include "../node.h"

namespace std {

    class Dijkstra {
    public:
        Dijkstra(int choice, int st, string nazwa);
        Graf graf;
        void zdijkstrujMacierz(int start);
        void zdijkstrujListe(int start);
        int *drogi;
        bool *odwiedzoned;
        int *poprzednicy;
        void wyswietl();
        kopiec que;
    };

} // std

#endif //SDIZOPROJEKT2_DIJKSTRA_H
