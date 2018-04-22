#ifndef AGENT_H
#define AGENT_H


class Agent
{
    public:
        Agent(int,int,int);
        ~Agent();
    protected:
        int PositionX,PositionY,id,hp,VisRange;
    private:
};

class Soldier: public Agent //de ce nu merge private???
{
    public:
        Soldier(int,int,int);
    protected:

    private:
};

#endif // AGENT_H
