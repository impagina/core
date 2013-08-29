#include <pluginInterface.h>

class LoadSla15 : public QObject, public PluginLoadInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginLoadInterface)

    public:
        QString getName();
};
