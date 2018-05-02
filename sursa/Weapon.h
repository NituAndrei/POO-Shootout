#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
    public:
        Weapon(int,int,int);
        ~Weapon();
        virtual int Fire();//returneaza damage dat
        int getRange();
        int getType();
    protected:
        int Damage,Range,id,PositionX,PositionY,Type;
    private:
};

#endif // WEAPON_H
