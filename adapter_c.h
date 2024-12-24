// adapter_c.h
#ifndef ADAPTER_C_H
#define ADAPTER_C_H

#include "adapter_interface.h"
#include "data_module_c.h"

class AdapterC : public AdapterInterface
{
public:
    AdapterC(DataModuleC* moduleC);
    QList<Product> getProducts() override;

private:
    DataModuleC* m_moduleC;
};

#endif // ADAPTER_C_H
