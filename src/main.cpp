#include <QCoreApplication>
#include "public.h"
#include "event.h"
#include "map.h"
#include "tower.h"
#include "enemy.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char key = 0;
    Map   consoleMap;
    int Ret = -1;
    QTime qClock;    /* Qt定时器 */
    qClock.start();  /* 开始定时 */

    while (true)
    {
        /* 画面清屏 */
        system("cls");
        /* 显示地图 */
        consoleMap.Show();

        /* 如果Qt定时器达到__ENEMY_WAITE_TIME_MS__毫秒 */
        if (qClock.elapsed() > __ENEMY_CREATE_TIME_MS__)
        {
            /* Qt定时器重新定时 */
            qClock.restart();
            /* 获取敌人剩余构建个数 */
            Ret = consoleMap.GetEnemyResidueNum();
            /* 可以构建敌人则生成一个新的敌人 */
            if (Ret > 0)
            {
                Enemy *pNewEnemy = new Enemy;
                pNewEnemy->Draw(consoleMap);
            }
        }

        /* 非阻塞获取按键输入 */
        key = gConsoleEvent.Input();
        /* 显示输入的按键，用于调试 */
        printf("[%c]", key);
        /* 识别按键功能 */
        switch (key)
        {
        case 'T': {
            /* 定义一个新的塔 */
            Tower *pNewTower = new Tower;
            /* 如果是T建塔操作，就在当前焦点建造防御塔 */
            pNewTower->Build(consoleMap);
            break;
        }
        case 'D': {
            /* 获取目前的塔 */
            Tower *pCurTower = consoleMap.GetCurTower(gConsoleEvent.GetXFocus(), gConsoleEvent.GetYFocus());
            /* 如果是D删除塔操作，从当前焦点位置删除塔 */
            pCurTower->Dismantle(consoleMap);
            break;
        }
        default: {
            /* 如果是方向键，就移动焦点 */
            gConsoleEvent.SetFucus(key);
            break;
        }
        }
    }

    return a.exec();
}
