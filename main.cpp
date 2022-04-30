
#include <iostream>
#include "libreria.h"
using namespace std;
#include "libreria.h"

int main()
{
    TElencoConti conti;
    int nConti=0;

    
    
    char nomefile[]="conti.txt";
    cout << "Carica i conti." << endl;
    
    leggi_dati(nomefile,conti,nConti);
    
    
    stampa_elenco_conti(conti,nConti);


    bubble_sort(conti,nConti);
    stampa_elenco_conti(conti,nConti);
    char ibanP[]="IT90B0300203280886893758982";
    char ibanR[]="IT32G0300203280556627826997";
    transazione(ibanP,ibanR,400.0,conti,nConti);
    stampa_elenco_conti(conti,nConti);

    return 0;
}