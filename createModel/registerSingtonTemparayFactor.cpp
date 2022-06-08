#include <iostream>
#include <map>
using namespace std;

///<产品类
class Shoes
{
public:
    virtual void show() =0;
    virtual ~Shoes(){};
};
class NikeShoes:public Shoes
{
public:
    void show(){
        cout << "I'm nike shoes!" << endl;
    }
};

class Clothes
{
public:
    virtual void show() = 0;
    virtual ~Clothes(){};
};

class UniqolClothes:public Clothes
{
public:
    void show()
    {
        cout << "I'm Uniqol clothes!" << endl;
    }
};
///< 产品注册虚基类
template<class Iproduct_t>
class IProductRegistrar{
public:
    virtual Iproduct_t* createProduct()=0;

protected:
    IProductRegistrar(){}
    virtual ~IProductRegistrar(){};

private:
    IProductRegistrar(const IProductRegistrar&);
    const IProductRegistrar& operator=(const IProductRegistrar&);
};

///< 工厂模板类
template<class ProductType_t>
class ProductFactory
{
public:
//获取工厂单例
    static ProductFactory<ProductType_t>& Instance()
    {
        static ProductFactory<ProductType_t> instance;
        return instance;
    }

    //产品注册
    void RegisterProduct(IProductRegistrar<ProductType_t>* registrar, std::string name)
    {
        m_ProductRegistry[name] = registrar;
    }
   
    // 获取产品
    ProductType_t* GetProduct(std::string name)
    {
         if(m_ProductRegistry.find(name) != m_ProductRegistry.end())
         {
             return m_ProductRegistry[name]->createProduct();
         }
         cout << "No product found for:"<< name << endl;
         return nullptr;
    }

private:
    ProductFactory(){};
    ~ProductFactory(){};
    ProductFactory(const ProductFactory&);
    const ProductFactory& operator= (const ProductFactory&);
    
    //保存注册的产品
    std::map<std::string, IProductRegistrar<ProductType_t> *> m_ProductRegistry;
};

///< 产品注册类
template<class ProductType_t, class ProductImpl_t>
class ProductRegistrar: public IProductRegistrar<ProductType_t>
{
public:
    explicit ProductRegistrar(const std::string& name)
    {
        ProductFactory<ProductType_t>::Instance().RegisterProduct(this, name);
    }

    ProductType_t* createProduct()
    {
        return new ProductImpl_t();
    }
};

int main()
{

    ///< register nike.
    ProductRegistrar<Shoes, NikeShoes> registNike("nike");
    Shoes* nikeShoe = ProductFactory<Shoes>::Instance().GetProduct("nike");
    Shoes* nikeShoe1 = ProductFactory<Shoes>::Instance().GetProduct("nike1");
    nikeShoe->show();

    ///< register uniqol
    ProductRegistrar<Clothes, UniqolClothes> registUniq("uniqol");
    Clothes* uniqCloth = ProductFactory<Clothes>::Instance().GetProduct("uniqol");
    uniqCloth->show();

    return 0;
}
