#ifndef ANDROIDINTERFACE_H
#define ANDROIDINTERFACE_H

#include <QObject>

class AndroidInterface : public QObject
{
    Q_OBJECT
public:
    AndroidInterface(QObject *parent = nullptr);
    Q_INVOKABLE void setNotification(const QString &notification);
    QString notification() const;

signals:
    void notificationChanged();

private slots:
    void updateAndroidNotification();

private:
    QString m_notification;

signals:
};

#endif // ANDROIDINTERFACE_H
