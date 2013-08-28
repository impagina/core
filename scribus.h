#ifndef SCRIBUS_H
#define SCRIBUS_H

#include <QCoreApplication>

class QString;

class Scribus : public QCoreApplication
{
    Q_OBJECT
public:
    explicit Scribus(int argc, char *argv[]);
    int run();
    QString getApplicationVersion();
    QString getApplicationUsage();
    QString getApplicationHelp();

signals:
    
public slots:
    
};

#endif // SCRIBUS_H
