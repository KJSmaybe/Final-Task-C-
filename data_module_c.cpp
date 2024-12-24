// data_module_c.cpp
#include "data_module_c.h"

QList<QVariant> DataModuleC::getRawData() const
{
    // Эмулируем список QVariant, внутри которого лежат QVariantMap/другие структуры
    // Допустим, поля: { "info": { "name": "...", "cat": "..." }, "priceDetail": 400.0, "text": "desc", "isInStock": false }
    QList<QVariant> dataList;

    QVariantMap obj1;
    QVariantMap info1;
    info1["name"] = "ProductF";
    info1["cat"]  = "CategoryA";
    obj1["info"] = info1;
    obj1["priceDetail"] = 400.0;
    obj1["text"] = "Описание продукта F";
    obj1["isInStock"] = true;

    QVariantMap obj2;
    QVariantMap info2;
    info2["name"] = "ProductG";
    info2["cat"]  = "CategoryC";
    obj2["info"] = info2;
    obj2["priceDetail"] = 600.25;
    obj2["text"] = "Описание продукта G";
    obj2["isInStock"] = false;

    dataList.append(obj1);
    dataList.append(obj2);

    return dataList;
}
