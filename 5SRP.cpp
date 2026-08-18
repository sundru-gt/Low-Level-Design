#include<bits/stdc++.h>
using namespace std;
class Product{
    public:
        string name;
        double price;
    public:
        Product(string name,double price){
            this->name=name;
            this->price=price;
        }
};

class ShoppingCart{
    private:
        vector<Product*>products;
    public:
        void addProduct(Product *p)
        {
            products.push_back(p);
        }
        const vector<Product*>& getProducts()
        {
            return products;    
        }
        double calculateTotal(){
            double total=0;
            for(auto p:products){
                total+=p->price;
            }
            return total;
        }
};
class InvoicePrinter{
    private:
        ShoppingCart *cart;
    public:
    InvoicePrinter(ShoppingCart *cart){
        this->cart=cart;
    }
    void printInvoice(){
        cout<<"Invoice:";
    }   
};
class SavetoDB{
    private:
        ShoppingCart *cart;
    public:
    SavetoDB(ShoppingCart *cart){
        this->cart=cart;
    }
    void saveToDB(){
        cout<<"Saving to DB:";
    }
};
int main(){
    ShoppingCart *cart=new ShoppingCart();
    cart->addProduct(new Product("Apple",100));
    cart->addProduct(new Product("Banana",200));
    InvoicePrinter *printer=new InvoicePrinter(cart);
    printer->printInvoice();
    SavetoDB *saver=new SavetoDB(cart);
    saver->saveToDB();
    return 0;
}