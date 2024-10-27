#pragma once

#include <QWidget>

#include "dwmapi.h"
#pragma comment(lib, "dwmapi.lib")

QT_BEGIN_NAMESPACE
namespace Ui {
    class StartWidget;
}
QT_END_NAMESPACE

class StartWidget : public QWidget {
    Q_OBJECT

public:
    StartWidget(QWidget* parent = nullptr);

    ~StartWidget();

private slots:

private:
    Ui::StartWidget* ui;
};
