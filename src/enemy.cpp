#include "public.h"
#include "event.h"
#include "map.h"
#include "enemy.h"

/*	���˺�����ʼ
**	==============================Enemy Start=======================
*/

Enemy::Enemy() : m_HP(9)
               , m_cost(1){
}
Enemy::~Enemy() {
    m_destinationWayPoint = NULL;
}

/* �ڵ�ͼ�������� */
void Enemy::Create(Map &map)
{
    /* ������˺�����������꣬�������д�����캯������ */
    this->m_x = 2;
    this->m_y = 0;
    /* �ڵ�ͼ�й������� */
    map.SetCh(this->m_x, this->m_y, __MAP_CH_ENEMY__);
    /* ���¼��ĵ����б��м�����˵����� */
    map.InsertEnemy(this->m_x, this->m_y, *this);
}

void Enemy::Move(Map &map){
    //system("cls");
    if (!m_HP)
        return;
    else
    {
        m_pos = m_destinationWayPoint->pos();
        m_destinationWayPoint = m_destinationWayPoint->nextWayPoint();
        map.SetCh(m_pos.x,m_pos.y,__MAP_CH_ENEMY__);
    }
}
void Enemy::Draw(Map &map){
    m_pos.x=2;
    m_pos.y=0;
    map.SetCh(m_pos.x, m_pos.y, __MAP_CH_ENEMY__);
    map.GetCh(m_pos.x, m_pos.y);
}

/* ��ȡ����HP */
int Enemy::GetHP(void)
{
    return m_HP;
}

void Enemy::Attack(void) {
}

Enemy::Enemy(Enemy::Point pos)
    : _pos(pos)
    , _nextWayPoint(NULL)
{
}

void Enemy::setNextWayPoint(Enemy *nextPoint)
{
    _nextWayPoint = nextPoint;
}

Enemy* Enemy::nextWayPoint() const
{
    return _nextWayPoint;
}

const Enemy::Point Enemy::pos() const
{
     return _pos;
}


/*	���˺�������
**	==============================Enemy End=======================
*/
