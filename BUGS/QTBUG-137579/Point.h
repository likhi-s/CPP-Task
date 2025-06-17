#ifndef POINT_H
#define POINT_H
#include <iostream>

#include <QDebug>

class Point
{
public:
    Point(int x);
    Point(std::string y);
    int x() const;   
    std::string y() const;
private:
    int m_x;
    std::string m_y;
};

QDebug operator<<(QDebug dbg, const Point &point);

#endif // POINT_H
