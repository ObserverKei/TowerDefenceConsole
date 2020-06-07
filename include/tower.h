#ifndef TOWER_H
#define TOWER_H

/* ������ */
class Tower
{
public:
	Tower();
	~Tower();
	/* ��������� */
	/* virtual */
    int Build(Map &map);
	/* ��������� */
    void Dismantle(Map &map);
	/* �������� */
	/* virtual */
	void Attack(void);
		/* ���˹��� */
		/* ���˹��� */
        /* �ظ���   */
		/* ʹ�����Խ��й��� */
    /* ��ȡ��HP */
    int GetHP(void);
    /* ��ȡ����ֵ */
    int GetCost(void);
private:
	int m_type;			/* ���������� */
	/* ���˹��� */
	/* ���˹��� */
	/* �ظ���   */
	/* ���ֹ������� */
	int m_attackFlags;
	/* ˮ���� */
	/* ������ */
	/* ������������     */
	int m_attackPower;	/* ���������� */
	int m_attackSpeed;	/* ���������ٶ� */
	int m_attackRange;	/* ����������Χ */
	int m_cost;			/* ��������ֵ��� */
    int m_HP;			/* ������Ѫ�� */
    size_t m_x;            /* ������������ */
    size_t m_y;            /* ������������ */
};

#endif // TOWER_H
