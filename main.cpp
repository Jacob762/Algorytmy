#include <iostream>
#include <fstream>
#include <random>
#include "Struktury/Prima/Prima.h"
#include "Struktury/Dijkstra/Dijkstra.h"
#include "Struktury/Kruskal/Kruskal.h"
#include "Struktury/BellmanFord/BF.h"
#include "Struktury/Slist/nList.h"

void menu();
void wygenerujGraf(int nody, int krawedzie,float zageszczenie);

int main() {
    menu();
    return 0;
}

void menu(){
    ::srand(time(NULL));
    wygenerujGraf(10,5,0.8);
    int start;
    int wybor;
    string nazwa;
    cout<<"Podaj nazwe pliku"<<endl;
    cin>>nazwa;
    for(;;){
        cout<<endl;
        cout<<"Menu wyboru algorytmow"<<endl;
        cout<<"1. Algorytm Dijkstry"<<endl;
        cout<<"2. Algorytm Prima"<<endl;
        cout<<"3. Algorytm Kruskala"<<endl;
        cout<<"4. Algorytm Bellmana-Forda"<<endl;
        cout<<"5. Wyjdz"<<endl;
        cin.sync(); cin.clear();
        cin>>wybor;
        switch (wybor) {
            case 1: {
                cout << "Wybierz sposob reprezentacji" << endl;
                cout << "0. Reprezentacja listy" << endl;
                cout << "1. Reprezentacja macierzowa" << endl;
                cin.sync();
                cin.clear();
                cin >> wybor;
                cout << "Wybierz liczbe startowa" << endl;
                cin.sync(); cin.clear();
                cin >> start;
                Dijkstra dij = Dijkstra(wybor, start,nazwa);
                break;
        }
            case 2:{
                cout<<"Wybierz sposob reprezentacji"<<endl;
                cout<<"0. Reprezentacja listy"<<endl;
                cout<<"1. Reprezentacja macierzowa"<<endl;
                cin.sync(); cin.clear();
                cin>>wybor;
                cout<<"Wybierz liczbe startowa"<<endl;
                cin.sync(); cin.clear();
                cin>>start;
                Prima prim = Prima(wybor,start,nazwa);
                break;}
            case 3:{
                cout<<"Wybierz sposob reprezentacji"<<endl;
                cout<<"0. Reprezentacja listy"<<endl;
                cout<<"1. Reprezentacja macierzowa"<<endl;
                cin.sync(); cin.clear();
                cin>>wybor;
                cout<<"Wybierz liczbe startowa"<<endl;
                cin.sync(); cin.clear();
                cin>>start;
                Kruskal kru = Kruskal(wybor,start,nazwa);
            }
            case 4:{
                cout<<"Wybierz sposob reprezentacji"<<endl;
                cout<<"0. Reprezentacja listy"<<endl;
                cout<<"1. Reprezentacja macierzowa"<<endl;
                cin.sync(); cin.clear();
                cin>>wybor;
                cout<<"Wybierz liczbe startowa"<<endl;
                cin.sync(); cin.clear();
                cin>>start;
                BF bf = BF(wybor,start,nazwa);
                break;
            }
            case 5:
                exit(21456);
        }
    }
}

void wygenerujGraf(int nody, int krawedzie, float zageszczenie){
    int kraw;
    bool *tabOd = new bool [nody];
    int wyjscia = floor(zageszczenie*nody);
    for(int i=0;i<nody;i++) tabOd[i]= false;
    ofstream file("plik.txt", ios::out);
    if (!file.is_open()) {
        cout<<"ERROR"<<endl;
        return;
    }
    kraw = nody * wyjscia;
    int x,y,z;
    file<<nody<<" "<<kraw<<endl;
    for(int i=0;i<nody;i++){
        x = i;
        tabOd[x] = true;
        for(int j=0;j<wyjscia;j++) {
            y = rand()%nody;
            if(tabOd[y]){
                while(true) {
                    if(tabOd[y]||y==x){
                        y = rand()%nody;
                    } else break;
                }
            }
            tabOd[y] = true;
            z = rand()%20+1;
            file<<x<<" "<<y<<" "<<z<<endl;
        }
        for(int k=0;k<nody;k++) tabOd[k]= false;
    }
    file.close();

}