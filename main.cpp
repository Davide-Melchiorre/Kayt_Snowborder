#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <string.h>
#include <stdio.h>

using namespace std;

const int c=10;

struct Atleta
{
    string matricola,cognome;
    string x,y,distanza;
};

void Generazionefile(Atleta snowborder[], int &i)
{
    ifstream fin("atleti.csv");
    string str;
    int x,y,x2,y2,xp=0,yp=0;
    while(getline(fin,str, ';'))
    {
        snowborder[i].matricola=str;
        cout<<str<<" ";
        getline(fin,snowborder[i].cognome, ';');
        cout<<snowborder[i].cognome<<" ";
        getline(fin,snowborder[i].x, ';');
        cout<<snowborder[i].x<<" ";
        getline(fin,snowborder[i].y, ';');
        cout<<snowborder[i].y<<" ";
        getline(fin,snowborder[i].distanza);
        cout<<snowborder[i].distanza<<" ";
        i++;
        cout<<endl;
    }
    fin.close();

    for (int a=0;a<30;a++)
    {
        do{
            x=rand()%101;
            y=rand()%101;
            x2=rand()%101;
            y2=rand()%101;
        }while(x<=x2 && y<=y2 && x>xp);
        xp=x;
        yp=y;
        cout<<x<<endl;
        //cout<<y<<endl;
    }



}
//sqrt((pow(x[i]-x[i+1],2))+(pow(y[i]-y[i+1],2)));
int main()
{
    srand(time(NULL));
    Atleta snowborder[c];
    int i=0;
    int scelta;
    do{
        cout<<"1-Generazione del file e delle coordinate"<<endl;
        cout<<"2-Stampa atleti"<<endl;
        cout<<"3-ricerca atleti"<<endl;
        cout<<"4-stampa del podio"<<endl;
        cout<<"5-Uscita"<<endl<<">>";
        cin>>scelta;
            switch(scelta)
                {
                    case 1:
                        cout<<endl;
                        Generazionefile(snowborder,i);
                        cout<<endl;
                        break;
                    case 2:

                        break;
                    case 3:

                        break;
                    case 4:

                        break;
                }
    }while(scelta!=5);
    return 0;
}
