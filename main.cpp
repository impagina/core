#include <QDebug>

#include "scribus.h"

int main(int argc, char *argv[])
{
    Scribus app(argc, argv);

    return app.run();
    // we only want to call app.exec() (instead of app.run()) if we have an event loop
    // (dbus?) (ale/20130828)
}
