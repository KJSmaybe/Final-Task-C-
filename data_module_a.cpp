// data_module_a.cpp
#include "data_module_a.h"

QStringList DataModuleA::getRawData() const
{
    // Допустим, каждая строка содержит:
    // "Имя;Категория;Цена;Описание;Наличие(0 или 1)"
    return {
        "ProductA;CategoryA;100.5;Описание продукта A;1",
        "ProductB;CategoryB;;Описание продукта B;0", // здесь нет цены, пример ошибки
        "ProductC;CategoryA;200;Описание продукта C;1"
    };
}
