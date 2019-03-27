#ifndef ITEME_INTERFATA_H
#define ITEME_INTERFATA_H


class Iteme_Interfata
{
    public:
        Iteme_Interfata(int, int, int, int, int);
        int ReturnX();
        int ReturnY();
        virtual ~Iteme_Interfata();
    protected:
        int numar_viata, numar_atac, numar_deplasare, x, y;
    private:
};

class Viata: public Iteme_Interfata
{
    public:
        Viata (int, int);
        ~Viata();
};

class Atac: public Iteme_Interfata
{
    public:
        Atac (int, int);
        ~Atac();
};

class Deplasare: public Iteme_Interfata
{
    public:
        Deplasare (int, int);
        ~Deplasare();
};

#endif // ITEME_INTERFATA_H
