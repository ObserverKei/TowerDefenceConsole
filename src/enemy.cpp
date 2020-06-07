#include "public.h"
#include "event.h"
#include "map.h"
#include "enemy.h"

/*	敌人函数开始
**	==============================Enemy Start=======================
*/

Enemy::Enemy() : m_HP(9)
               , m_cost(1){
}
Enemy::~Enemy() {
    m_destinationWayPoint = NULL;
}

/* 在地图构建敌人 */
void Enemy::Create(Map &map)
{
    /* 保存敌人横坐标和纵坐标，这个可以写到构造函数里面 */
    this->m_x = 2;
    this->m_y = 0;
    /* 在地图中构建敌人 */
    map.SetCh(this->m_x, this->m_y, __MAP_CH_ENEMY__);
    /* 在事件的敌人列表中加入敌人的链接 */
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

/* 获取敌人HP */
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


/*	敌人函数结束
**	==============================Enemy End=======================
*/
