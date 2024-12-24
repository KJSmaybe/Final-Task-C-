// mainwindow.cpp
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_table(new QTableWidget(this)),
    m_filterCategory(new QLineEdit(this)),
    m_filterInStock(new QCheckBox("Только в наличии", this)),
    m_loadButton(new QPushButton("Загрузить данные", this)),
    m_filterButton(new QPushButton("Применить фильтр", this))
{
    setupUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // Верхняя панель с полями фильтра
    QHBoxLayout *filterLayout = new QHBoxLayout();
    filterLayout->addWidget(new QLabel("Категория:", this));
    filterLayout->addWidget(m_filterCategory);
    filterLayout->addWidget(m_filterInStock);
    filterLayout->addWidget(m_filterButton);

    mainLayout->addLayout(filterLayout);
    mainLayout->addWidget(m_table);

    // Кнопка загрузки
    mainLayout->addWidget(m_loadButton);

    setCentralWidget(central);

    // Настройка таблицы
    m_table->setColumnCount(5);
    QStringList headers;
    headers << "Name" << "Category" << "Price" << "Description" << "In Stock";
    m_table->setHorizontalHeaderLabels(headers);
    m_table->horizontalHeader()->setStretchLastSection(true);

    // Связь сигналов и слотов
    connect(m_loadButton, &QPushButton::clicked, this, &MainWindow::loadData);
    connect(m_filterButton, &QPushButton::clicked, this, &MainWindow::applyFilter);
}

/*!
 * \brief Загружает данные из всех модулей и объединяет их
 */
void MainWindow::loadData()
{
    m_allProducts.clear();

    // Создаём объекты модулей
    DataModuleA moduleA;
    DataModuleB moduleB;
    DataModuleC moduleC;

    // Создаём адаптеры
    AdapterA adapterA(&moduleA);
    AdapterB adapterB(&moduleB);
    AdapterC adapterC(&moduleC);

    // Получаем продукты
    QList<Product> productsA = adapterA.getProducts();
    QList<Product> productsB = adapterB.getProducts();
    QList<Product> productsC = adapterC.getProducts();

    // Объединяем
    m_allProducts.append(productsA);
    m_allProducts.append(productsB);
    m_allProducts.append(productsC);

    // Отобразим все продукты (без фильтра)
    populateTable(m_allProducts);
}

/*!
 * \brief Применяет фильтры к списку продуктов
 */
void MainWindow::applyFilter()
{
    QString categoryFilter = m_filterCategory->text().trimmed();
    bool onlyInStock = m_filterInStock->isChecked();

    QList<Product> filtered;
    for (const Product &p : m_allProducts) {
        bool categoryMatch = categoryFilter.isEmpty() || p.category.contains(categoryFilter, Qt::CaseInsensitive);
        bool inStockMatch  = !onlyInStock || p.inStock;

        if (categoryMatch && inStockMatch) {
            filtered.append(p);
        }
    }

    populateTable(filtered);
}

/*!
 * \brief Заполняет QTableWidget данными из products
 */
void MainWindow::populateTable(const QList<Product> &products)
{
    m_table->clearContents();
    m_table->setRowCount(products.size());

    for (int i = 0; i < products.size(); ++i) {
        const Product &p = products[i];
        // Столбцы: name, category, price, description, inStock
        QTableWidgetItem *itemName = new QTableWidgetItem(p.name);
        QTableWidgetItem *itemCategory = new QTableWidgetItem(p.category);
        QTableWidgetItem *itemPrice = new QTableWidgetItem(QString::number(p.price));
        QTableWidgetItem *itemDesc = new QTableWidgetItem(p.description);
        QTableWidgetItem *itemStock = new QTableWidgetItem(p.inStock ? "true" : "false");

        m_table->setItem(i, 0, itemName);
        m_table->setItem(i, 1, itemCategory);
        m_table->setItem(i, 2, itemPrice);
        m_table->setItem(i, 3, itemDesc);
        m_table->setItem(i, 4, itemStock);
    }

    // Подгоняем ширину столбцов
    m_table->resizeColumnsToContents();
}
