#include "processManager.h"

#include <QProcess>
#include <QTimer>
#include <QCoreApplication>

ProcessManager::ProcessManager(QProcess &process) :
    m_process(process)
{
    start();
    m_timer = new QTimer();
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, &ProcessManager::start);
    m_timer->start();
}

ProcessManager::~ProcessManager()
{
    delete m_timer;
}

void ProcessManager::start()
{
    if (m_process.pid() != 0)
        return;

    QString command;
    QStringList arguments;


#ifdef Q_OS_LINUX
    QString dir = QCoreApplication::applicationDirPath();
    command = command = dir + "/jre/bin/java";
    arguments << "-Dfile.encoding=UTF-8";
    arguments << "-jar";
    arguments << dir + "/reader.jar";
#endif

#ifdef Q_OS_WIN
    QString dir = QCoreApplication::applicationDirPath();
    command = dir + "\\jre\\bin\\java.exe";
    arguments << "-Dfile.encoding=UTF-8";
    arguments << "-jar";
    arguments << dir + "\\reader.jar";
#endif

    m_process.start(command.toUtf8(), arguments);
}
