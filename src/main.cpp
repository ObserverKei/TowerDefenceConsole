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
    QTime qClock;    /* Qt��ʱ�� */
    qClock.start();  /* ��ʼ��ʱ */

    while (true)
    {
        /* �������� */
        system("cls");
        /* ��ʾ��ͼ */
        consoleMap.Show();

        /* ���Qt��ʱ���ﵽ__ENEMY_WAITE_TIME_MS__���� */
        if (qClock.elapsed() > __ENEMY_CREATE_TIME_MS__)
        {
            /* Qt��ʱ�����¶�ʱ */
            qClock.restart();
            /* ��ȡ����ʣ�๹������ */
            Ret = consoleMap.GetEnemyResidueNum();
            /* ���Թ�������������һ���µĵ��� */
            if (Ret > 0)
            {
                Enemy *pNewEnemy = new Enemy;
                pNewEnemy->Draw(consoleMap);
            }
        }

        /* ��������ȡ�������� */
        key = gConsoleEvent.Input();
        /* ��ʾ����İ��������ڵ��� */
        printf("[%c]", key);
        /* ʶ�𰴼����� */
        switch (key)
        {
        case 'T': {
            /* ����һ���µ��� */
            Tower *pNewTower = new Tower;
            /* �����T�������������ڵ�ǰ���㽨������� */
            pNewTower->Build(consoleMap);
            break;
        }
        case 'D': {
            /* ��ȡĿǰ���� */
            Tower *pCurTower = consoleMap.GetCurTower(gConsoleEvent.GetXFocus(), gConsoleEvent.GetYFocus());
            /* �����Dɾ�����������ӵ�ǰ����λ��ɾ���� */
            pCurTower->Dismantle(consoleMap);
            break;
        }
        default: {
            /* ����Ƿ���������ƶ����� */
            gConsoleEvent.SetFucus(key);
            break;
        }
        }
    }

    return a.exec();
}
