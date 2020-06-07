#ifndef TOWER_H
#define TOWER_H

/* 防御塔 */
class Tower
{
public:
	Tower();
	~Tower();
	/* 建造防御塔 */
	/* virtual */
    int Build(Map &map);
	/* 拆除防御塔 */
    void Dismantle(Map &map);
	/* 三种类型 */
	/* virtual */
	void Attack(void);
		/* 单人攻击 */
		/* 多人攻击 */
        /* 回复塔   */
		/* 使用属性进行攻击 */
    /* 获取塔HP */
    int GetHP(void);
    /* 获取塔价值 */
    int GetCost(void);
private:
	int m_type;			/* 防御塔类型 */
	/* 单人攻击 */
	/* 多人攻击 */
	/* 回复塔   */
	/* 两种攻击属性 */
	int m_attackFlags;
	/* 水属性 */
	/* 火属性 */
	/* 三种升级功能     */
	int m_attackPower;	/* 升级攻击力 */
	int m_attackSpeed;	/* 升级攻击速度 */
	int m_attackRange;	/* 升级攻击范围 */
	int m_cost;			/* 防御塔价值金币 */
    int m_HP;			/* 防御塔血条 */
    size_t m_x;            /* 防御塔横坐标 */
    size_t m_y;            /* 防御塔纵坐标 */
};

#endif // TOWER_H
