#include "PluginMainWindow.h"
#include "ui_PluginMainWindow.h"

PluginMainWindow::PluginMainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::PluginMainWindow)
{
    ui->setupUi(this);
}

PluginMainWindow::~PluginMainWindow()
{
    delete ui;
}
