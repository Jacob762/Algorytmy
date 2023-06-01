//
// Created by jakub on 5/20/2023.
//

#include "Kruskal.h"

using namespace std;

    Kruskal::Kruskal(int choice, int st, string nazwa) {
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
        cout<<endl;
        graf = Graf('n',nazwa);
        init_kolejkaL();
        size = graf.rozmiar;
        zkruskaluj(st);
        wyswietl();
        graf = Graf('k',nazwa);
        init_kolejkaM();
        size = graf.rozmiar;
        zkruskaluj(st);
        wyswietl();
    }

    void Kruskal::zkruskaluj(int start) {
        int wynik = 0;
        init_zbiory();
        int roz = kolejka.rozmiar;
        for(int krawedz = 0;krawedz<roz;krawedz++){
            if(znajdzDowodce(kolejka.table[0].id)!= znajdzDowodce(kolejka.table[0].next)){
                przypiszDowodce(kolejka.table[0].id,kolejka.table[0].next);
                wynik+=kolejka.table[0].val;
                list.dodajNaKoniec(new node(kolejka.table[0].id,kolejka.table[0].next, kolejka.table[0].val));
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

void Kruskal::wyswietl() {
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