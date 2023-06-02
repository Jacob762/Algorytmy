//
// Created by jakub on 5/3/2023.
//

#include "Dijkstra.h"

namespace std {

    Dijkstra::Dijkstra(int choice, int st, string nazwa){
        switch (choice) {
            case 0:
                graf = Graf('l',nazwa);
                graf.getLista();
                break;
            case 1:
                graf = Graf('m',nazwa);
                graf.pokaz();
                break;
        }
        graf = Graf('l',nazwa);
        zdijkstrujListe(st);
        cout<<endl;
        graf = Graf('m',nazwa);
        zdijkstrujMacierz(st);
    }

    void Dijkstra::zdijkstrujMacierz(int start){
        drogi = new int [graf.rozmiar];
        odwiedzoned = new bool [graf.rozmiar];
        poprzednicy = new int [graf.rozmiar];
        que = kopiec();
        int current;
        for(int i=0;i<graf.rozmiar;i++){
            if(i!=start){
                drogi[i] = INT_MAX;
                odwiedzoned[i] = false;
                poprzednicy[i] = -1;
            } else{
                drogi[i] = 0;
                odwiedzoned[i] = true;
                poprzednicy[i] = -1;
            }
        }
        que.dodaj(drogi[start],start,0);
        while(que.rozmiar!=0){
            current = que.table[0].id;
            que.usunKorzen();
            odwiedzoned[current] = true;
            for(int i=0;i<graf.rozmiar;i++) {
                if (drogi[i] > drogi[current] + graf.grafMacierz[current][i] && !odwiedzoned[i] && graf.grafMacierz[current][i]!=-1) {
                    poprzednicy[i] = current;
                    drogi[i] = drogi[current] + graf.grafMacierz[current][i];
                }
            }
            for(int i=0;i<graf.rozmiar;i++){
                if(drogi[i]!=INT_MAX&&!odwiedzoned[i]) que.dodaj(drogi[i],i,0);
            }
        }
        wyswietl();
        delete [] drogi;
        delete [] odwiedzoned;
        delete [] poprzednicy;
    }

    void Dijkstra::zdijkstrujListe(int start){
        drogi = new int [graf.rozmiar];
        odwiedzoned = new bool [graf.rozmiar];
        poprzednicy = new int [graf.rozmiar];
        que = kopiec();
        node *temp;
        int current;
        for(int i=0;i<graf.rozmiar;i++){
            if(i!=start){
                drogi[i] = INT_MAX;
                odwiedzoned[i] = false;
                poprzednicy[i] = -1;
            } else{
                drogi[i] = 0;
                odwiedzoned[i] = true;
                poprzednicy[i] = -1;
            }
        }
        que.dodaj(drogi[start],start,0);
        while(que.rozmiar!=0){
            current = que.table[0].id;
            que.usunKorzen();
            odwiedzoned[current] = true;
            temp = graf.nLis[current].head;
            while(temp!=NULL) {
                if (drogi[temp->next] > drogi[current] + temp->val && !odwiedzoned[temp->next]) {
                    poprzednicy[temp->next] = current;
                    drogi[temp->next] = drogi[current] + temp->val;
                }
                temp = temp->nextEl;
            }
            for(int i=0;i<graf.rozmiar;i++){
                if(drogi[i]!=INT_MAX&&!odwiedzoned[i]) que.dodaj(drogi[i],i,0);
            }
        }
        wyswietl();
        delete [] drogi;
        delete [] odwiedzoned;
        delete [] poprzednicy;
    }

    void Dijkstra::wyswietl(){
        int* S = new int [graf.rozmiar];
        int sptr = 0;
        for( int i = 0; i < graf.rozmiar; i++ )
        {
            cout << i << ": ";

            // Ścieżkę przechodzimy od końca ku początkowi,
            // Zapisując na stosie kolejne wierzchołki

            for( int j = i; j > -1; j = poprzednicy [ j ] ) S [ sptr++ ] = j;

            // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu

            while( sptr ) cout << S [ --sptr ] << " ";

            // Na końcu ścieżki wypisujemy jej koszt

            cout << "$" << drogi [ i ] << endl;
        }
    }
} // std