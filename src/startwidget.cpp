#include "startwidget.h"

#include "./ui_startwidget.h"
#include "QAbstractItemView"
#include "QBoxLayout"
#include "QCheckBox"
#include "QComboBox"
#include "QFormLayout"
#include "QLabel"
#include "QLineEdit"
#include "QMainWindow"
#include "QOverload"
#include "QPainter"
#include "QPushButton"
#include "QStackedLayout"
#include "QTimer"
#include "QToolBar"
#include "QVBoxLayout"
#include <format>
#include "QDialog"
#include "QDockWidget"
#include "QStatusBar"
#include "QMenuBar"
#include "QTreeWidget"

StartWidget::StartWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::StartWidget) {
    ui->setupUi(this);

    this->setWindowFlag(Qt::Widget);

    QVBoxLayout* vlay{ new QVBoxLayout{this} };
    this->setLayout(vlay);

    QComboBox* cb{ new QComboBox{this} };
    cb->setPlaceholderText("cnm");
    vlay->addWidget(cb);



}

StartWidget::~StartWidget() { delete ui; }
