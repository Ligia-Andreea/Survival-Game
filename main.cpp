#include <iostream>
#include "Harta.h"
#include "Agent_Interfata.h"

using namespace std;

// itemii sa se adauge la agenti (se face in runda care e in harta)
// daca agentii cad peste un item il iau, li se adauga la viata/atac/deplasare
//            itemul dispare de pe harta si in locul ala ramane agentul
// daca se suprapun 2 agenti , atac agent 1 -> viata agent 2 si invers
//            daca sunt egale dispar ambii agenti de pe harta
//starea jocului dupa fiecare runda, inainte de a apasa daca sa mai faca o runda sau nu


int main()
{
    cout<<"Afisare harta cu itemi"<<endl;
    Harta h(21, 15);
    int i=1, v;

    while (i!=0)
    {
        if(i==1)
        {
            cout<<"Runda "<<i<<endl;
            h.Runda();
            i++;

        }
        cout<<"   Introduceti 1 pentru a continua jocul"<<endl<<"   Sau 2 pentru a opri"<<endl;
        cin>>v;
        if (v==1)
        {
            cout<<"Runda "<<i<<endl;
            h.Runda();
            i++;
        }
        if (v==2)
        {
            i=0;
            cout<<"Joc terminat";
        }
    }

    return 0;
}

