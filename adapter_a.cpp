// adapter_a.cpp
#include "adapter_a.h"
#include <QDebug>

AdapterA::AdapterA(DataModuleA *moduleA)
    : m_moduleA(moduleA)
{
}

QList<Product> AdapterA::getProducts()
{
    QList<Product> productList;
    if (!m_moduleA) {
        return productList;
    }

    QStringList rawData = m_moduleA->getRawData();
    for (const QString &line : rawData) {
        QStringList parts = line.split(';');
        // parts: [0] name, [1] category, [2] price, [3] description, [4] in_stock
        if (parts.size() < 5) {
            qWarning() << "Некорректная строка (мало полей):" << line;
            continue;
        }

        Product p;
        p.name       = parts[0].trimmed();
        p.category   = parts[1].trimmed();

        bool ok = false;
        double price = parts[2].toDouble(&ok);
        if (!ok) {
            qWarning() << "Ошибка преобразования цены:" << parts[2];
            // Можно пометить как ошибочную запись
            continue;
        }
        p.price      = price;
        p.description = parts[3].trimmed();

        // in_stock — 0 или 1
        bool inStock = (parts[4].trimmed() == "1");
        p.inStock = inStock;

        productList.append(p);
    }

    return productList;
}
