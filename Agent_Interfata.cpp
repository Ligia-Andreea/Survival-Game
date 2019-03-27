#include "Agent_Interfata.h"
#include <cstdlib>
#include <ctime>

Agent_Interfata::Agent_Interfata(int a, int b, int c, int d, int e)
{
    nr_viata=a;
    nr_atac=b;
    nr_deplasare=c;
    x=d;
    y=e;

}

int Agent_Interfata::ReturnX()
{
    return x;
}
int Agent_Interfata::ReturnY()
{
    return y;
}

Agent_Interfata::~Agent_Interfata()
{
    //dtor
}



Agent_1::Agent_1(int x, int y): Agent_Interfata(1,1,1,x,y)
{

}

Agent_2::Agent_2(int x, int y): Agent_Interfata(1,1,2,x,y)
{

}

Agent_3::Agent_3(int x, int y): Agent_Interfata(1,1,3,x,y)
{

}



Agent_1::~Agent_1()
{

}

Agent_2::~Agent_2()
{

}

Agent_3::~Agent_3()
{

}



void Agent_Interfata::SetHarta(int k, int l)
{
    lungime_harta = k;
    latime_harta = l;
}

void Agent_1::Move()  //tura
{

    int r=1+(rand()%2);
    if (r==1)
    {
        if(x + nr_deplasare >= lungime_harta && nr_deplasare > 0)
            nr_deplasare *= -1;
        if(x + nr_deplasare < 0)
            nr_deplasare *= -1;
        x += nr_deplasare;
    }
    if (r==2)
    {
        if(y + nr_deplasare >= latime_harta && nr_deplasare > 0)
            nr_deplasare *= -1;
        if(y + nr_deplasare < 0)
            nr_deplasare *= -1;
        y += nr_deplasare;
    }

}

void Agent_2::Move()  //nebun
{

    int ok=0;
    while (ok==0)
    {
        int r=1+(rand()%4);
        if (r==1)
        {
            x -= nr_deplasare;
            y -= nr_deplasare;
            if (x>=0 && y>=0)
                ok=1;
        }
        if (r==2)
        {
            x -= nr_deplasare;
            y += nr_deplasare;
            if (x>=0 && y<=latime_harta)
                ok=1;
        }
        if (r==3)
        {
            x += nr_deplasare;
            y -= nr_deplasare;
            if (x<=lungime_harta && y>=0)
                ok=1;
        }
        if (r==4)
        {
            x += nr_deplasare;
            y += nr_deplasare;
            if (x<=lungime_harta && y<=latime_harta)
                ok=1;
        }
    }

}

void Agent_3::Move()  //rege
{
/*
    int ok=0;
    while (ok==0)
    {
        int r=1+(rand()%8);
        if (r==1)
        {
            x -= nr_deplasare;
            y -= nr_deplasare;
            if (x>=0 && y>=0)
                ok=1;
        }
        if (r==2)
        {
            x -= nr_deplasare;
            if (x>=0 && y<=latime_harta)
                ok=1;
        }
        if (r==3)
        {
            x -= nr_deplasare;
            y += nr_deplasare;
            if (x>=0 && y<=latime_harta)
                ok=1;
        }
        if (r==4)
        {
            y += nr_deplasare;
            if (x<=lungime_harta && y<=latime_harta)
                ok=1;
        }
        if (r==5)
        {
            x += nr_deplasare;
            y += nr_deplasare;
            if (x<=lungime_harta && y<=latime_harta)
                ok=1;
        }
        if (r==6)
        {
            x += nr_deplasare;
            if (x<=lungime_harta && y>=0)
                ok=1;

        }
        if (r==7)
        {
            x += nr_deplasare;
            y -= nr_deplasare;
            if (x>=0 && y>=0)
                ok=1;
        }
        if (r==8)
        {
            y -= nr_deplasare;
            if (x<=lungime_harta && y>=0)
                ok=1;
        }
    }
*/
}
