// data_module_c.h
#ifndef DATA_MODULE_C_H
#define DATA_MODULE_C_H

#include <QList>
#include <QVariant>

class DataModuleC
{
public:
    QList<QVariant> getRawData() const;
};

#endif // DATA_MODULE_C_H
