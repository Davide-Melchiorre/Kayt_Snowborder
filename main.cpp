#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <time.h>

using namespace std;

const int c=10;

struct Atleta
{
    string matricola,cognome;
    int x[30],y[30];
    float distanza;
};

void visualizzazione(Atleta snowborder[], int &i)
{
    ifstream fin("atleti.csv");
    string str;
    while(getline(fin,str, ';'))
    {
        snowborder[i].matricola=str;
        cout<<str<<" ";
        getline(fin,snowborder[i].cognome);
        cout<<snowborder[i].cognome<<" ";
        i++;
        cout<<endl;
    }
    fin.close();
}

void gestione(Atleta snowborder[], int &i)
{
    int x=0,y=0,x1=11,y1=0;
    for(int h=0; h<i; h++)
    {
        snowborder[h].x[0]=0;
        snowborder[h].y[0]=0;
        for(int k=1; k<=30; k++)
        {
                x=rand()%x1+y;
                if(k%3==0)
                    y=y+10;
            snowborder[h].x[k]=rand()%101;
            snowborder[h].y[k]=x;

        }
        y=0;
    }

    for(int h=0; h<i; h++)
    {
        for(int k=1; k<=30; k++)
        {
            snowborder[h].distanza+=sqrt((pow(snowborder[h].x[k]-snowborder[h].x[k-1],2))+(pow(snowborder[h].y[k]-snowborder[h].y[k-1],2)));
        }
    }
    cout<<endl<<"Coordinate generate correttamente!"<<endl<<endl;

    fstream fout("atleti.csv");
    for(int h=0; h<i; h++)
    {
        fout<<snowborder[h].matricola<<';';
        fout<<snowborder[h].cognome<<';';
        for(int k=1; k<=30; k++)
        {
        fout<<snowborder[h].x[k]<<';';
        fout<<snowborder[h].y[k]<<';';
        }
        fout<<snowborder[h].distanza<<endl;
    }
    fout.close();

    /*for(int h=0; h<i; h++)
    {
        cout<<snowborder[h].matricola<<"  "<<snowborder[h].cognome<<"  "<<snowborder[h].distanza<<endl;
    }*/
}

void risultati(Atleta snowborder[], int &i)
{
    cout<<endl<<"I RISULTATI DELLA GARA SONO :"<<endl;
    for(int h=0; h<i; h++)
    {
        cout<<"  "<<snowborder[h].matricola<<"  "<<snowborder[h].cognome<<"  "<<snowborder[h].distanza<<endl;
    }
    cout<<endl;
}

void podio(Atleta snowborder[], int &i)
{
    Atleta appoggio;

}


int main()
{
    srand(time(NULL));
    Atleta snowborder[c];
    int i=0;
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
                        podio(snowborder,i);
                        break;
                }
    }while(scelta!=5);
    return 0;
}
/*1;D'Addetta
2;Di vito
3;De Bonis
4;Saracino
5;Martella
6;Mischitelli
7;Di Tullo
8;Gentile
9;Totaro
10;Pompilio*/
