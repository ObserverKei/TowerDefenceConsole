#include "public.h"
#include "event.h"
#include "map.h"
#include "enemy.h"

/*	敌人函数开始
**	==============================Enemy Start=======================
*/

Enemy::Enemy() : m_HP(10)
               , m_cost(1){
}
Enemy::~Enemy() {
    m_destinationWayPoint = NULL;
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


/*	敌人函数结束
**	==============================Enemy End=======================
*/
