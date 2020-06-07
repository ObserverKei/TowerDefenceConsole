#include "public.h"
#include "event.h"
#include "map.h"
#include "tower.h"


/*	防御塔函数开始
**	==============================Tower Start=======================
*/
/* 需要注意初始化列表要和定义顺序一致，否则QT会报错 */
Tower::Tower() : m_cost(2), m_HP(9) {
}
Tower::~Tower() {
}
/* 获取塔HP */
int Tower::GetHP(void){
    return m_HP;
}
/* 获取塔价值 */
int Tower::GetCost(void){
    return m_cost;
}

/* 拆除防御塔 */
void Tower::Dismantle(Map &map) {
    /* 拆除塔回复一半金额 */
    gConsoleEvent.AddUsrCost(m_cost/2);
    /* 在地图中擦除塔 */
    map.SetCh(this->m_x, this->m_y, __MAP_CH_EMPTY__);
    /* 从地图塔列表中擦除塔 */
    map.EraseTower(this->m_x, this->m_y);
    /* 销毁塔 */
    delete this;
}

/*	名称：	建造防御塔
**	功能：	在地图 map 的焦点 m_focus 处生成防御塔 __MAP_CH_TOWER__
**	传参：	Map &map;	地图类
**	返回：	无
*/
int Tower::Build(Map &map) {
    /* 如果焦点不为空 */
    if (__MAP_CH_EMPTY__ != map.GetCh(gConsoleEvent.GetXFocus(), gConsoleEvent.GetYFocus()))
    {
        /* 不能在非空地方建塔 */
        return -1;
    }
    /* 玩家建造塔，金额减少 */
    int Ret = gConsoleEvent.SubUsrCost(m_cost);
    /* 如果玩家没钱了 */
    if (Ret < 0)
    {
        /* 金额不足 */
        return -1;
    }
    /* 保存塔横坐标和纵坐标 */
    this->m_x = gConsoleEvent.GetXFocus();
    this->m_y = gConsoleEvent.GetYFocus();
    /* 在地图中建造塔 */
	map.SetCh(gConsoleEvent.GetXFocus(), gConsoleEvent.GetYFocus(), __MAP_CH_TOWER__);
    /* 在事件的塔列表中加入塔的链接 */
    map.InsertTower(this->m_x, this->m_y, *this);

    return 0;
}
/*	防御塔函数结束
**	==============================Tower End=======================
*/
