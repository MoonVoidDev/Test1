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

StartWidget::StartWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::StartWidget) {
    ui->setupUi(this);

    this->setWindowFlag(Qt::Widget);

    QVBoxLayout* mainvl{ new QVBoxLayout(this) };

    QStackedLayout* sl{ new QStackedLayout(mainvl) };

    QWidget* page1w{ new QWidget(this) };
    QWidget* page2w{ new QWidget(this) };
    QVBoxLayout* page1vl{ new QVBoxLayout(page1w) };
    QVBoxLayout* page2vl{ new QVBoxLayout(page2w) };

    QPushButton* b1{ new QPushButton("b1", this) };
    QPushButton* b2{ new QPushButton("b2", this) };
    QPushButton* b3{ new QPushButton("b98", this) };
    QPushButton* b4{ new QPushButton("b97", this) };

    page1vl->addStretch();
    page1vl->addWidget(b1);
    page1vl->addWidget(b2);
    page1vl->addStretch();
    page2vl->addWidget(b3);
    page2vl->addWidget(b4);
    sl->addWidget(page1w);
    sl->addWidget(page2w);

    QPushButton* nextPage{ new QPushButton("next", this) };
    QPushButton* prePage{ new QPushButton("pre", this) };

    QHBoxLayout* hl{ new QHBoxLayout(nullptr) };

    hl->addStretch(4);
    hl->addWidget(prePage);
    hl->addStretch(1);
    hl->addWidget(nextPage);
    hl->addStretch(4);

    mainvl->addLayout(hl);

    prePage->setEnabled(false);
    sl->setCurrentIndex(0);

    connect(nextPage, &QPushButton::clicked, this,
        [sl, prePage, nextPage]() -> void {
            if (sl->currentIndex() < sl->count() - 1) {
                sl->setCurrentIndex(sl->currentIndex() + 1);
                prePage->setEnabled(true);
            }
            if (sl->currentIndex() == sl->count() - 1) {
                nextPage->setEnabled(false);
            }
            else {
                nextPage->setEnabled(true);
            }
        });

    connect(prePage, &QPushButton::clicked, this,
        [sl, prePage, nextPage]() -> void {
            if (sl->currentIndex() > 0) {
                sl->setCurrentIndex(sl->currentIndex() - 1);
                nextPage->setEnabled(true);
            }
            if (sl->currentIndex() == 0) {
                prePage->setEnabled(false);
            }
            else {
                prePage->setEnabled(true);
            }
        });

}

StartWidget::~StartWidget() { delete ui; }
