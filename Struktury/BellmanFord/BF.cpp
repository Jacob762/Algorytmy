//
// Created by jakub on 5/20/2023.
//

#include <fstream>
#include "BF.h"

namespace std {
    BF::BF(int choice, int st,string nazwa) {
        zaladujListe(nazwa);
        graf = Graf('f',nazwa);
        switch (choice) {
            case 0:
                getLista();
                break;
            case 1:
                graf.pokaz();
                break;
            default:
                break;
        }
        cout<<endl;
        if(zfordujListe(st)) wyswietl();
        else cout<<"Ujemny cykl"<<endl;
        if(zfordujMacierz(st)) wyswietl();
        else cout<<"Ujemny cykl"<<endl;
    }

    bool BF::zfordujMacierz(int start) {
        drogi = new int [graf.rozmiar];
        poprzednicy = new int [graf.rozmiar];
        bool res;
        for(int i=0;i<graf.rozmiar;i++){
            if(i!=start){
                drogi[i] = INT_MAX;
                poprzednicy[i] = -1;
            } else{
                drogi[i] = 0;
                poprzednicy[i] = -1;
            }
        }
        for(int i=1;i<graf.rozmiar;i++){
            res = true;
            for(int j=0;j<graf.rozmiar;j++){
                for(int k=0;k<graf.rozmiar;k++){
                    if(graf.grafMacierz[j][k]!=INT_MAX&&drogi[j]!=INT_MAX){
                        if(drogi[k]<=drogi[j]+graf.grafMacierz[j][k]) continue;
                        res = false;
                        drogi[k]=drogi[j]+graf.grafMacierz[j][k];
                        poprzednicy[k] = j;
                    }
                }
            }
            if(res) return true;
        }

        for(int i=0;i<graf.rozmiar;i++){
            for(int j=0;j<graf.rozmiar;j++){
                if(drogi[j]>drogi[i]+graf.grafMacierz[i][j]) return false;
            }
        }
        return true;
    }



    void BF::wyswietl(){
        int* S = new int [graf.rozmiar];
        node* temp;
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
        cout<<endl;
    }

    void BF::poprawMacierz(){

    }

    void BF::zaladujListe(string nazwa) {
        int x,y,val;
        int s;
        fstream file(nazwa,std::ios_base::in);
        if (!file.is_open()) {
            cout<<"ERROR"<<endl;
            return;
        }
        file >> x >> y;
        node* temp;
        s = x;
        rozmiarL = x;
        lista = new nList [x];
        for(int i=0;i<s;i++) lista[i] = nList();
        while(file >> x >> y >> val){
            lista[x].dodajNaKoniec(new node(x,y,val));
        }
    }

    bool BF::zfordujListe(int start) {
        node *temp;
        drogi = new int [rozmiarL];
        poprzednicy = new int [rozmiarL];
        bool res;
        for(int i=0;i<rozmiarL;i++){
            if(i!=start){
                drogi[i] = INT_MAX;
                poprzednicy[i] = -1;
            } else{
                drogi[i] = 0;
                poprzednicy[i] = -1;
            }
        }
        for(int i=1;i<rozmiarL;i++){
            res = true;
            for(int j=0;j<rozmiarL;j++){
                temp = lista[j].head;
                while(temp!=NULL){
                    if(drogi[j]!=INT_MAX){
                        if(drogi[temp->next]<=drogi[j]+temp->val){
                            temp = temp->nextEl;
                            continue;
                        }
                        res = false;
                        drogi[temp->next] = drogi[j]+temp->val;
                        poprzednicy[temp->next] = j;
                    }
                    temp = temp->nextEl;
                }
            }
            if(res) return true;
        }
        for(int i=0;i<rozmiarL;i++){
            temp = lista[i].head;
            while(temp!=NULL){
                if(drogi[temp->next]<=drogi[i]+temp->val) return false;
                temp = temp->nextEl;
            }
        }
        return true;
    }

    void BF::getLista(){
        node* temp;
        for(int i=0;i<rozmiarL;i++){
            temp = lista[i].head;
            cout<<i<<"\t";
            while (temp!=NULL){
                cout<<temp->next<<" : "<<temp->val<<"  ";
                temp = temp->nextEl;
            }
            cout<<endl;
        }
    }
} // std