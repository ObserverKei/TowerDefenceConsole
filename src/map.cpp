#include "public.h"
#include "event.h"
#include "tower.h"
#include "map.h"

/*	地图函数开始
**	==============================Map Start=======================
*/
Map::Map() : m_map{0}, m_enemyMaxNum(20) {
}
Map::~Map() {
}
/* 获取地图横坐标边界 */
size_t Map::GetMapMaxX(void) {
    return __MAP_X_LEN__;
}
/* 获取地图纵坐标边界 */
size_t Map::GetMapMaxY(void){
    return __MAP_Y_LEN__;
}
/* 获取敌人剩余构建个数,并使剩余个数减1 */
int Map::GetEnemyResidueNum(void)
{
    if (m_enemyMaxNum > 0)
    {
        /* 返回剩余个数并让剩余敌人构建个数减少1 */
        return m_enemyMaxNum--;
    }
    else
    {
        /* 已经不能再构建敌人了 */
        return m_enemyMaxNum;
    }
}

/*	名称：	修改地图某一位置数据
**	功能：	在地图 m_map[x][y] 写入字符 ch
**	传参：	int x;
**			int y;		
**			char ch;	写入字符
**	返回：	无
*/
void Map::SetCh(size_t x, size_t y, char ch)
{
	m_map[x][y] = ch;
}
/*	名称：	获取地图某一位置数据
**	功能：	获取地图 m_map[x][y] 
**	传参：	int x;
**			int y;
**	返回：	char 类型 地图这一位置数据
*/
char Map::GetCh(size_t x, size_t y)
{
	return m_map[x][y];
}

/* 把塔加入列表 */
void Map::InsertTower(size_t x, size_t y, Tower &tower){
    string tmpPlace(to_string(x) + "," + to_string(y));
    /* 把塔插入位置 */
    m_towerList[tmpPlace] = &tower;
}

/* 获取当前位置的塔 */
Tower *Map::GetCurTower(size_t x, size_t y){
    string tmpPlace(to_string(x) + "," + to_string(y));
    /* 返回当前位置的塔 */
    return m_towerList[tmpPlace];
}

/* 从塔列表移除塔 */
void Map::EraseTower(size_t x, size_t y){
    string tmpPlace(to_string(x) + "," + to_string(y));
    /* 从塔列表移除塔 */
    m_towerList.erase(tmpPlace);
}

/* 返回塔HP */
int Map::GetTowerHP(string place) {
    return m_towerList[place]->GetHP();
}

/*	名称：	控制台调试地图 
**	功能：	在控制台打印地图 m_map 的内容
**	传参：	无
**	返回：	无
*/
void Map::Show(void)
{
    for (size_t i = 0; i < __MAP_X_LEN__; ++i)
	{
		printf("==");
	}
	printf("\n");

    for (size_t y = 0; y < __MAP_Y_LEN__; ++y)
	{
        for (size_t x = 0; x < __MAP_X_LEN__; ++x)
		{
			/* 如果是焦点位置就显示焦点!
			 * */
			bool flag = false;
			if ((x == gConsoleEvent.GetXFocus()) && (y == gConsoleEvent.GetYFocus()))
			{
				printf("! ");
				flag = true;
			}
			if (false == flag)
			{/* 不是焦点就显示其他的 */
				if (__MAP_CH_EMPTY__ == m_map[x][y])
                {   /* 如果是空，就什么也不做 */
					printf("  ");
				}
                else if (__MAP_CH_TOWER__ == m_map[x][y])
				{
                    /* 如果是塔，在这里进行操作 */
                    /* 拼接当前位置信息 */
                    string tmpPlace(to_string(x) + "," + to_string(y));
                    /* 获取当前塔HP */
                    int currentTowerHP = this->GetTowerHP(tmpPlace);
                    if (currentTowerHP > 0)
                    {
                        printf("%c%d", m_map[x][y], currentTowerHP);
                    }
                    else
                    {
                        /* 出现错误，没有塔HP */
                        printf("??");
                    }
                }// end of else if
                else if (__MAP_CH_ENEMY__ == m_map[x][y])
                {
                    int currentTowerHP = 9;
                    /* 这里有什么 */
                    printf("%c%d", m_map[x][y], currentTowerHP);

                    /* 如果是敌人，在这里进行操作 */

                    /* 确定下一步要走哪里，
                     * 这里需要思考是一个一个走，
                     * 还是按照之前计算好的路径走，
                     * 如果计算路径，
                     * 那么再这里可能也得重新计算路径 */

                    /* 清除当前位置 */

                    /* 走下一步 */

                }
                else
                {
					printf("%c ", m_map[x][y]);
                }
            }// end of if
        }// end of for
		putchar('\n');
    }// end of for
    for (size_t i = 0; i < __MAP_X_LEN__; ++i)
	{
		printf("==");
	}
	printf("\n");

	/* 提示菜单 */   
    printf("←↑↓→\t控制移动\n");
	printf("!\t\t控制焦点\n");
	printf("T\t\t安装防御塔\n");
    printf("D\t\t拆除防御塔\n");
    printf("===============\n");
    printf("剩余生成敌人:\t%d\n", this->m_enemyMaxNum);
    printf("玩家HP:\t\t%d\n", gConsoleEvent.GetUsrHP());
    printf("玩家金额:\t%d\n", gConsoleEvent.GetUsrCost());

	return;
}
/*	地图函数结束
**	==============================Map End=======================
*/
