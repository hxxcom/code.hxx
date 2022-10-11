#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10) //���s1~s10�������£���������
			{
				if(Count<4)  //����������С��4
				{
				Password*=10;		//��������һλ
				Password+=KeyNum%10;    //��ȡһλ����
				}
				Count++;   //�ƴμ�һ
				LCD_ShowNum(2,1,Password,4);		//������ʾ
			}
			
			if(KeyNum==11) //������°���s11��ȷ��
			{
				if(Password==2345) //�������Ϊ2345��ȷ����
				{
					LCD_ShowString(1,14,"OK");  //��ʾOK
					Password=0;  //��������
					Count=0;		//�ƴ�����
					LCD_ShowNum(2,1,Password,4);		//������ʾ
				}
				else		//����
				{
					LCD_ShowString(1,14,"ERR");		//��ʾERR
					Password=0;  //��������
					Count=0;		//�ƴ�����
					LCD_ShowNum(2,1,Password,4);		//������ʾ
				}
			}
			if(KeyNum==12)  //�������s12��ȡ������
			{
				Password=0;  //��������
				Count=0;		//�ƴ�����
				LCD_ShowNum(2,1,Password,4);		//������ʾ	
			}
			
		}
	}
}