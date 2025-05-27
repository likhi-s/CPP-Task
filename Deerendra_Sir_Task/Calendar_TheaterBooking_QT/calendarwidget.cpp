#include "calendarwidget.h"
#include "calendar.h"
#include "month.h"
#include <QString>
#include <QDebug>

CalendarWidget::CalendarWidget(QWidget *parent) : QWidget(parent)
{
    cout << "Calendar Widget Constructor Called" << endl;
    setFixedSize(1000, 800);
    setWindowTitle("CALENDAR");

    m_month = new Month;
    m_calendar = new Calendar;
    m_bookingmanager = new BookingManager;
    m_date = new Date;

    m_currentYear = m_calendar->getCurrentYear();
    m_currentMonth = m_calendar->getCurrentMonth();
    m_currentDay = m_calendar->getCurrentDay();
    m_currentDate = m_calendar->getCurrentDate();

    setupUI();
    refreshCalendar();
}

CalendarWidget::~CalendarWidget()
{
    cout << "Calendar Widget Destructor Called" << endl;
    delete m_month;
    delete m_calendar;
}

void CalendarWidget::setupUI()
{
    int startX = 80;
    int startY = 40;

    QPushButton *leftArrow = new QPushButton("<", this);
    leftArrow->setGeometry(250, startY, 40, 30);
    connect(leftArrow, &QPushButton::clicked, this, &CalendarWidget::goToPreviousMonth);

    QPushButton *rightArrow = new QPushButton(">", this);
    rightArrow->setGeometry(490, startY, 40, 30);
    connect(rightArrow, &QPushButton::clicked, this, &CalendarWidget::goToNextMonth);

    m_monthTitle = new QPushButton(this);
    m_monthTitle->setGeometry(300, startY, 180, 30);
    m_monthTitle->setEnabled(false);

    const char *days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    for (int i = 0; i < 7; ++i)
    {
        QPushButton *button = new QPushButton(days[i], this);
        button->setGeometry(startX + i * 90, startY + 40, 85, 30);
        button->setEnabled(false);
    }

    for (int i = 0; i < 42; ++i)
    {
        m_dayButtons[i] = new QPushButton(this);
        m_dayButtons[i]->setGeometry(startX + (i % 7) * 90, startY + 80 + (i / 7) * 40, 85, 30);

        connect(m_dayButtons[i], &QPushButton::clicked, this, [=]() {
            int day = m_dayButtons[i]->text().toInt();
            if (day > 0) {
                Date date(day, m_currentMonth, m_currentYear);
                onDayClicked(date);
            }
        });
    }

    m_currentDateDisplay = new QPushButton(this);
    m_currentDateDisplay->setGeometry(210, 380, 350, 30);
    m_currentDateDisplay->setEnabled(false);
}

void CalendarWidget::refreshCalendar()
{
    const char *monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    QString title = QString("%1 %2").arg(monthNames[m_currentMonth - 1]).arg(m_currentYear);
    m_monthTitle->setText(title);

    Date today = m_date->getCurrentDate();

    char buffer[100];
    sprintf(buffer, "Current Date: %02d/%02d/%04d", today.getDay(), today.getMonth(), today.getYear());

    QString dateStr = QString(buffer);
    m_currentDateDisplay->setText(dateStr);



    for (int i = 0; i < 42; ++i)
        m_dayButtons[i]->hide();

    int startDay = m_calendar->getStartDay(m_currentMonth, m_currentYear);
    int totalDays = m_month->getDaysInMonth(m_currentYear);

    // for (int d = 1; d <= totalDays; ++d)
    // {
    //     int index = startDay + d - 1;
    //     QString number = QString::number(d);
    //     m_dayButtons[index]->setText(number);
    //     m_dayButtons[index]->show();

    //     Date btnDate(d, m_currentMonth, m_currentYear);

    //     if (btnDate < today) {
    //         m_dayButtons[index]->setEnabled(false);
    //     } else {
    //         m_dayButtons[index]->setEnabled(true);
    //     }
    // }
    for (int d = 1; d <= totalDays; ++d)
    {
        int index = startDay + d - 1;
        Date btnDate(d, m_currentMonth, m_currentYear);

        // Booking info
        int bookedCount = 0;
        if (m_bookingmanager->m_bookingList.find(btnDate) != m_bookingmanager->m_bookingList.end()) {
            bookedCount = m_bookingmanager->m_bookingList[btnDate].size();
        }

        int totalTheaters = m_bookingmanager->m_movietheaterList.size();

        QString label;
        if (bookedCount == 0)
        {
            label = QString::number(d);
            m_dayButtons[index]->setText(label);

        }
        else
        {
            label = QString("%1/%2").arg(d).arg(bookedCount);
            m_dayButtons[index]->setText(label);
        }

        m_dayButtons[index]->setText(label);
        m_dayButtons[index]->show();

        if (btnDate < today || bookedCount >= totalTheaters)
        {
            m_dayButtons[index]->setEnabled(false);
        }
        else
        {
            m_dayButtons[index]->setEnabled(true);
            m_dayButtons[index]->setStyleSheet("");
        }
    }



}

void CalendarWidget::goToPreviousMonth()
{
    m_currentMonth--;
    if (m_currentMonth == 0)
    {
        m_currentMonth = 12;
        m_currentYear--;
    }
    refreshCalendar();
}

void CalendarWidget::goToNextMonth()
{
    m_currentMonth++;
    if (m_currentMonth == 13)
    {
        m_currentMonth = 1;
        m_currentYear++;
    }
    refreshCalendar();
}

void CalendarWidget::onDayClicked(Date date)
{
    selectedDate = date;
    clearTheaterButtons();
    clearBookingOptions();

    auto &allTheaters = m_bookingmanager->m_movietheaterList;
    auto &booked = m_bookingmanager->m_bookingList[date];

    int y = 450;
    for (auto &theater : allTheaters)
    {
        int id = theater.first;
        if (std::find(booked.begin(), booked.end(), id) == booked.end())
        {
            QPushButton *btn = new QPushButton(QString("Theater %1").arg(id), this);
            btn->setGeometry(50, y, 150, 30);
            btn->show();
            theaterButtons.append(btn);

            connect(btn, &QPushButton::clicked, this, [=]() {
                selectedTheaterId = id;
                showBookingOptions();
            });

            y += 40;
        }
    }


    if (y == 450)
        qDebug() << "No theaters available for this day";
}

void CalendarWidget::showBookingOptions()
{
    clearBookingOptions();

    bookButton = new QPushButton("Book", this);
    exitButton = new QPushButton("Exit", this);

    bookButton->setGeometry(250, 450, 100, 30);
    exitButton->setGeometry(250, 490, 100, 30);

    bookButton->show();
    exitButton->show();

    connect(bookButton, &QPushButton::clicked, this, [=]() {
        m_bookingmanager->bookTheater(selectedDate, selectedTheaterId);
        clearBookingOptions();
        clearTheaterButtons();
    });

    connect(exitButton, &QPushButton::clicked, this, [=]() {
        clearBookingOptions();
    });
}

void CalendarWidget::clearTheaterButtons()
{
    for (QPushButton *btn : theaterButtons)
    {
        btn->hide();
        btn->deleteLater();
    }
    theaterButtons.clear();
}

void CalendarWidget::clearBookingOptions()
{
    if (bookButton)
    {
        bookButton->hide();
        bookButton->deleteLater();
        bookButton = nullptr;
    }
    if (exitButton)
    {
        exitButton->hide();
        exitButton->deleteLater();
        exitButton = nullptr;
    }
}
