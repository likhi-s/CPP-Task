#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QList>
#include "date.h"
#include "bookingmanager.h"

class Month;
class Calendar;

class CalendarWidget : public QWidget
{
    Q_OBJECT

public:
    CalendarWidget(QWidget *parent = nullptr);
    ~CalendarWidget();

private:
    void setupUI();
    void refreshCalendar();
    void clearTheaterButtons();
    void clearBookingOptions();
    void showBookingOptions();
    void onDayClicked(Date date);
    void goToPreviousMonth();
    void goToNextMonth();

    Month *m_month;
    Calendar *m_calendar;
    BookingManager *m_bookingmanager;
    Date *m_date;

    QPushButton *m_dayButtons[42];
    QPushButton *m_monthTitle;
    QPushButton *m_currentDateDisplay;

    QList<QPushButton*> theaterButtons;
    QPushButton *bookButton = nullptr;
    QPushButton *exitButton = nullptr;

    int m_currentYear;
    int m_currentMonth;
    int m_currentDay;
    Date m_currentDate;

    int selectedTheaterId = -1;
    Date selectedDate;
};

#endif // CALENDARWIDGET_H
