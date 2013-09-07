#include <plugins/pluginInterface.h>
#include <document/document.h>

class LoadSla15 : public QObject, public PluginLoadInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginLoadInterface)

    protected:
        Document *document;

    public:
        Document *getDocument() {return document;}
        bool loadFile(QString filename);
        QString getName();
};
