/**
 *简单工厂模式
 *
 */
#include <iostream>
using namespace std;
class Shoes
{
public:
    virtual void  show() = 0;
    virtual ~Shoes(){};
};

class NikeShoes:public Shoes
{
public:
    void show(){
        cout << "I'am NikeShoes" << endl;
    }
};

class AdidasShoes:public Shoes
{
public:
    void show()
    {
        cout << "I'am AdidasShoes" << endl;
    }
};

class LiNingShoes:public Shoes
{
public:
    void show()
    {
        cout << "I'am LiNingShoes" << endl;
    }
};

enum class ShoesType
{
    NIKE,
    ADIDAS,
    LINING
};
class ShoesFactory
{
public:
    Shoes* createShoes(ShoesType type)
    {
        switch(type)
        {
	   case ShoesType::NIKE:
		return new NikeShoes;
           break;
	   case ShoesType::ADIDAS:
	       return new AdidasShoes;
	   break;
	   case ShoesType::LINING:
	        return new LiNingShoes;
	   break;
	   default:
	       return nullptr;
	   break;
	}
    }
};

int main()
{
    ShoesFactory shoesFact;
    ///< 创建nike
    Shoes* nikeShoes = shoesFact.createShoes(ShoesType::NIKE);
    nikeShoes->show();

    ///< 创建adidas
    Shoes* adidasShoes = shoesFact.createShoes(ShoesType::ADIDAS);
    adidasShoes->show();

    ///< 创建李宁
    Shoes* liningShoes = shoesFact.createShoes(ShoesType::LINING);
    liningShoes->show();

    delete nikeShoes;
    delete adidasShoes;
    delete liningShoes;
    return 0;
}
