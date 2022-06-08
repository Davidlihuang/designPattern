#include <iostream>

using namespace std;

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

class ShoesFactory
{
public:
    virtual Shoes* CreateShoes() = 0;
    virtual ~ShoesFactory(){};
};

class NikeShoesFactory:public ShoesFactory
{
public:
    Shoes* CreateShoes()
    {
        return new NikeShoes();
    }
};

class AdidasShoesFactory:public ShoesFactory
{
public:
    Shoes* CreateShoes(){
        return new AdidasShoes();
    }
};

class LiningShoesFactory:public ShoesFactory
{
public:
    Shoes* CreateShoes()
    {
        return new LiNingShoes();
    }
};


int main()
{
    ///< create nike shoe
    ShoesFactory* nikeFactory = new NikeShoesFactory();
    Shoes* nikeShoes = nikeFactory->CreateShoes();
    nikeShoes->show();
    delete nikeFactory;
    delete nikeShoes;

    ///<create adidas shoe
    ShoesFactory* adidasFactory = new AdidasShoesFactory();
    Shoes* adidasShoes = adidasFactory->CreateShoes();
    adidasShoes->show();
    delete adidasFactory;
    delete adidasShoes;

    ///< create lining shoe
    ShoesFactory* liningFactory = new LiningShoesFactory();
    Shoes*   liningShoes = liningFactory->CreateShoes();
    liningShoes->show();
    delete liningShoes;
    delete liningFactory;

    return 0;
}
