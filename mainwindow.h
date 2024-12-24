// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

#include "adapter_interface.h"
#include "data_module_a.h"
#include "data_module_b.h"
#include "data_module_c.h"
#include "adapter_a.h"
#include "adapter_b.h"
#include "adapter_c.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadData();
    void applyFilter();

private:
    void setupUI();
    void populateTable(const QList<Product> &products);

private:
    QTableWidget* m_table;
    QLineEdit* m_filterCategory;
    QCheckBox*  m_filterInStock;
    QPushButton* m_loadButton;
    QPushButton* m_filterButton;

    QList<Product> m_allProducts; // все продукты (без фильтра)
};

#endif // MAINWINDOW_H
