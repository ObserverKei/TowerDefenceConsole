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
    /* �����ֶ� */
    /* ��ȡ����HP */
    int GetHP(void);
    /* virtual */
    void Attack(void);
        /* ���ֹ����ֶ� */
        /* Ⱥ�幥���� */
        /* ���幥���� */
    /* �ڵ�ͼ�������� */
    void Create(Map &map);
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
    /* ���˺����� */
    int m_x;
    /* ���������� */
    int m_y;
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
