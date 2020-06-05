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
    /* 数据加入塔列表 */
    void InsertTower(size_t x, size_t y, Tower &tower);
    /* 获取当前位置的塔 */
    Tower *GetCurTower(size_t x, size_t y);
    /* 从塔列表移除塔 */
    void EraseTower(size_t x, size_t y);
    /* 获取塔HP */
    int GetTowerHP(string place);
private:
	char m_map[__MAP_X_LEN__][__MAP_Y_LEN__];		/* 方阵地图 */
	int m_path[2 * __MAP_X_LEN__][2];				/* 敌人路径 */
	/* 防御塔可安装位置 */
	int m_emptyPlace[__MAP_X_LEN__][__MAP_Y_LEN__];
    /* 塔列表 */
    map<string, Tower *> m_towerList;
};

#endif // MAP_H
