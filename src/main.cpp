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
    Enemy consoleEnemy;

    while (true)
    {
        /* 画面清屏 */
        system("cls");
        /* 显示地图 */
        consoleMap.Show();
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
