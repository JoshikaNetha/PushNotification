#include "AndroidInterface.h"

#ifdef Q_OS_ANDROID
#include <qjniobject.h>
#include <QtCore/qcoreapplication.h>
#include <QJniEnvironment>
#include <QJniObject>
#endif
AndroidInterface::AndroidInterface(QObject *parent)
    : QObject(parent)
{

    connect(this, &AndroidInterface::notificationChanged,
            this, &AndroidInterface::updateAndroidNotification);

    setNotification("Namaskaram sarwadu");
}

void AndroidInterface::setNotification(const QString &notification)
{
    if (m_notification == notification)
        return;

    //! [notification changed signal]
    m_notification = notification;
    emit notificationChanged();
}

QString AndroidInterface::notification() const
{
    return m_notification;
}

void AndroidInterface::updateAndroidNotification()
{
#ifdef Q_OS_ANDROID
    QJniObject string1 = QJniObject::fromString(m_notification);
    QJniObject::callStaticMethod<void>(
        "com/pushnotification/MainActivity",
        "notify",
        "(Landroid/content/Context;Ljava/lang/String;)V",
        QNativeInterface::QAndroidApplication::context(),
        string1.object<jstring>());

#endif

}
