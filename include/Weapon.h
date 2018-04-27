#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
    public:
        Weapon(int);
        ~Weapon();
        virtual int Fire();//returneaza damage dat
        const char* getType();
    protected:
        int Damage,Range,HitChance,id;
        char Type[5];
    private:
};


class AssaultRifle: public Weapon
{
    public:
        AssaultRifle(int);
    protected:
    private:
};
#endif // WEAPON_H
