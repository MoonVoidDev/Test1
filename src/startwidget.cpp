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


    QPushButton* launchMain{ new QPushButton{"Launch", this} };
    vlay->addWidget(launchMain);


    connect(launchMain, qOverload<bool>(&QPushButton::clicked), this,
        [this]()->void {
            QMainWindow* mw{ new QMainWindow{this} };
            QToolBar* tb{ new QToolBar{mw} };
            tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            tb->setMovable(false);
            mw->addToolBar(Qt::BottomToolBarArea, tb);

            QIcon icon1{ ":/tool_icons/resources/tool_icons/hoshi no.jpg" };
            QAction* a1{ new QAction{"A1", tb} };
            a1->setIcon(icon1);
            QAction* a2{ new QAction{"A2", tb} };
            a2->setIcon(icon1);

            tb->addAction(a1);
            tb->addAction(a2);
            mw->show();
        }
    );



}

StartWidget::~StartWidget() { delete ui; }
