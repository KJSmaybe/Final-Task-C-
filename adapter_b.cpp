// adapter_b.cpp
#include "adapter_b.h"
#include <QDebug>

AdapterB::AdapterB(DataModuleB *moduleB)
    : m_moduleB(moduleB)
{
}

QList<Product> AdapterB::getProducts()
{
    QList<Product> productList;
    if (!m_moduleB) {
        return productList;
    }

    QList<QVariantMap> rawData = m_moduleB->getRawData();
    for (const QVariantMap &m : rawData) {
        Product p;

        // Извлекаем поля, учитывая их другие названия
        if (m.contains("title"))
            p.name = m["title"].toString();
        else
            qWarning() << "Отсутствует поле title";

        if (m.contains("group"))
            p.category = m["group"].toString();
        else
            qWarning() << "Отсутствует поле group";

        if (m.contains("cost")) {
            bool ok = false;
            double price = m["cost"].toDouble(&ok);
            if (!ok) {
                qWarning() << "Ошибка преобразования цены:" << m["cost"];
                continue;
            }
            p.price = price;
        } else {
            qWarning() << "Отсутствует поле cost";
            continue;
        }

        if (m.contains("descr"))
            p.description = m["descr"].toString();
        else
            qWarning() << "Отсутствует поле descr";

        if (m.contains("available"))
            p.inStock = m["available"].toBool();
        else
            qWarning() << "Отсутствует поле available";

        productList.append(p);
    }

    return productList;
}
