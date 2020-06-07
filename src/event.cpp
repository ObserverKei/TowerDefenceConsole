#include "public.h"
#include "tower.h"
#include "enemy.h"
#include "event.h"

Event gConsoleEvent;

/*	其他事件函数开始
**	==============================Event Start=======================
*/
Event::Event() :m_usrCost(20), m_usrHP(10) {
}
Event::~Event() {
}
/* 游戏场景切换 */
void Event::SceneChange(int scene) {
    scene++;
}
/* 游戏难度随游戏进度不断增加 */
void Event::AddDifficulty(void) {
}
/* 焦点横坐标 */
size_t Event::GetXFocus(void) {
	return m_focus[0]; 
}
/* 焦点纵坐标 */
size_t Event::GetYFocus(void) {
	return m_focus[1]; 
}
/* 用户血条 */
int Event::GetUsrHP(void){
    return m_usrHP;
}
/* 用户金额 */
int Event::GetUsrCost(void){
    return m_usrCost;
}
/* 减少玩家金额 */
int Event::SubUsrCost(int cost){
    /* 如果用户金额足够 */
    if ((m_usrCost - cost) >= 0)
    {
        m_usrCost -= cost;
        return 0;
    }
    else
    {
        return -1;
    }
}

/* 增加金额 */
void Event::AddUsrCost(int cost){
    m_usrCost += cost;
}

/*	名称：	控制台输入控制函数 
**	功能：	在控制台接收一个按键输入
**	传参：	无
**	返回：	代表按键的单个 char 字符
*/
char Event::Input(void)
{
	int str[2] = { 0 };
	struct key_s
	{
		char key;
		int key_code[2];
	}key[] = {
		{'u', {224, 72}},	/* Up */
		{'d', {224, 80}},	/* Down */
		{'l', {224, 75}},	/* Left */
		{'r', {224, 77}},	/* Right */
		{'T', {'T',}},		/* T */
        {'T', {'t',}},		/* t */
        {'D', {'D',}},      /* D */
        {'D', {'d',}},      /* d */
	};

	/* 输入键位 */
    for (size_t i = 0; i < sizeof(key_s::key_code) / sizeof(key_s::key_code[0]); ++i)
	{
		/* 非阻塞输入 */
		if (_kbhit())
		{
			str[i] = _getch();
		}
	}
	/* 判断键位 */
    for (size_t i = 0; i < sizeof(key) / sizeof(key[0]); ++i)
	{
		if ((!memcmp(str, key[i].key_code, sizeof(key_s::key_code))))
		{
			return key[i].key;
		}
	}
	return 0;
}

/*	名称：	控制台焦点设置函数 
**	功能：	通过传参的 key 操作焦点坐标 m_focus 
**	传参：	char key;	Input的输出代表字符
**	返回：	无
*/
void Event::SetFucus(char key)
{
	switch (key)
	{/* 移动焦点 */
	case 'u': {
		if (m_focus[1] > 0)
		{
			m_focus[1]--;
		}
		break;
	}
	case 'd': {
		if (m_focus[1] < __MAP_Y_LEN__-1)
		{
			m_focus[1]++;
		}
		break;
	}
	case 'l': {
		if (m_focus[0] > 0)
		{
			m_focus[0]--;
		}
		break;
	}
	case 'r': {
		if (m_focus[0] < __MAP_X_LEN__-1)
		{
			m_focus[0]++;
		}
		break;
	}
	}
	return;
}
/*	其他事件函数结束
**	==============================Event End=======================
*/
