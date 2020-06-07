#include "public.h"
#include "event.h"
#include "map.h"
#include "tower.h"


/*	������������ʼ
**	==============================Tower Start=======================
*/
/* ��Ҫע���ʼ���б�Ҫ�Ͷ���˳��һ�£�����QT�ᱨ�� */
Tower::Tower() : m_cost(2), m_HP(9) {
}
Tower::~Tower() {
}
/* ��ȡ��HP */
int Tower::GetHP(void){
    return m_HP;
}
/* ��ȡ����ֵ */
int Tower::GetCost(void){
    return m_cost;
}

/* ��������� */
void Tower::Dismantle(Map &map) {
    /* ������ظ�һ���� */
    gConsoleEvent.AddUsrCost(m_cost/2);
    /* �ڵ�ͼ�в����� */
    map.SetCh(this->m_x, this->m_y, __MAP_CH_EMPTY__);
    /* �ӵ�ͼ���б��в����� */
    map.EraseTower(this->m_x, this->m_y);
    /* ������ */
    delete this;
}

/*	���ƣ�	���������
**	���ܣ�	�ڵ�ͼ map �Ľ��� m_focus �����ɷ����� __MAP_CH_TOWER__
**	���Σ�	Map &map;	��ͼ��
**	���أ�	��
*/
int Tower::Build(Map &map) {
    /* ������㲻Ϊ�� */
    if (__MAP_CH_EMPTY__ != map.GetCh(gConsoleEvent.GetXFocus(), gConsoleEvent.GetYFocus()))
    {
        /* �����ڷǿյط����� */
        return -1;
    }
    /* ��ҽ������������� */
    int Ret = gConsoleEvent.SubUsrCost(m_cost);
    /* ������ûǮ�� */
    if (Ret < 0)
    {
        /* ���� */
        return -1;
    }
    /* ������������������� */
    this->m_x = gConsoleEvent.GetXFocus();
    this->m_y = gConsoleEvent.GetYFocus();
    /* �ڵ�ͼ�н����� */
	map.SetCh(gConsoleEvent.GetXFocus(), gConsoleEvent.GetYFocus(), __MAP_CH_TOWER__);
    /* ���¼������б��м����������� */
    map.InsertTower(this->m_x, this->m_y, *this);

    return 0;
}
/*	��������������
**	==============================Tower End=======================
*/
