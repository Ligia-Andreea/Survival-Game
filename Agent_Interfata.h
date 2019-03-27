#ifndef AGENT_INTERFATA_H
#define AGENT_INTERFATA_H


class Agent_Interfata
{
    public:
        Agent_Interfata(int,int,int,int,int);
        int ReturnX();
        int ReturnY();
        void SetHarta(int k, int l);
        virtual void Move()=0;
        virtual ~Agent_Interfata();
    protected:
        int nr_viata, nr_atac, nr_deplasare, x, y, lungime_harta, latime_harta;
    private:
};


class Agent_1: public Agent_Interfata
{
    public:
        Agent_1 (int, int);
         ~Agent_1();
         void Move();
    protected:
    private:
};

class Agent_2: public Agent_Interfata
{
    public:
        Agent_2 (int, int);
         ~Agent_2();
         void Move();
    protected:
    private:
};

class Agent_3: public Agent_Interfata
{
    public:
        Agent_3 (int, int);
       ~Agent_3();
       void Move();
    protected:
    private:
};

#endif // AGENT_INTERFATA_H
