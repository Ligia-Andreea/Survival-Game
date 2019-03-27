#include "Iteme_Interfata.h"

Iteme_Interfata::Iteme_Interfata(int a, int b, int c, int d, int e)
{
    numar_viata=a;
    numar_atac=b;
    numar_deplasare=c;
    x=d;
    y=e;
}

int Iteme_Interfata::ReturnX()
{
    return x;
}

int Iteme_Interfata::ReturnY()
{
    return y;
}

Iteme_Interfata::~Iteme_Interfata()
{
    //dtor
}


Viata::Viata(int x, int y): Iteme_Interfata(5,0,0,x,y)
{

}

Atac::Atac(int x, int y): Iteme_Interfata(0,5,0,x,y)
{

}

Deplasare::Deplasare(int x, int y): Iteme_Interfata(0,0,5,x,y)
{

}


Viata::~Viata()
{

}

Atac::~Atac()
{

}

Deplasare::~Deplasare()
{

}
