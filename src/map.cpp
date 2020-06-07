#include "public.h"
#include "event.h"
#include "tower.h"
#include "map.h"

/*	��ͼ������ʼ
**	==============================Map Start=======================
*/
Map::Map() : m_map{0}, m_enemyMaxNum(20) {
}
Map::~Map() {
}
/* ��ȡ��ͼ������߽� */
size_t Map::GetMapMaxX(void) {
    return __MAP_X_LEN__;
}
/* ��ȡ��ͼ������߽� */
size_t Map::GetMapMaxY(void){
    return __MAP_Y_LEN__;
}
/* ��ȡ����ʣ�๹������,��ʹʣ�������1 */
int Map::GetEnemyResidueNum(void)
{
    if (m_enemyMaxNum > 0)
    {
        /* ����ʣ���������ʣ����˹�����������1 */
        return m_enemyMaxNum--;
    }
    else
    {
        /* �Ѿ������ٹ��������� */
        return m_enemyMaxNum;
    }
}

/*	���ƣ�	�޸ĵ�ͼĳһλ������
**	���ܣ�	�ڵ�ͼ m_map[x][y] д���ַ� ch
**	���Σ�	int x;
**			int y;		
**			char ch;	д���ַ�
**	���أ�	��
*/
void Map::SetCh(size_t x, size_t y, char ch)
{
	m_map[x][y] = ch;
}
/*	���ƣ�	��ȡ��ͼĳһλ������
**	���ܣ�	��ȡ��ͼ m_map[x][y] 
**	���Σ�	int x;
**			int y;
**	���أ�	char ���� ��ͼ��һλ������
*/
char Map::GetCh(size_t x, size_t y)
{
	return m_map[x][y];
}

/* ���������б� */
void Map::InsertTower(size_t x, size_t y, Tower &tower){
    string tmpPlace(to_string(x) + "," + to_string(y));
    /* ��������λ�� */
    m_towerList[tmpPlace] = &tower;
}

/* ��ȡ��ǰλ�õ��� */
Tower *Map::GetCurTower(size_t x, size_t y){
    string tmpPlace(to_string(x) + "," + to_string(y));
    /* ���ص�ǰλ�õ��� */
    return m_towerList[tmpPlace];
}

/* �����б��Ƴ��� */
void Map::EraseTower(size_t x, size_t y){
    string tmpPlace(to_string(x) + "," + to_string(y));
    /* �����б��Ƴ��� */
    m_towerList.erase(tmpPlace);
}

/* ������HP */
int Map::GetTowerHP(string place) {
    return m_towerList[place]->GetHP();
}

/*	���ƣ�	����̨���Ե�ͼ 
**	���ܣ�	�ڿ���̨��ӡ��ͼ m_map ������
**	���Σ�	��
**	���أ�	��
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
			/* ����ǽ���λ�þ���ʾ����!
			 * */
			bool flag = false;
			if ((x == gConsoleEvent.GetXFocus()) && (y == gConsoleEvent.GetYFocus()))
			{
				printf("! ");
				flag = true;
			}
			if (false == flag)
			{/* ���ǽ������ʾ������ */
				if (__MAP_CH_EMPTY__ == m_map[x][y])
                {   /* ����ǿգ���ʲôҲ���� */
					printf("  ");
				}
                else if (__MAP_CH_TOWER__ == m_map[x][y])
				{
                    /* �����������������в��� */
                    /* ƴ�ӵ�ǰλ����Ϣ */
                    string tmpPlace(to_string(x) + "," + to_string(y));
                    /* ��ȡ��ǰ��HP */
                    int currentTowerHP = this->GetTowerHP(tmpPlace);
                    if (currentTowerHP > 0)
                    {
                        printf("%c%d", m_map[x][y], currentTowerHP);
                    }
                    else
                    {
                        /* ���ִ���û����HP */
                        printf("??");
                    }
                }// end of else if
                else if (__MAP_CH_ENEMY__ == m_map[x][y])
                {
                    int currentTowerHP = 9;
                    /* ������ʲô */
                    printf("%c%d", m_map[x][y], currentTowerHP);

                    /* ����ǵ��ˣ���������в��� */

                    /* ȷ����һ��Ҫ�����
                     * ������Ҫ˼����һ��һ���ߣ�
                     * ���ǰ���֮ǰ����õ�·���ߣ�
                     * �������·����
                     * ��ô���������Ҳ�����¼���·�� */

                    /* �����ǰλ�� */

                    /* ����һ�� */

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

	/* ��ʾ�˵� */   
    printf("��������\t�����ƶ�\n");
	printf("!\t\t���ƽ���\n");
	printf("T\t\t��װ������\n");
    printf("D\t\t���������\n");
    printf("===============\n");
    printf("ʣ�����ɵ���:\t%d\n", this->m_enemyMaxNum);
    printf("���HP:\t\t%d\n", gConsoleEvent.GetUsrHP());
    printf("��ҽ��:\t%d\n", gConsoleEvent.GetUsrCost());

	return;
}
/*	��ͼ��������
**	==============================Map End=======================
*/
