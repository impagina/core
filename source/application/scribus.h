#ifndef SCRIBUS_H
#define SCRIBUS_H

#include <QCoreApplication>

class QString;

#include <QList>
#include <plugins/pluginInterface.h>


class Scribus : public QCoreApplication
{
    Q_OBJECT
public:
    explicit Scribus(int argc, char *argv[]);
    int run();
    QString getApplicationVersion();
    QString getApplicationUsage();
    QString getApplicationHelp();

    void loadPlugins();

protected:
    QList<PluginLoadInterface*> pluginsLoad;

signals:
    
public slots:
    
};

#endif // SCRIBUS_H
