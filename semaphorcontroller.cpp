#include <QDebug>
#include <QTimer>
#include "semaphorcontroller.h"

SemaphorController::SemaphorController() : m_current_state{SemaphoreState::ALL_OFF}, m_green{kDimmedGreen}, m_red{kDimmedRed}, m_yellow{kDimmedYellow}
{
    qDebug() << "CTOR:" << SemaphorController::staticMetaObject.className();
    qDebug() << "GreenColor" << m_green;
    qDebug() << "RedColor" << m_red;
    qDebug() << "YellowColor" << m_yellow;
    semaphoreStateMachine();
}

QString SemaphorController::green()
{
    return m_green;
}

QString SemaphorController::red()
{
    return m_red;
}

QString SemaphorController::yellow()
{
    return m_yellow;
}

void SemaphorController::semaphoreStateMachine()
{
    auto timer_ms{0};
    qDebug() << "Current State:" << kSemaphoreStateMap[m_current_state];
    switch (m_current_state) {
    case SemaphoreState::ALL_OFF:
        m_current_state = SemaphoreState::RED_ON;
        setGreen(kDimmedGreen);
        setRed(kDimmedRed);
        setYellow(kDimmedYellow);
        timer_ms = 100;
        break;
    case SemaphoreState::RED_ON:
        m_current_state = SemaphoreState::YELLOW_ON;
        setGreen(kDimmedGreen);
        setRed(kLiveRed);
        setYellow(kDimmedYellow);
        timer_ms = 2000;
        break;
    case SemaphoreState::YELLOW_ON:
        m_current_state = SemaphoreState::GREEN_ON;
        setGreen(kDimmedGreen);
        setRed(kDimmedRed);
        setYellow(kLiveYellow);
        timer_ms = 1000;
        break;
    case SemaphoreState::GREEN_ON:
        m_current_state = SemaphoreState::RED_ON;
        setGreen(kLiveGreen);
        setRed(kDimmedRed);
        setYellow(kDimmedYellow);
        timer_ms = 3000;
        break;
    default:
        m_current_state = SemaphoreState::ALL_OFF;
        break;
    }
     QTimer::singleShot(timer_ms, this, &SemaphorController::semaphoreStateMachine);
}

void SemaphorController::setGreen(QString value)
{
    m_green = std::move(value);
    emit greenChanged();
}

void SemaphorController::setRed(QString value)
{
    m_red = std::move(value);
    emit redChanged();
}

void SemaphorController::setYellow(QString value)
{
    m_yellow = std::move(value);
    emit yellowChanged();
}
