//
// Created by jakub on 5/5/2023.
//

#include "Graf.h"
#include <iostream>
#include <fstream>

using namespace std;

    Graf::Graf() {

    }

    Graf::Graf(char struktura){
        rozmiar = 1;
        switch(struktura){
            case 'm':
                init_macierz();
                break;
            case 'l':
                init_lista();
                break;
            case 'k':
                dodajMacierzPrima("plik.txt");
                break;
            case 'n':
                dodajListaPrim("plik.txt");
                break;
            case 'f':
                dodajMacierzFord("plik.txt");
                break;
        }
    }

    void Graf::init_macierz() {
        dodajMacierz("plik.txt");
        pokaz();
        cout<<endl<<endl;
        for(int i=0;i<rozmiar;i++){
            for(int j=0;j<rozmiar;j++){
                if(grafMacierz[i][j]!=-1){
                    Q.dodaj(grafMacierz[i][j],i,j);
                }
            }
        }
    }

    void Graf::dodajMacierz(string nazwa) {
        int x,y,val;
        fstream file(nazwa,std::ios_base::in);
        if (!file.is_open()) {
            cout<<"ERROR"<<endl;
            return;
        }
        file >> x >> y;
        rozmiar = x;
        grafMacierz = new int*[rozmiar];
        for(int i=0;i<rozmiar;i++){
            grafMacierz[i] = new int [rozmiar];
            for(int j=0;j<rozmiar;j++) grafMacierz[i][j] = -1;
        }
        while(file >> x >> y >> val){
            grafMacierz[x][y] = val;
        }
    }

    void Graf::dodajMacierzFord(string nazwa){
        int x,y,val;
        fstream file(nazwa,std::ios_base::in);
        if (!file.is_open()) {
            cout<<"ERROR"<<endl;
            return;
        }
        file >> x >> y;
        rozmiar = x;
        grafMacierz = new int*[rozmiar];
        for(int i=0;i<rozmiar;i++){
            grafMacierz[i] = new int [rozmiar];
            for(int j=0;j<rozmiar;j++) grafMacierz[i][j] = INT_MAX;
        }
        while(file >> x >> y >> val){
            grafMacierz[x][y] = val;
        }
    }

    void Graf::pokaz() {
        cout<<"   ";
        for(int i=0;i<rozmiar;i++) cout<<i<<"  ";
        cout<<endl;
        for(int i=0;i<rozmiar;i++){
            cout<<i<<"  ";
            for(int j=0;j<rozmiar;j++) cout<<grafMacierz[i][j]<<" ";
            cout<<endl;
        }

    }
    void Graf::init_lista() {
        dodajLista("plik.txt");
        for(int i=0;i<rozmiar;i++){
            cout<<i<<"\t";
            list[i].pokaz();
        }
        cout<<endl<<endl;
        listaElement* temp;
        listaElement* temp2;
        for(int i=0;i<rozmiar;i++){
            temp = list[i].head;
            temp2 = listp[i].head;
            while(temp!=NULL){
                Q.dodaj(temp2->data,i,temp->data);
                temp = temp->nextEl;
                temp2 = temp2->nextEl;
            }
        }
    }

    void Graf::poszerzMacierz(int wielkosc) {
        temp = new int*[wielkosc];
        for(int i=0;i<wielkosc;i++) {
            temp[i] = new int[wielkosc];
            for(int j=0;j<wielkosc;j++) temp[i][j] = -1;
        }
        for(int i=0;i<rozmiar;i++) {
            for(int j=0;j<rozmiar;j++) {
                temp[i][j] = grafMacierz[i][j];
                if(i==j) temp[i][j] = 0;
            }
        }
        rozmiar = wielkosc;
        delete [] grafMacierz;
        grafMacierz = temp;
    }

    void Graf::dodajLista(string nazwa) {
        int x,y,val;
        fstream file(nazwa,std::ios_base::in);
        if (!file.is_open()) {
            cout<<"ERROR"<<endl;
            return;
        }
        file >> x >> y;
        rozmiar = x;
        list = new lista [rozmiar];
        listp = new lista [rozmiar];
        for(int i=0;i<rozmiar;i++) list[i] = lista();
        while(file >> x >> y >> val){
            list[x].dodajNaKoniec(new listaElement(y));
            listp[x].dodajNaKoniec(new listaElement(val));
        }
    }

    void Graf::dodajListaPrim(string nazwa) {
        int x,y,val;
        fstream file(nazwa,std::ios_base::in);
        if (!file.is_open()) {
            cout<<"ERROR"<<endl;
            return;
        }
        file >> x >> y;
        rozmiar = x;
        list = new lista [rozmiar];
        listp = new lista [rozmiar];
        for(int i=0;i<rozmiar;i++) list[i] = lista();
        while(file >> x >> y >> val){
            list[x].dodajNaKoniec(new listaElement(y));
            listp[x].dodajNaKoniec(new listaElement(val));
            list[y].dodajNaKoniec(new listaElement(x));
            listp[y].dodajNaKoniec(new listaElement(val));
        }
    }

    void Graf::dodajMacierzPrima(string nazwa) {
        int x,y,val;
        fstream file(nazwa,std::ios_base::in);
        if (!file.is_open()) {
            cout<<"ERROR"<<endl;
            return;
        }
        file >> x >> y;
        rozmiar = x;
        grafMacierz = new int*[rozmiar];
        for(int i=0;i<rozmiar;i++){
            grafMacierz[i] = new int [rozmiar];
            for(int j=0;j<rozmiar;j++) grafMacierz[i][j] = -1;
        }
        while(file >> x >> y >> val){
            grafMacierz[x][y] = val;
            grafMacierz[y][x] = val;
        }
    }
