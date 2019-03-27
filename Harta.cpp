#include "Harta.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Harta::Harta(int lungime, int latime)
{
    int i, j, x, y;
    lung = lungime;
    lat = latime;

    v=new int*[lung];
    for (i=0; i<lung; i++)
    {
        v[i]=new int[lat];
        for (j=0; j<lat; j++)
        {
            v[i][j]=0;
        }
    }


    //Declarare agenti
    srand(time(0));
    a = new Agent_Interfata*[21];
    for(int i = 0; i< 7; i++)
    {
        a[i] = new Agent_1 ((rand()%lung), (rand()%lat));
        a[i+7] = new Agent_2 ((rand()%lung), (rand()%lat));
        a[i+14] = new Agent_3 ((rand()%lung), (rand()%lat));
    }

    for(int i = 0; i< 21; i++)
        a[i]->SetHarta(lung, lat);



    //Declarare Iteme

    srand(time(0));
    item = new Iteme_Interfata*[21];
    for(int i = 0; i< 7; i++)
    {
        item[i] = new Viata ((rand()%lung), (rand()%lat));
        item[i+7] = new Atac ((rand()%lung), (rand()%lat));
        item[i+14] = new Deplasare ((rand()%lung),(rand()%lat));
    }

        for(int i =0; i< 21; i++)
        if(i < 7)
            v[a[i]->ReturnX()][a[i]->ReturnY()] = 1;
        else
            if( i >= 7 && i < 14)
                v[a[i]->ReturnX()][a[i]->ReturnY()] = 2;
            else
                v[a[i]->ReturnX()][a[i]->ReturnY()] = 3;

    for(int i =0; i< 21; i++)
        if(i < 7)
            v[item[i]->ReturnX()][item[i]->ReturnY()] = 4;
        else
            if( i >= 7 && i < 14)
            v[item[i]->ReturnX()][a[i]->ReturnY()] = 5;
            else
            v[item[i]->ReturnX()][item[i]->ReturnY()] = 6;


    Afisare();

}


void Harta::Afisare()
{
    int i, j;

    for (i=0; i<lung; i++)
    {
        for (j=0; j<lat; j++)
        {
            if (v[i][j]==0)   //nu e nimic
                cout<<"- ";
            else
                if (v[i][j]==1)   //agent 1
                    cout<<"1 ";
                else
                    if (v[i][j]==2)   //agent 2
                        cout<<"2 ";
                    else
                        if (v[i][j]==3)   //agent 3
                            cout<<"3 ";
                        else
                            if (v[i][j]==4)   //viata
                                cout<<"v ";
                            else
                                if (v[i][j]==5)   //atac
                                    cout<<"a ";
                                else
                                    if (v[i][j]==6)   //deplasare
                                        cout<<"d ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Harta::Reset()
{
    int i,j;
    for (i=0; i<lung; i++)
    {
        for (j=0; j<lat; j++)
        {
            v[i][j]=0;
        }
    }
}

void Harta::Runda()
{
    Reset();

    for(int i = 0; i< 7; i++)
    {
        a[i]->Move();
        a[i+7]->Move();
        a[i+14]->Move();
    }

//agentul gasescte item
   for(int i = 0; i< 21; i++)
    {
   int ax, ay, itx, ity;
   ax=a[i]->ReturnX();
   ay=a[i]->ReturnY();
   itx=item[i]->ReturnX();
   ity=item[i]->ReturnY();
   if((v[itx][ity])!=0&&(v[ax][ay])!=0) //verificam daca agentul si un item se afla in accelasi spatiu
        {
            if((v[itx][ity])==4)
            {
                v[i][j]=+4;//se adauga la viata agentului
            }
            if((v[itx][ity])==5)
            {
                v[i][j]=-5;//agentul pierde din viata
            }
            if(v[itx][ity]==6)
            {
                a[i]->Move();
            }

        }
    }
    for(int i =0; i< 21; i++)
        if(i < 7)
            v[a[i]->ReturnX()][a[i]->ReturnY()] = 1;
        else
            if( i >= 7 && i < 14)
                v[a[i]->ReturnX()][a[i]->ReturnY()] = 2;
            else
                v[a[i]->ReturnX()][a[i]->ReturnY()] = 3;

    for(int i =0; i< 21; i++)
        if(i < 7)
            v[item[i]->ReturnX()][item[i]->ReturnY()] = 4;
        else
            if( i >= 7 && i < 14)
            v[item[i]->ReturnX()][a[i]->ReturnY()] = 5;
            else
            v[item[i]->ReturnX()][item[i]->ReturnY()] = 6;

    Afisare();
}

Harta::~Harta()
{
    //dtor
}

