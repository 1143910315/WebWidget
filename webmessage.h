#ifndef WEBMESSAGE_H
#define WEBMESSAGE_H

#include <QObject>

class WebMessage : public QObject {
    Q_OBJECT
    Q_INVOKABLE QString getLastContent();
    Q_INVOKABLE void setLastContent(QString lastContent);
    Q_PROPERTY(QString lastContent READ getLastContent WRITE setLastContent NOTIFY lastContentChanged)
    Q_INVOKABLE QString getClickButtonMessage();
    Q_INVOKABLE void setClickButtonMessage(QString clickButtonMessage);
    Q_PROPERTY(QString clickButtonMessage READ getClickButtonMessage WRITE setClickButtonMessage NOTIFY clickButtonMessageChanged)
    // Q_PROPERTY(QString content1 MEMBER clickButtonMessage NOTIFY clickButtonMessageChanged)
public:
    explicit WebMessage(QObject *parent = nullptr);
private:
    QString m_lastContent;
    QString m_clickButtonMessage;
public slots:
    void test();
    void clickButton(QString buttonType);
signals:
    void lastContentChanged();
    void clickButtonMessageChanged();
    // void clickButtonMessageChanged(const QString clickButtonMessage);
};

#endif // WEBMESSAGE_H
