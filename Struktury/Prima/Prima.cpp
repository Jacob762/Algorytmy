//
// Created by jakub on 5/3/2023.
//

#include "Prima.h"

namespace std {

    Prima::Prima() {
        graf = Graf('n');
        //zprimujMacierz(5);
        zprimujListe(5);
    }

    void Prima::zprimujMacierz(int start) {
        int rozmiar = graf.rozmiar;
        int ik =0;
        kolejka = kopiec();
        odwiedzoned = new bool [rozmiar];
        for(int i=0;i<rozmiar;i++) odwiedzoned[i] = false;
        int wynik = 0;
        int m = start;
        while(ik<rozmiar-1){
            odwiedzoned[m] = true;
            for(int j=0;j<rozmiar;j++){
                if(graf.grafMacierz[m][j]!=-1 && !odwiedzoned[j]){
                    kolejka.dodaj(graf.grafMacierz[m][j],m,j);
                }
            }
            while(true){
                if(!odwiedzoned[kolejka.table[0].next]){
                    wynik+=kolejka.table[0].val;
                    m = kolejka.table[0].next;
                    kolejka.usunKorzen();
                    break;
                } else{
                    kolejka.usunKorzen();
                }
            }
            ik++;
        }
        cout<<wynik<<endl;
    }

    void Prima::zprimujListe(int start){
        int rozmiar = graf.rozmiar;
        kolejka = kopiec();
        odwiedzoned = new bool [rozmiar];
        int ik =0;
        for(int i=0;i<rozmiar;i++) odwiedzoned[i] = false;
        int wynik = 0;
        int m = start;
        listaElement *temp, *temp2;
        while(ik<rozmiar-1){
            odwiedzoned[m] = true;
            temp = graf.list[m].head;
            temp2 = graf.listp[m].head;
                while(temp!=NULL){
                    if(!odwiedzoned[temp->data]){
                        kolejka.dodaj(temp2->data,m,temp->data);
                    }
                    temp = temp->nextEl;
                    temp2 = temp2->nextEl;
                }
            while(true){
                if(!odwiedzoned[kolejka.table[0].next]){
                    wynik+=kolejka.table[0].val;
                    m = kolejka.table[0].next;
                    kolejka.usunKorzen();
                    break;
                } else{
                    kolejka.usunKorzen();
                }
            }
            ik++;
        }
        cout<<wynik;
    }

    void Prima::wyswietl() {

    }
} // std