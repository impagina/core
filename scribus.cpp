#include "scribus.h"

#include <iostream>

#include <QDebug>
#include <QStringList>
#include <QFile>
#include <QFileInfo>

/**
  * TODO: On windows, depending on how the application is started, arguments() is not "correctly" filled.
  * we will have to check if this affects us. (ale/20130828)
  */

Scribus::Scribus(int argc, char *argv[]) :
    QCoreApplication(argc, argv)
{
    setApplicationName(SCRIBUSNAME); // defined in the .pro file
    setApplicationVersion(SCRIBUSVERSION);
}

int Scribus::run()
{
    int result = EXIT_SUCCESS;
    QStringList arguments = this->arguments();
    QStringList filename = QStringList();
    // qDebug() << "arguments" << arguments;


    for (int i = 1; i < arguments.count(); i++)
    {
        QString argument = arguments.at(i);
        if (argument == "-v")
        {
            std::cout << getApplicationVersion().toLocal8Bit().data() << std::endl;
            return EXIT_SUCCESS;
        }
        else if ((argument == "-h") || (argument == "-?") || (argument == "--help"))
        {
            std::cout << getApplicationHelp().toLocal8Bit().data() << std::endl;
            return EXIT_SUCCESS;

        }
        else if (QFileInfo(QFile::decodeName(argument.toLocal8Bit())).exists())
        {

            filename << argument.toLocal8Bit();

        }
        else
        {
            if (argument.left(1) == "-")
            {
                std::cerr << tr("%1: Invalid argument: %2").arg(applicationName()).arg(argument).toLocal8Bit().data() << "\n";
                std::cerr << getApplicationUsage().toUtf8().constData() << "\n";
                return EXIT_FAILURE;
            }
            else
            {
                std::cerr << tr("%1: File %2 does not exist, aborting.").arg(applicationName()).arg(argument).toLocal8Bit().data() << "\n";
                std::cerr << getApplicationUsage().toUtf8().constData() << "\n";
                return EXIT_FAILURE;
            }
        }
    }

    if (filename.empty())
    {
        std::cerr << getApplicationUsage().toUtf8().constData() << "\n";
        return EXIT_FAILURE;
    }

    // TODO: load the file (ale/20130828)
    qDebug() << "filename" << filename;

    return result;
}

/**
 * @brief Scribus::getApplicationVersion
 * @return
 * TODO: when the output goes to cerr, the eol may have to be replaced by the caller after getting the string
 * TODO: eventually add more information on the version (compile options? license?) (ale/20130828)
 */
QString Scribus::getApplicationVersion()
{
    return tr("%1 version %2").arg(applicationName()).arg(applicationVersion());
}

/**
 * @brief Scribus::getApplicationUsage
 * @return
 * TODO: when the output goes to cerr, the eol may have to be replaced by the caller after getting the string
 */
QString Scribus::getApplicationUsage()
{
    return
        tr("%1 version %2").arg(applicationName()).arg(applicationVersion()) + "\n" +
        tr("Try %1 -h for more information.").arg(arguments().at(0));
}

/**
 * @brief Scribus::getApplicationHelp
 * @return
 * TODO: when the output goes to cerr, the eol may have to be replaced by the caller after getting the string
 */
QString Scribus::getApplicationHelp()
{
    return
        tr("%1 version %2").arg(applicationName()).arg(applicationVersion()) + "\n" +
        tr("Usage:") + "\n" +
        tr("  %1 [arguments] file [..]  process the specified file(s)").arg(arguments().at(0)) + "\n" +
        tr("Arguments:") + "\n" +
        "  -v           " + tr("Print version information and exit") + "\n" +
        "  -h -? --help " + tr("Print Help (this message) and exit");
}
