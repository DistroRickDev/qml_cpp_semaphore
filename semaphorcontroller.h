#pragma once
#include <QObject>
#include "SemaphorStates.h"

class SemaphorController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString green READ green WRITE setGreen NOTIFY greenChanged)
    Q_PROPERTY(QString red READ red WRITE setRed NOTIFY redChanged)
    Q_PROPERTY(QString yellow READ yellow WRITE setYellow NOTIFY yellowChanged)

public:
    SemaphorController();
    QString green();
    QString red();
    QString yellow();

signals:
    void greenChanged();
    void redChanged();
    void yellowChanged();

public slots:
    /*
     * @brief SM controls flow of semaphor on a statemachine
     */
    void semaphoreStateMachine();
private:
    SemaphoreState m_current_state;

    QString m_green;
    QString m_red;
    QString m_yellow;

    void setGreen(QString value);
    void setRed(QString value);
    void setYellow(QString value);

};
