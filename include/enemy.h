#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public QObject
{
public:
    struct Point{
        int x;
        int y;
    };
public:
    Enemy();
    ~Enemy();
    /* �����ֶ� */
    /* virtual */
    void Attack(void);
    /* ���ֹ����ֶ� */
    /* Ⱥ�幥���� */
    /* ���幥���� */
/* �ƶ� */
    void Move(Map &map);
    /*���Ƶ���*/
    void Draw(Map &map);

// �����ƶ��ĺ���
public:
    Enemy(Enemy::Point pos);

    void setNextWayPoint(Enemy *nextPoint);
    Enemy* nextWayPoint() const;
    const Enemy::Point pos() const;
private:
        /* �������� */
    int m_type;				/* �������� */
        /* �ٶȿ������� */
        /* �߷��������� */
        /* ��Ѫ�������� */
    int m_moveSpeed;		/* �ƶ��ٶ� */
    int m_defense;			/* ���� */
    int m_HP;				/* Ѫ�� */
    /* ����������� */
    int m_Flags;
    /* ˮ���� */
    /* ������ */
    int m_cost;			/* ����������� */
    Enemy::Point       m_pos;
    Enemy *		m_destinationWayPoint;
    Enemy *     startWayPoint;
    // �����ƶ��ĺ���
private:
    Enemy::Point		_pos;
    Enemy *			_nextWayPoint;
};

#endif // ENEMY_H
