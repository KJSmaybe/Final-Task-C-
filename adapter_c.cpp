// adapter_c.cpp
#include "adapter_c.h"
#include <QDebug>
#include <QVariantMap>

AdapterC::AdapterC(DataModuleC *moduleC)
    : m_moduleC(moduleC)
{
}

QList<Product> AdapterC::getProducts()
{
    QList<Product> productList;
    if (!m_moduleC) {
        return productList;
    }

    QList<QVariant> rawData = m_moduleC->getRawData();
    for (const QVariant &variant : rawData) {
        if (!variant.canConvert<QVariantMap>()) {
            qWarning() << "Некорректная структура данных, не QVariantMap!";
            continue;
        }

        QVariantMap map = variant.toMap();
        Product p;

        // Из map берём вложенные поля
        if (map.contains("info") && map["info"].canConvert<QVariantMap>()) {
            QVariantMap infoMap = map["info"].toMap();
            p.name     = infoMap.value("name", "").toString();
            p.category = infoMap.value("cat", "").toString();
        } else {
            qWarning() << "Отсутствует/некорректное поле info";
        }

        if (map.contains("priceDetail")) {
            bool ok = false;
            double price = map["priceDetail"].toDouble(&ok);
            if (!ok) {
                qWarning() << "Ошибка преобразования цены:" << map["priceDetail"];
                continue;
            }
            p.price = price;
        } else {
            qWarning() << "Отсутствует поле priceDetail";
            continue;
        }

        if (map.contains("text")) {
            p.description = map["text"].toString();
        } else {
            qWarning() << "Отсутствует поле text";
        }

        if (map.contains("isInStock")) {
            p.inStock = map["isInStock"].toBool();
        } else {
            qWarning() << "Отсутствует поле isInStock";
        }

        productList.append(p);
    }

    return productList;
}
