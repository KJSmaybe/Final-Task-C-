// adapter_b.h
#ifndef ADAPTER_B_H
#define ADAPTER_B_H

#include "adapter_interface.h"
#include "data_module_b.h"

class AdapterB : public AdapterInterface
{
public:
    AdapterB(DataModuleB* moduleB);
    QList<Product> getProducts() override;

private:
    DataModuleB* m_moduleB;
};

#endif // ADAPTER_B_H
