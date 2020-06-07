#ifndef PUBLIC_H
#define PUBLIC_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <QObject>
#include <QPoint>
#include <string>
#include <map>
#include <QTime>

#define __MAP_X_LEN__           	8
#define __MAP_Y_LEN__           	5
#define __MAP_CH_EMPTY__        	0
#define __MAP_CH_TOWER__            'T'
#define __MAP_CH_ENEMY__            'E'
#define __ENEMY_CREATE_TIME_MS__    3000

using namespace std;

class Event;
class Map;
class Tower;
class Enemy;

extern Event gConsoleEvent;

#endif // PUBLIC_H
