/*!
    \file main.cpp
    \brief Con questo programma si riesce a simulare una gara di kayt snowboarding
    \author Davide Melchiorre
    \version 1.0
    \date 24/02/2023
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <time.h>

using namespace std;
//! \var c
//! \brief c è una costante che tiene il numero di tutti i partecipanti presenti nel file
const int c=10;

//! \struct Atleta
//! \brief Atleta è la struttura dove si basa il programma
struct Atleta
{
    //! \var matricola
    //! \brief matricola serve per identificare univocamente l'atleta con un numero ed è di tipo string
    string matricola;
    //! \var cognome
    //! \brief cognome indica il cognome dell'atleta ed è di tipo string
    string cognome;
    //! \var x
    //! \brief x è un vettore di tipo int di 30 elementi e serve per salvarsi tutte le coordinate della X
    int x[30];
    //! \var y
    //! \brief y è un vettore di tipo int di 30 elementi e serve per salvarsi tutte le coordinate della Y
    int y[30];
    //! \var distanza
    //! \brief distanza ci serve per indicare la lunghezza percorsa ed è di tipo float
    float distanza=0;
};

/*!
    \fn visualizzazione(Atleta snowborder[], int &i)
    \param snowborder vettore di struct
    \param i contatore del numero di partecipanti
    \brief serve per caricare il vettore di struct e visualizzare i partecipanti

*/
void visualizzazione(Atleta snowborder[], int &i)
{
    //! \var fin
    //! \brief apre il canale per il file in lettura
    ifstream fin("atleti.csv");
    //! \var str
    //! \brief variabile di appoggio per salvarsi il contenuto del file nel vettore
    string str;
    while(getline(fin,str, ';'))
    {
        snowborder[i].matricola=str;
        cout<<' '<<str<<"   ";
        getline(fin,snowborder[i].cognome);
        cout<<snowborder[i].cognome<<" ";
        //! \brief riempie il primo valore della x di tutti i partecipanti con 0
        snowborder[i].y[0]=0;
        //! \brief riempie il primo valore della y di tutti i partecipanti con 0
        snowborder[i].x[0]=0;
        i++;
        cout<<endl;
    }
    //! \note fin.close() serve per chiudere il canale del file
    fin.close();
}

/*!
    \fn gestione(Atleta snowborder[], int &i)
    \param snowborder vettore di struct
    \param i contatore del numero di partecipanti
    \brief gestisce le coordinate mettendole nel vettore e calcola la distanza
*/
void gestione(Atleta snowborder[], int &i)
{
    //! \var a
    //! \brief varibile che serve per rendere piu realistica la gara
    int a=0;
    //! \var y
    //! \brief il numero randomico per calcolare la coordinata di Y
    int y=0;
    //! \var y1
    //! \brief varibile che serve per rendere piu realistica la gara
    int y1=11;
    //! \brief ciclo for che scorre per tutti i partecipanti
    for(int h=0; h<i; h++)
    {
        //! \brief ciclo for che scorre per 30 che sarebbero i minuti quindi genera una coordinata al minuto
        for(int k=1; k<30; k++)
        {
                y=rand()%y1+a;
                if(k%3==0)
                    //! \brief il valore di a aumenta di 10 ogni "3 minuti" per essere piu realistica
                    a=a+10;
            //! \brief viene generato un numero casuale da 0 a 100 per la x
            snowborder[h].x[k]=rand()%101;
            //! \brief viene assegnato il valore alla Y gnerato precedentemente
            snowborder[h].y[k]=y;
        }
        //! \brief ad ogni partecipante la a si azzera
        a=0;
    }
    //! \brief ciclo for che scorre per tutti i partecipanti
   for(int h=0; h<i; h++)
    {
        //! \brief ciclo for che scorre per 30 che sarebbero i minuti
        for(int k=1; k<30; k++)
        {
            snowborder[h].distanza+=sqrt((pow(snowborder[h].x[k]-snowborder[h].x[k-1],2))+(pow(snowborder[h].y[k]-snowborder[h].y[k-1],2)));
        }
    }

    cout<<endl<<"Coordinate generate correttamente!"<<endl<<endl;

    //! \var fout
    //! \brief apre il canale del file in scrittura
    fstream fout("gara.csv");
    //! \brief ciclo for che scorre per tutti i partecipanti
    for(int h=0; h<i; h++)
    {
        //! \brief viene scritto nel file la matricola
        fout<<snowborder[h].matricola<<';';
        //! \brief viene scritto nel file il cognome
        fout<<snowborder[h].cognome<<';';
        //! \brief ciclo for che scorre per 30 che sarebbero i minuti
        for(int k=0; k<30; k++)
        {
            //!\brief viene scritto nel file tutte le coordinate di X
            fout<<snowborder[h].x[k]<<';';
            //! \brief viene scritto nel file tutte le coordinate di Y
            fout<<snowborder[h].y[k]<<';';
        }
        //! \brief viene scritto nel file la distanza percorsa
        fout<<snowborder[h].distanza<<endl;
    }
    //! \note fout.close() serve per chiudere il canale del file
    fout.close();

}

