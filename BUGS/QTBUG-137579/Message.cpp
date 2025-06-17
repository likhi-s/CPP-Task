#include "Message.h"


Message::Message(const QString &text) : m_body(text) {}

QString Message::body() const
{
    return m_body;
}

/*QDebug operator<<(QDebug dbg, const Message &message)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace();
    dbg << "Message(" << message.body() << ")";
    return dbg;
}*/

/*QDebug operator<<(QDebug dbg, const Message &message)
{
    QDebugStateSaver saver(dbg);
    dbg << "Message(" <<Qt::hex<< message.body() << ")";
    return dbg;
}*/

QDebug operator<<(QDebug dbg, const Message &message)
{
    QDebugStateSaver saver(dbg);
    dbg.noquote();
    dbg << "Message(" << message.body() << ")";
    return dbg;
}

