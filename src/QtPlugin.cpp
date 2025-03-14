#include "QtPlugin.h"
#include "PluginDialog.h"
#include "PluginTabWidget.h"
#include "pluginmain.h"

#include <QFile>

static PluginDialog* pluginDialog;
static PluginTabWidget* pluginTabWidget;
static HANDLE hSetupEvent;
static HANDLE hStopEvent;

static QByteArray getResourceBytes(const char* path)
{
    QByteArray b;
    QFile s(path);
    if(s.open(QFile::ReadOnly))
        b = s.readAll();
    return b;
}

static QWidget* getParent()
{
    return QWidget::find((WId)Plugin::hwndDlg);
}

void QtPlugin::Init()
{
    hSetupEvent = CreateEventW(NULL, TRUE, FALSE, NULL);
    hStopEvent = CreateEventW(NULL, TRUE, FALSE, NULL);
}

void QtPlugin::Setup()
{
    QWidget* parent = getParent();
    pluginDialog = new PluginDialog(parent);
    pluginDialog->show();
    pluginTabWidget = new PluginTabWidget(parent);
    GuiAddQWidgetTab(pluginTabWidget);

    SetEvent(hSetupEvent);
}

void QtPlugin::WaitForSetup()
{
    WaitForSingleObject(hSetupEvent, INFINITE);
}

void QtPlugin::Stop()
{
    GuiCloseQWidgetTab(pluginTabWidget);
    pluginTabWidget->close();
    pluginDialog->close();
    delete pluginDialog;
    delete pluginTabWidget;

    SetEvent(hStopEvent);
}

void QtPlugin::WaitForStop()
{
    WaitForSingleObject(hStopEvent, INFINITE);
}

void QtPlugin::ShowTab()
{
    GuiShowQWidgetTab(pluginTabWidget);
}
