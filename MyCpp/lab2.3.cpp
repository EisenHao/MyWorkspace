#include <iostream>
using namespace std;

//���㲻ͬͼ�ε����

const float PI = 3.1416;

int Sw_deal(int iType){
	float radius, a, b, area;
	switch(iType)
	{
		case 1:
			cout << "Բ�İ뾶Ϊ��";
			cin >> radius;
			area = PI * radius * radius;
			cout<<"���Ϊ��"<<area<<endl;
			break;
		case 2:
			cout << "���εĳ�Ϊ��";
			cin >> a;
			cout << "���εĿ�Ϊ��";
			cin >> b;
			area = a * b;
				cout<<"���Ϊ��"<<area<<endl;
			break;
		case 3:
			cout << "�����εı߳�Ϊ��";
			cin >> a;
			area = a * a;
				cout<<"���Ϊ��"<<area<<endl;
			break;
		default:
			cout << "���ǺϷ�������ֵ,����������!"<<endl;
			return 0;
	}
	return 1;
}

int main(void)
{
	int iType;
	
	cout << "ͼ�ε�����Ϊ?(1-Բ�� 2-������ 3-������):";
	cin >> iType;
	while(Sw_deal(iType)==0){
		cout << "ͼ�ε�����Ϊ?(1-Բ�� 2-������ 3-������):";
		cin >> iType;
	}
	return 0;
}
