#ifndef ADAPTER_INTERFACE_H
#define ADAPTER_INTERFACE_H

#include <QList>
#include <QString>
#include "product.h"

/*!
 * \brief Интерфейс адаптера для конвертации данных в унифицированный формат
 */
class AdapterInterface
{
public:
    virtual ~AdapterInterface() = default;

    /*!
     * \brief Метод для получения списка продуктов в унифицированном формате
     */
    virtual QList<Product> getProducts() = 0;
};

#endif // ADAPTER_INTERFACE_H
