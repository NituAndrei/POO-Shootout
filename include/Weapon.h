#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
    public:
        Weapon(int,int,int);
        ~Weapon();
        virtual int Fire();//returneaza damage dat
        int getRange();
        const char* getType();
    protected:
        int Damage,Range,HitChance,id,PositionX,PositionY;
        char Type[5];
    private:
};


class AssaultRifle: public Weapon
{
    public:
        AssaultRifle(int,int,int);
    protected:
    private:
};
#endif // WEAPON_H
