#include "webmessage.h"
#include <QMessageBox>
QString WebMessage::getLastContent() {
    return m_lastContent;
}

void WebMessage::setLastContent(QString lastContent) {
    m_lastContent = lastContent;
    emit lastContentChanged();
}

QString WebMessage::getClickButtonMessage() {
    return m_clickButtonMessage;
}

void WebMessage::setClickButtonMessage(QString clickButtonMessage) {
    m_clickButtonMessage = clickButtonMessage;
    emit clickButtonMessageChanged();
}

WebMessage::WebMessage(QObject *parent)
    : QObject{parent} {
}

void WebMessage::test() {
    QMessageBox::information(NULL, "测试", "页面加载完成，可以开始测试了");
}

void WebMessage::clickButton(QString buttonType) {
    QMessageBox::information(NULL, "点击按钮", "当前点击了" + buttonType);
    setProperty("clickButtonMessage", "最后弹出消息：当前点击了" + buttonType);
}

void WebMessage::clickPage(QJsonObject jsonObject) {
    QString xString;
    QString yString;
    QJsonValueRef v = jsonObject["x"];
    if (v.isString()) {
        xString = v.toString();
    } else if (v.isDouble()) {
        QTextStream(&xString) << v.toDouble();
    }
    v = jsonObject["y"];
    if (v.isString()) {
        yString = v.toString();
    } else if (v.isDouble()) {
        QTextStream(&yString) << v.toDouble();
    }
    QMessageBox::information(NULL, "点击页面", "页面坐标（" + xString + "，" + yString + "）");
}
