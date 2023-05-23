//
// Created by jakub on 5/20/2023.
//

#include "Kruskal.h"

using namespace std;

    Kruskal::Kruskal() {
        graf = Graf('n');
        size = graf.rozmiar;
        zkruskaluj(5);
    }

    void Kruskal::zkruskaluj(int start) {
        int wynik = 0;
        init_zbiory();
        init_kolejkaL();
        //init_kolejkaM();
        int roz = kolejka.rozmiar;
        for(int krawedz = 0;krawedz<roz;krawedz++){
            if(znajdzDowodce(kolejka.table[0].id)!= znajdzDowodce(kolejka.table[0].next)){
                przypiszDowodce(kolejka.table[0].id,kolejka.table[0].next);
                wynik+=kolejka.table[0].val;
            }
            kolejka.usunKorzen();
        }
        cout<<wynik<<endl;
    }

    void Kruskal::init_zbiory(){
        poprzednicy = new int [size];
        stopien = new int [size];
        for(int i=0;i<size;i++){
            poprzednicy[i] = -1;
            stopien[i] = 0;
        }
    }

    int Kruskal::znajdzDowodce(int liczba){
        if(poprzednicy[liczba]==-1) return liczba;
        return znajdzDowodce(poprzednicy[liczba]);
    }

    void Kruskal::przypiszDowodce(int u, int v){
        int uno = znajdzDowodce(u);
        int vos = znajdzDowodce(v);
        if(uno==vos) return;
        else if(stopien[uno]<stopien[vos]) poprzednicy[uno] = vos;
        else if(stopien[vos]>stopien[uno]) poprzednicy[vos] = uno;
        else{
            poprzednicy[vos] = uno;
            stopien[uno] +=1;
        }
    }

    void Kruskal::init_kolejkaL(){
        kolejka = kopiec();
        listaElement *temp, *temp2;
        for(int i=0;i<graf.rozmiar;i++){
            temp = graf.list[i].head;
            temp2 = graf.listp[i].head;
            while(temp!=NULL){
                kolejka.dodaj(temp2->data,i,temp->data);
                temp = temp->nextEl;
                temp2 = temp2->nextEl;
            }
        }
    }

    void Kruskal::init_kolejkaM(){
        kolejka = kopiec();
        for(int i=0;i<graf.rozmiar;i++){
            for(int j=0;j<graf.rozmiar;j++){
                if(graf.grafMacierz[i][j]!=-1){
                    kolejka.dodaj(graf.grafMacierz[i][j],i,j);
                }
            }
        }
    }
