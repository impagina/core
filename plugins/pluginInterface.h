#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QtPlugin>
class PluginInterface
{
    public:
        virtual ~PluginInterface() {}

        virtual QString getName() = 0;
};

class PluginLoadInterface : public PluginInterface
{
    public:
        virtual ~PluginLoadInterface() {}
};

class PluginStoreInterface : public PluginInterface
{
    public:
        virtual ~PluginStoreInterface() {}
};

Q_DECLARE_INTERFACE(PluginLoadInterface,
                      "org.impagina.Scribus-core.pluginLoadInterface/0.0")
Q_DECLARE_INTERFACE(PluginStoreInterface,
                      "org.impagina.Scribus-core.pluginStoreInterface/0.0")

#endif // PLUGININTERFACE_H
