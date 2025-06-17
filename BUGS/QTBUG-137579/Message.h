#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QDebug>

class Message
{
public:
    Message(const QString &text);
    QString body() const;

private:
    QString m_body;
};

QDebug operator<<(QDebug dbg, const Message &message);

#endif // MESSAGE_H
