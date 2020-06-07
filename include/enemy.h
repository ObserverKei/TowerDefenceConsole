#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public QObject
{
public:
    struct Point{
        size_t x;
        size_t y;
    };
public:
    Enemy();
    ~Enemy();
    /* 攻击手段 */
    /* 获取敌人HP */
    int GetHP(void);
    /* virtual */
    void Attack(void);
        /* 多种攻击手段 */
        /* 群体攻击塔 */
        /* 单体攻击塔 */
    /* 在地图构建敌人 */
    void Create(Map &map);
    /* 移动 */
    void Move(Map &map);
    /*绘制敌人*/
    void Draw(Map &map);

// 敌人移动的航线
public:
    Enemy(Enemy::Point pos);

    void setNextWayPoint(Enemy *nextPoint);
    Enemy* nextWayPoint() const;
    const Enemy::Point pos() const;
private:
    /* 敌人横坐标 */
    int m_x;
    /* 敌人纵坐标 */
    int m_y;
        /* 三种类型 */
    int m_type;				/* 敌人类型 */
        /* 速度快其他弱 */
        /* 高防御其他弱 */
        /* 高血条其他弱 */
    int m_moveSpeed;		/* 移动速度 */
    int m_defense;			/* 防御 */
    int m_HP;				/* 血条 */
    /* 敌人属性组合 */
    int m_Flags;
    /* 水属性 */
    /* 火属性 */
    int m_cost;			/* 死亡奖励金币 */
    Enemy::Point       m_pos;
    Enemy *		m_destinationWayPoint;
    Enemy *     startWayPoint;
    // 敌人移动的航线
private:
    Enemy::Point		_pos;
    Enemy *			_nextWayPoint;
};

#endif // ENEMY_H
