#include <iostream>

using namespace std;

///< product shoes;
class Shoes
{
public:
    virtual void show()  = 0;
    virtual ~Shoes(){};
};

class NikeShoes: public Shoes
{
public:
    void show()
    {
        cout << "I'm nike shoes!" << endl;
    }
};

class AdidasShoes:public Shoes
{
public:
    void show()
    {
        cout << "I'm AdidasShoes" << endl;
    }
};

class LiNingShoes:public Shoes
{
public:
    void show()
    {
        cout << "I'm LiNing Shoes" << endl;
    }
};

///< product clothes
class Clothes
{
    public:
        virtual void show() = 0;
        virtual ~Clothes(){};
};

class NikeClothes:public Clothes
{
public:
    void show(){
        cout << "I'm nike clothe!" << endl;
    }
};

class AdidasClothes:public Clothes
{
    public:
        void show()
        {
            cout << "I'm adidas clothes!" << endl;
        }
};

class LiningClothes:public Clothes
{
public:
    void show()
    {
        cout << "I'm lining clothes!" << endl;
    }
};




///< factory
class Factory
{
public:
    virtual Shoes* CreateShoes() = 0;
    virtual Clothes* CreateClothes() = 0;
    virtual ~Factory(){};
};

class NikeFactory:public Factory
{
public:
    Shoes* CreateShoes()
    {
        return new NikeShoes();
    }
    Clothes* CreateClothes()
    {
        return new NikeClothes();
    }
};

class AdidasFactory:public Factory
{
public:
    Shoes* CreateShoes(){
        return new AdidasShoes();
    }
    Clothes* CreateClothes()
    {
        return new AdidasClothes();
    }
};

class LiningFactory:public Factory
{
public:
    Shoes* CreateShoes()
    {
        return new LiNingShoes();
    }
    Clothes* CreateClothes()
    {
        return new LiningClothes();
    }
};


int main()
{
    ///< create nike shoe
    Factory* nikeFactory = new NikeFactory();
    Shoes* nikeShoes = nikeFactory->CreateShoes();
    Clothes* nikeClothes = nikeFactory->CreateClothes();
    nikeShoes->show();
    nikeClothes->show();
    delete nikeFactory;
    delete nikeShoes;
    delete nikeClothes;

    ///<create adidas shoe
    Factory* adidasFactory = new AdidasFactory();
    Shoes* adidasShoes = adidasFactory->CreateShoes();
    Clothes* adidasClothes = adidasFactory->CreateClothes();
    adidasShoes->show();
    adidasClothes->show();
    delete adidasFactory;
    delete adidasShoes;
    delete adidasClothes;

    ///< create lining shoe
    Factory* liningFactory = new LiningFactory();
    Shoes*   liningShoes = liningFactory->CreateShoes();
    Clothes* liningClothes = liningFactory->CreateClothes();
    liningShoes->show();
    liningClothes->show();
    delete liningShoes;
    delete liningFactory;
    delete liningClothes;

    return 0;
}
