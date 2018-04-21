#ifndef WEAPON_H
#define WEAPON_H


class Weapon
{
    public:
        Weapon();
        ~Weapon();
        virtual int Fire()=0;//returneaza daca a lovit sau nu
    protected:
    private:
};

#endif // WEAPON_H
