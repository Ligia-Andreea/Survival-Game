#ifndef HARTA_H
#define HARTA_H
#include "Agent_Interfata.h"
#include "Iteme_Interfata.h"
class Harta
{

    public:
        Harta(int lungime, int latime);
        void Afisare();
        void Reset();
        void Runda();
        virtual ~Harta();
    protected:
        int **v, i, j, n;
        int lung, lat;
        Agent_Interfata **a;
        Iteme_Interfata **item;
    private:

};

#endif // HARTA_H
