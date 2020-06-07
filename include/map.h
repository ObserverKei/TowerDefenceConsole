#ifndef MAP_H
#define MAP_H

/* 地图: */
class Map
{
public:
	Map();
	~Map();
	/* 两个地图 */
	/* virtual */
	void Show(void);	/* 构建地图 */
    /* 获取地图横坐标边界 */
    size_t GetMapMaxX(void);
    /* 获取地图纵坐标边界 */
    size_t GetMapMaxY(void);
	/* 修改地图数据 */
    void SetCh(size_t x, size_t y, char ch);
    char GetCh(size_t x, size_t y);
    /* 新塔数据加入塔列表 */
    void InsertTower(size_t x, size_t y, Tower &tower);
    /* 获取当前位置的塔 */
    Tower *GetCurTower(size_t x, size_t y);
    /* 从塔列表移除塔 */
    void EraseTower(size_t x, size_t y);
    /* 获取塔HP */
    int GetTowerHP(string place);
    /* 获取敌人剩余构建个数,并使剩余个数减1 */
    int GetEnemyResidueNum(void);
    /* 新的敌人数据加入敌人列表 */
    void InsertEnemy(size_t x, size_t y, Enemy &enemy);
    /* 获取当前位置的敌人 */
    Enemy *GetCurEnemy(size_t x, size_t y);
    /* 从敌人列表移除敌人 */
    void EraseEnemy(size_t x, size_t y);
private:
    /* 方阵地图 */
    char m_map[__MAP_X_LEN__][__MAP_Y_LEN__];
    /* 敌人最大个数 */
    int m_enemyMaxNum;
    /* 敌人路径 */
    int m_path[2 * __MAP_X_LEN__][2];
	/* 防御塔可安装位置 */
	int m_emptyPlace[__MAP_X_LEN__][__MAP_Y_LEN__];
    /* 塔列表 */
    map<string, Tower *> m_towerList;
    /* 敌人列表 */
    map<string, Enemy *> m_enemyList;
};

#endif // MAP_H
