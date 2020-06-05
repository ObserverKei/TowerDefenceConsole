#ifndef EVENT_H
#define EVENT_H

/* �����¼���*/
class Event
{
public:
	Event();
	~Event();
	/* ��Ϸ�����л� */
	void SceneChange(int scene);
        /* ���볡�������л� */
    /* ��Ϸ�Ѷ�����Ϸ���Ȳ������� */
	void AddDifficulty(void);
        /* �Ѷ����Ӻ��� */
        /* ���֣� */
        /* 1 ���˷������� */
        /* 2 �����ƶ��ٶ����� */
        /* 3 ���˹��������� */
    /* ����̨֧�ֺ��������ڵ��� */
    /* �������� */
	char Input(void);
	/* ���ý����ƶ� */
	void SetFucus(char key);
    /* ��������� */
    size_t GetXFocus(void);
    /* ���������� */
    size_t GetYFocus(void);
    /* �û�Ѫ�� */
    int GetUsrHP(void);
    /* �û���� */
    int GetUsrCost(void);
    /* ������ҽ�� */
    int SubUsrCost(int cost);
    /* ���ӽ�� */
    void AddUsrCost(int cost);
private:
	/* �������� */
	char *m_bgm;	/* ���bgm·�� */
	/* �¼���Ч */
	char *m_tone;  /* ����¼���Ч·�� */
	/* ѡ�񽹵� */
    size_t m_focus[2];
    /* ��ҽ�� */
    int m_usrCost;
    /* ���Ѫ�� */
    int m_usrHP;
};

#endif // EVENT_H
