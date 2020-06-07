#include "public.h"
#include "tower.h"
#include "enemy.h"
#include "event.h"

Event gConsoleEvent;

/*	�����¼�������ʼ
**	==============================Event Start=======================
*/
Event::Event() :m_usrCost(20), m_usrHP(10) {
}
Event::~Event() {
}
/* ��Ϸ�����л� */
void Event::SceneChange(int scene) {
    scene++;
}
/* ��Ϸ�Ѷ�����Ϸ���Ȳ������� */
void Event::AddDifficulty(void) {
}
/* ��������� */
size_t Event::GetXFocus(void) {
	return m_focus[0]; 
}
/* ���������� */
size_t Event::GetYFocus(void) {
	return m_focus[1]; 
}
/* �û�Ѫ�� */
int Event::GetUsrHP(void){
    return m_usrHP;
}
/* �û���� */
int Event::GetUsrCost(void){
    return m_usrCost;
}
/* ������ҽ�� */
int Event::SubUsrCost(int cost){
    /* ����û�����㹻 */
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

/* ���ӽ�� */
void Event::AddUsrCost(int cost){
    m_usrCost += cost;
}

/*	���ƣ�	����̨������ƺ��� 
**	���ܣ�	�ڿ���̨����һ����������
**	���Σ�	��
**	���أ�	�������ĵ��� char �ַ�
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

	/* �����λ */
    for (size_t i = 0; i < sizeof(key_s::key_code) / sizeof(key_s::key_code[0]); ++i)
	{
		/* ���������� */
		if (_kbhit())
		{
			str[i] = _getch();
		}
	}
	/* �жϼ�λ */
    for (size_t i = 0; i < sizeof(key) / sizeof(key[0]); ++i)
	{
		if ((!memcmp(str, key[i].key_code, sizeof(key_s::key_code))))
		{
			return key[i].key;
		}
	}
	return 0;
}

/*	���ƣ�	����̨�������ú��� 
**	���ܣ�	ͨ�����ε� key ������������ m_focus 
**	���Σ�	char key;	Input����������ַ�
**	���أ�	��
*/
void Event::SetFucus(char key)
{
	switch (key)
	{/* �ƶ����� */
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
/*	�����¼���������
**	==============================Event End=======================
*/
