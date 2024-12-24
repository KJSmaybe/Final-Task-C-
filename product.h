#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

struct Product {
    QString name;
    QString category;
    double price;
    QString description;
    bool inStock;
};

#endif // PRODUCT_H
