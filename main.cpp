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
    int x[30];
    int y[30];
    float distanza=0;
};

void visualizzazione(Atleta snowborder[], int &i)
{
    ifstream fin("atleti.csv");
    string str;
    while(getline(fin,str, ';'))
    {
        snowborder[i].matricola=str;
        cout<<' '<<str<<"   ";
        getline(fin,snowborder[i].cognome);
        cout<<snowborder[i].cognome<<" ";
        snowborder[i].y[0]=0;
        snowborder[i].x[0]=0;
        i++;
        cout<<endl;
    }
    fin.close();
}

void gestione(Atleta snowborder[], int &i)
{
    int a=0,y=0,y1=11;
    for(int h=0; h<i; h++)
    {
        for(int k=1; k<30; k++)
        {
                y=rand()%y1+a;
                if(k%3==0)
                    a=a+10;
            snowborder[h].x[k]=rand()%101;
            snowborder[h].y[k]=y;
        }
        a=0;
    }
   for(int h=0; h<i; h++)
    {
        for(int k=1; k<30; k++)
        {
            snowborder[h].distanza+=sqrt((pow(snowborder[h].x[k]-snowborder[h].x[k-1],2))+(pow(snowborder[h].y[k]-snowborder[h].y[k-1],2)));
        }
    }

    cout<<endl<<"Coordinate generate correttamente!"<<endl<<endl;

    fstream fout("gara.csv");
    for(int h=0; h<i; h++)
    {
        fout<<snowborder[h].matricola<<';';
        fout<<snowborder[h].cognome<<';';
        for(int k=0; k<30; k++)
        {
            fout<<snowborder[h].x[k]<<';';
            fout<<snowborder[h].y[k]<<';';
        }
        fout<<snowborder[h].distanza<<endl;
    }
    fout.close();

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

void podio(Atleta snowborder[], int &i, int &scelta)
{
    Atleta appoggio;
    for(int a=0;a<i-1;a++)
    {
        for(int b=a+1;b<i;b++)
        {
            if(snowborder[b].distanza>snowborder[a].distanza)
            {
                appoggio=snowborder[b];
                snowborder[b]=snowborder[a];
                snowborder[a]=appoggio;
            }
        }
    }

    cout<<"          PODIO   "<<endl;
    for(int c=0;c<3;c++)
    {
         cout<<"  "<<c+1<<"  "<<snowborder[c].cognome<<"  "<<snowborder[c].distanza<<endl;
    }
    string s;
    cout<<endl<<"vuoi avviare una nuova gara? [si/no]"<<endl;
    cin>>s;
    if(s=="si"||s=="Si")
    {
        for(int a=0;a<i;a++)
        {
            snowborder[a].distanza=0;
        }
            i=0;
    }
    else
    {
        scelta=5;
    }
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
                        cout<<endl;
                        podio(snowborder,i,scelta);
                        cout<<endl;
                        break;
                }
    }while(scelta!=5);
    return 0;
}
