// data_module_b.h
#ifndef DATA_MODULE_B_H
#define DATA_MODULE_B_H

#include <QList>
#include <QVariantMap>

class DataModuleB
{
public:
    QList<QVariantMap> getRawData() const;
};

#endif // DATA_MODULE_B_H
