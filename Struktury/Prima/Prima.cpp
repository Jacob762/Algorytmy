//
// Created by jakub on 5/3/2023.
//

#include "Prima.h"

namespace std {

    Prima::Prima(int choice, int st, string nazwa) {
        switch (choice) {
            case 0:
                graf = Graf('n',nazwa);
                graf.getLista();
                break;
            case 1:
                graf = Graf('k',nazwa);
                graf.pokaz();
                break;
        }
        list = nList();
        graf = Graf('n',nazwa);
        cout<<endl;
        zprimujListe(st);
        wyswietl();
        cout<<endl;
        graf = Graf('k',nazwa);
        cout<<endl;
        zprimujMacierz(st);
        wyswietl();
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
                    list.dodajNaKoniec(new node(kolejka.table[0].id,kolejka.table[0].next, kolejka.table[0].val));
                    kolejka.usunKorzen();
                    break;
                } else{
                    kolejka.usunKorzen();
                    if(kolejka.rozmiar==0) break;
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
        node *tmp;
        while(ik<rozmiar-1){
            odwiedzoned[m] = true;
            tmp = graf.nLis[m].head;
                while(tmp!=NULL){
                    if(!odwiedzoned[tmp->next]){
                        kolejka.dodaj(tmp->val,m,tmp->next);
                    }
                    tmp = tmp->nextEl;
                }
            while(true){
                if(!odwiedzoned[kolejka.table[0].next]){
                    wynik+=kolejka.table[0].val;
                    m = kolejka.table[0].next;
                    list.dodajNaKoniec(new node(kolejka.table[0].id,kolejka.table[0].next, kolejka.table[0].val));
                    kolejka.usunKorzen();
                    break;
                } else{
                    kolejka.usunKorzen();
                    if(kolejka.rozmiar==0) break;
                }
            }
            ik++;
        }
        cout<<wynik;
    }

    void Prima::wyswietl() {
        node* temp;
        temp = list.head;
        cout<<endl;
        cout<<"id"<<"  "<<"next"<<"  "<<"val"<<endl;
        while (temp!=NULL){
            cout<<temp->id<<"    "<<temp->next<<"    "<<temp->val<<endl;
            temp = temp->nextEl;
        }
        while(list.head!=NULL) list.usunZPoczatku();
    }
} // std