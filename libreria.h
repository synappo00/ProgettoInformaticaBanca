#ifndef __LIBRERIA_H__
#define __LIBRERIA_H__
#include <iostream>
#include <cstring>
#include <fstream>

#define LIBAN 30  // lunghezza massima della stringa "IBAN"
#define NCONTI 50 // lunghezza massima dell'ELENCO DEI CONTI CORRENTI
#define LNOME 50  // lunghezza massima del nome o cognome

typedef char TIban[LIBAN];

typedef struct
{
    char nome[LNOME];
    char cognome[LNOME];
    TIban iban;
    float saldo;
} TConto;

typedef TConto TElencoConti[NCONTI];

void stampa_elenco_conti(TElencoConti elencoConti, int nconti);
void leggi_dati(char nomefile[], TElencoConti elencoConti, int &nconti);
void versamento(TConto &conto, float valore);
void prelievo(TConto &conto, float valore);
void transazione(TIban pagante, TIban ricevente, float valore, TElencoConti elencoConti, int nconti);
int ricerca_per_iban(TIban iban, TElencoConti elencoConti, int nconti);
void bubble_sort(TElencoConti elencoConti, int nconti);

#endif //__LIBRERIA_H__