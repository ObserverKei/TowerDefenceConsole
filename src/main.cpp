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
        /* �������� */
        system("cls");
        /* ��ʾ��ͼ */
        consoleMap.Show();
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