/*!
    \fn risultati(Atleta snowborder[], int &i)
    \param snowborder vettore di struct
    \param i contatore del numero di partecipanti
    \brief fornisce i risultati ottenuti

*/

void risultati(Atleta snowborder[], int &i)
{
    cout<<endl<<"I RISULTATI DELLA GARA SONO :"<<endl;
    //! \brief ciclo for che scorre per tutti i partecipanti
    for(int h=0; h<i; h++)
    {
        //! \brief stampa di tutti i risultati ottenuti
        cout<<"  "<<snowborder[h].matricola<<"  "<<snowborder[h].cognome<<"  "<<snowborder[h].distanza<<endl;
    }
    cout<<endl;
}

/*!
    \fn podio(Atleta snowborder[], int &i, int &scelta)
    \param snowborder vettore di struct
    \param i contatore del numero di partecipanti
    \param scelta sarebbe il numero del menu che serve per far terminare il programma
    \brief calcolo del podio
*/

void podio(Atleta snowborder[], int &i)
{
    //! \var appoggio
    //! \brief variabile di appoggio che serve per lo scambio tra i partecipanti
    Atleta appoggio;

    //! \brief ciclo for che scorre tra tutti i partecipanti tranne l'ultimo
    for(int a=0;a<i-1;a++)
    {
        //! \brief ciclo for che scorre tra i partecipanti partendo dal successivo del ciclo precedente
        for(int b=a+1;b<i;b++)
        {
            //! \brief if che controlla se la distanza 2 è maggiore della distanza 1
            if(snowborder[b].distanza>snowborder[a].distanza)
            {
                //! \brief qui avviene lo scambio tra i partecipanti
                appoggio=snowborder[b];
                snowborder[b]=snowborder[a];
                snowborder[a]=appoggio;
            }
        }
    }

    cout<<"          PODIO   "<<endl;
    //! \brief ciclo for che scorre solo per tre che sarebbero le tre prime tre posizioni
    for(int c=0;c<3;c++)
    {
        //! \brief stapa del podio
        cout<<"  "<<c+1<<"  "<<snowborder[c].cognome<<"  "<<snowborder[c].distanza<<endl;
    }
    //! \var s
    //! \brief serve per avviare o meno una nuova gara
    string s;
    cout<<endl<<"vuoi avviare una nuova gara? [si/no]"<<endl;
    cin>>s;
    //! \brief controllo se s è uguale a Si e quindi si vuole avviare una nuova gara
    if(s=="si"||s=="Si")
    {
        //! \brief ciclo for che scorre per tutti i partecipanti
        for(int a=0;a<i;a++)
        {
            //! \brief qui si azzera la distanza di ogni partecipante
            snowborder[a].distanza=0;
        }
        //! \brief azzeramento del contatore dei partecipanti
        i=0;
    }
}

/*!
    \fn main()
    \brief fuzione principale del programma
*/

int main()
{
    srand(time(NULL));
    //! \var snowborder
    //! \brief vettore di struct
    Atleta snowborder[c];
    //! \var i
    //! \brief contatore dei partecipanti
    int i=0;
    //! \var scelta
    //! \brief per scegliere una voce del menu
    int scelta;
    do{
        cout<<"1-Visualizza atleti"<<endl;
        cout<<"2-Generazione del file e delle coordinate"<<endl;
        cout<<"3-Visualizza risultati"<<endl;
        cout<<"4-stampa del podio"<<endl;
        cout<<"5-Uscita"<<endl<<">>";
        cin>>scelta;
            switch(scelta)
                {
                    case 1:
                        cout<<endl;
                        visualizzazione(snowborder,i);
                        cout<<endl;
                        break;
                    case 2:
                        gestione(snowborder,i);
                        break;
                    case 3:
                        risultati(snowborder,i);
                        break;
                    case 4:
                        cout<<endl;
                        podio(snowborder,i);
                        cout<<endl;
                        break;
                }
    }while(scelta!=5);
    return 0;
}
