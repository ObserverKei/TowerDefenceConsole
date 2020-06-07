#ifndef MAP_H
#define MAP_H

/* ��ͼ: */
class Map
{
public:
	Map();
	~Map();
	/* ������ͼ */
	/* virtual */
	void Show(void);	/* ������ͼ */
    /* ��ȡ��ͼ������߽� */
    size_t GetMapMaxX(void);
    /* ��ȡ��ͼ������߽� */
    size_t GetMapMaxY(void);
	/* �޸ĵ�ͼ���� */
    void SetCh(size_t x, size_t y, char ch);
    char GetCh(size_t x, size_t y);
    /* �������ݼ������б� */
    void InsertTower(size_t x, size_t y, Tower &tower);
    /* ��ȡ��ǰλ�õ��� */
    Tower *GetCurTower(size_t x, size_t y);
    /* �����б��Ƴ��� */
    void EraseTower(size_t x, size_t y);
    /* ��ȡ��HP */
    int GetTowerHP(string place);
    /* ��ȡ����ʣ�๹������,��ʹʣ�������1 */
    int GetEnemyResidueNum(void);
    /* �µĵ������ݼ�������б� */
    void InsertEnemy(size_t x, size_t y, Enemy &enemy);
    /* ��ȡ��ǰλ�õĵ��� */
    Enemy *GetCurEnemy(size_t x, size_t y);
    /* �ӵ����б��Ƴ����� */
    void EraseEnemy(size_t x, size_t y);
private:
    /* �����ͼ */
    char m_map[__MAP_X_LEN__][__MAP_Y_LEN__];
    /* ���������� */
    int m_enemyMaxNum;
    /* ����·�� */
    int m_path[2 * __MAP_X_LEN__][2];
	/* �������ɰ�װλ�� */
	int m_emptyPlace[__MAP_X_LEN__][__MAP_Y_LEN__];
    /* ���б� */
    map<string, Tower *> m_towerList;
    /* �����б� */
    map<string, Enemy *> m_enemyList;
};

#endif // MAP_H
