#include "Point.h"

Point::Point(int x) : m_x(x)
{

}
Point::Point(std::string y): m_y(y)
{

}

int Point::x() const { return m_x; }

std::string Point::y() const { return m_y; }



QDebug operator<<(QDebug dbg, const Point &point)
{
    //dbg.nospace();
    //dbg << "Point (" << point.x()<< ")";
    dbg << "Point (" << point.y()<< ")";


    return dbg;
}



