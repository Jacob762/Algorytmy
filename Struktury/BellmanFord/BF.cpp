//
// Created by jakub on 5/20/2023.
//

#include "BF.h"

namespace std {
    BF::BF() {
        graf = Graf('f');
        if(zfordujMacierz(5)) wyswietl();
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
        int spec = start;
        for(int i=1;i<graf.rozmiar;i++){
            res = true;
            for(int j=0;j<graf.rozmiar;j++){
                for(int k=0;k<graf.rozmiar;k++){
                    if(k==start) continue;
                    if(graf.grafMacierz[j][k]!=INT_MAX&&drogi[j]!=INT_MAX){
                        if(drogi[k]<=drogi[j]+graf.grafMacierz[j][k]) continue;
                        res = false;
                        drogi[k]=drogi[j]+graf.grafMacierz[j][k];
                        poprzednicy[k] = spec;
                    }
                }
                if(spec==graf.rozmiar) spec=0;
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
        int sptr = 0;
        for( int i = 0; i < graf.rozmiar; i++ )
        {
            cout << i << ": ";

            // Ścieżkę przechodzimy od końca ku początkowi,
            // Zapisując na stosie kolejne wierzchołki

            for( int j = i; j != -1; j = poprzednicy [ j ] ) S [ sptr++ ] = j;

            // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu

            while( sptr ) cout << S [ --sptr ] << " ";

            // Na końcu ścieżki wypisujemy jej koszt

            cout << "$" << drogi [ i ] << endl;
        }
    }

    void BF::poprawMacierz(){

    }
} // std