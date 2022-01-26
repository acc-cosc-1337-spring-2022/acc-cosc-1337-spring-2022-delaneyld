//
#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
public:
    Product(int id, double p) : id_no{id}, price{p}{}
    double get_price()const;
private:
    int id_no;
    double price;
};

#endif