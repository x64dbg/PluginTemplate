#include "PluginTabWidget.h"
#include "pluginmain.h"
#include <QVBoxLayout>
#include <QMessageBox>

PluginTabWidget::PluginTabWidget(QWidget* parent) :
    QWidget(parent)
{
    mPluginMainWindow = new PluginMainWindow(parent);
    mPluginMainWindow->setAutoFillBackground(true);
    QVBoxLayout* layout = new QVBoxLayout(parent);
    layout->addWidget(mPluginMainWindow);
    layout->setMargin(0);
    setLayout(layout);
    setWindowTitle(mPluginMainWindow->windowTitle());
    setWindowIcon(mPluginMainWindow->windowIcon());
}

void PluginTabWidget::closeEvent(QCloseEvent* event)
{
    Q_UNUSED(event);
    mPluginMainWindow->close();
}
