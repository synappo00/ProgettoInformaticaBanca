#include "libreria.h"
#include <cstring>
using namespace std;

void leggi_dati(char nomefile[],TElencoConti elencoConti,int &nconti){
    fstream file;
    char saldo[100];
    nconti=0;
    file.open(nomefile,ios::in);
    if(!file){
        cout<<"Errore apertura file"<<endl;
        
    }else{

        while(file>>elencoConti[nconti].nome>>elencoConti[nconti].cognome>>elencoConti[nconti].iban>>saldo){
            
            
            elencoConti[nconti].saldo=atof(saldo);
            nconti++;
            
        }


    }
    file.close();
    
}

void stampa_elenco_conti(TElencoConti elencoConti,int nconti){
    cout << "Conti correnti:" << endl;
    for(int i=0;i<nconti;i++){
        cout<<"Nome : "<<elencoConti[i].nome<<" Cognome : "<<elencoConti[i].cognome<<" IBAN : "<<elencoConti[i].iban<<" Saldo : "<<elencoConti[i].saldo<<endl;

    }
    
}
void versamento(TConto &conto,float valore){
    conto.saldo+=valore;
}
void prelievo(TConto &conto,float valore){
    conto.saldo-=valore;
}

void transazione(TIban pagante,TIban ricevente,float valore,TElencoConti elencoConti,int nconti){
    int indice_conto1=ricerca_per_iban(pagante,elencoConti,nconti);
    int indice_conto2=ricerca_per_iban(ricevente,elencoConti,nconti);
    versamento(elencoConti[indice_conto2],valore);
    prelievo(elencoConti[indice_conto1],valore);
}
int ricerca_per_iban(TIban iban,TElencoConti elencoConti, int nconti){
    

    int pos=-1,mid,low=0,high=nconti-1;
    bool trovato=false;
    while(low<=high && !trovato){
        mid=(low+high)/2;
        if(strcmp(elencoConti[mid].iban,iban)==0){
            trovato=true;
            pos=mid;
            return pos;
        }else if(strcmp(elencoConti[mid].iban,iban)<0){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

    return pos;

    
}

void bubble_sort(TElencoConti elencoConti, int nconti){
    int i=0,j;
    TConto temp;
    bool swap;

    do{
        swap=false;
        for(j=0;j<nconti-1;j++){
            if(strcmp(elencoConti[j].iban,elencoConti[j+1].iban)>0){
                swap=true;
                temp=elencoConti[j];
                elencoConti[j]=elencoConti[j+1];
                elencoConti[j+1]=temp;
            }
        }
        i++;
    }
    while(swap && i<nconti);
    
}
