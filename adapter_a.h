// adapter_a.h
#ifndef ADAPTER_A_H
#define ADAPTER_A_H

#include "adapter_interface.h"
#include "data_module_a.h"

class AdapterA : public AdapterInterface
{
public:
    AdapterA(DataModuleA* moduleA);
    QList<Product> getProducts() override;

private:
    DataModuleA* m_moduleA;
};

#endif // ADAPTER_A_H
