//
// Created by jakub on 5/3/2023.
//

#include "Dijkstra.h"

namespace std {

    Dijkstra::Dijkstra(){
        graf = Graf('l');
        zdijkstruj(0);
    }

    void Dijkstra::zdijkstruj(int start){
        int rozmiarKolejki = graf.Q.rozmiar;
        drogi = new int [graf.rozmiar];
        odwiedzoned = new bool [graf.rozmiar];
        poprzednicy = new int [graf.rozmiar];
        kolejka = new node [graf.Q.rozmiar];
        lista ktoNastepny = lista();
        int current = start;
        int j = 0;
        for(int i=0;i<rozmiarKolejki;i++){
            kolejka[i].val = graf.Q.table[0].val;
            kolejka[i].id = graf.Q.table[0].id;
            kolejka[i].next = graf.Q.table[0].next;
            graf.Q.usunKorzen();
        }
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
        while(j<graf.rozmiar){
            odwiedzoned[current] = true;
            for(int i=0;i<rozmiarKolejki;i++){
                if(kolejka[i].id == current && !odwiedzoned[kolejka[i].next]){
                    ktoNastepny.dodajNaKoniec(new listaElement(kolejka[i].next));
                    if(drogi[kolejka[i].next]>drogi[kolejka[i].id]+kolejka[i].val){
                        poprzednicy[kolejka[i].next] = kolejka[i].id;
                        drogi[kolejka[i].next] = drogi[kolejka[i].id]+kolejka[i].val;
                    }
                }
            }
            j++;
            current = ktoNastepny.head->data;
            ktoNastepny.usunZPoczatku();
        }
        wyswietl();
        delete [] drogi;
        delete [] odwiedzoned;
        delete [] poprzednicy;
        delete [] kolejka;
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