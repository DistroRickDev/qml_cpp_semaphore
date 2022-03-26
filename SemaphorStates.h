#pragma once
#include <QMap>
#include <QString>

enum class SemaphoreState{
    ALL_OFF,
    GREEN_ON,
    YELLOW_ON,
    RED_ON
};

static QMap<SemaphoreState, QString> kSemaphoreStateMap {
  {SemaphoreState::ALL_OFF, "ALL_OFF"},
  {SemaphoreState::GREEN_ON, "GREEN_ON"},
  {SemaphoreState::YELLOW_ON, "YELLOW_ON"},
  {SemaphoreState::RED_ON, "RED_ON"}
};

static QString kLiveRed{ "#ff0000" };
static QString kDimmedRed{ "#4d1a1a"};
static QString kLiveYellow{ "#ffa500"};
static QString kDimmedYellow{ "#4d3b1a"};
static QString kLiveGreen{ "#32cd32"};
static QString kDimmedGreen{ "#244324"};



