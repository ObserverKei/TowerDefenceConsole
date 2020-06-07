#ifndef EVENT_H
#define EVENT_H

/* 其他事件：*/
class Event
{
public:
	Event();
	~Event();
	/* 游戏场景切换 */
	void SceneChange(int scene);
        /* 传入场景进行切换 */
    /* 游戏难度随游戏进度不断增加 */
	void AddDifficulty(void);
        /* 难度增加函数 */
        /* 体现： */
        /* 1 敌人防御提升 */
        /* 2 敌人移动速度提升 */
        /* 3 敌人攻击力提升 */
    /* 控制台支持函数，用于调试 */
    /* 接受输入 */
	char Input(void);
	/* 设置焦点移动 */
	void SetFucus(char key);
    /* 焦点横坐标 */
    size_t GetXFocus(void);
    /* 焦点纵坐标 */
    size_t GetYFocus(void);
    /* 用户血条 */
    int GetUsrHP(void);
    /* 用户金额 */
    int GetUsrCost(void);
    /* 减少玩家金额 */
    int SubUsrCost(int cost);
    /* 增加金额 */
    void AddUsrCost(int cost);
private:
	/* 背景音乐 */
	char *m_bgm;	/* 存放bgm路径 */
	/* 事件音效 */
	char *m_tone;  /* 存放事件音效路径 */
	/* 选择焦点 */
    size_t m_focus[2];
    /* 玩家金额 */
    int m_usrCost;
    /* 玩家血条 */
    int m_usrHP;
};

#endif // EVENT_H
