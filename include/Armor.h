#ifndef ARMOR_H
#define ARMOR_H


class Armor
{
    public:
        Armor();
        ~Armor();
        virtual void apllyModifiers()=0;
        virtual void removeModifiers()=0;
    protected:

    private:
};

#endif // ARMOR_H
