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
template<class Iproduct>
class AbstractFactory
{
public:
    virtual Iproduct* CreateProduct() = 0;
    virtual ~AbstractFactory(){};
};

template<class ConcreteProduct, class abstractProduct_t>
class ConcreteFactory:public AbstractFactory<abstractProduct_t>
{
public:
    abstractProduct_t* CreateProduct()
    {
        return new ConcreteProduct();
    }
};




int main()
{
    ///< create nike shoes
    ConcreteFactory<NikeShoes, Shoes> nikeFactory;
    Shoes* nikeShoe = nikeFactory.CreateProduct();
    nikeShoe->show();

    ///<create nike clothes
    ConcreteFactory<NikeClothes, Clothes> nikeClothesFactory;
    Clothes* nikeClothes = nikeClothesFactory.CreateProduct();
    nikeClothes->show();

    delete nikeShoe;
    delete nikeClothes;


    return 0;
}
