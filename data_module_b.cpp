// data_module_b.cpp
#include "data_module_b.h"

QList<QVariantMap> DataModuleB::getRawData() const
{
    // Допустим, поля отличаются:
    // "title", "group", "cost", "descr", "available"
    QList<QVariantMap> dataList;

    QVariantMap item1;
    item1["title"]     = "ProductD";
    item1["group"]     = "CategoryB";
    item1["cost"]      = 300.75;
    item1["descr"]     = "Описание продукта D";
    item1["available"] = true;
    dataList.append(item1);

    QVariantMap item2;
    item2["title"]     = "ProductE";
    item2["group"]     = "CategoryC";
    item2["cost"]      = 0;  // допустим, цена 0
    item2["descr"]     = "Описание продукта E";
    item2["available"] = false;
    dataList.append(item2);

    return dataList;
}
