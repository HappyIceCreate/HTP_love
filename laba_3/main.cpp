#include <iostream>
using namespace std;

/*int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a % c == 0 && b % c == 0)
	{
		cout << (a + b) / c;
	} else if (a % c == 0 && b % c != 0) {
		cout << a / c + b;
	} else {
		cout << a - b - c;
	}
	
	return 0;
}*/

/* int main()
{
	int week_day;
	cin >> week_day;
	switch (week_day)
	{
	case 1:
		cout << "�����������";
		break;
	case 2:
	    cout << "�������";
		break;
	case 3:
	    cout << "�����";
		break;
	case 4:
		cout << "�������";
		break;
	case 5:
		cout << "�������";
		break;
	case 6:
		cout << "�������";
		break;
	case 7:
		cout << "�����������";
		break;
	
	default:
		cout << "��� ������ � ����� ������� �� ����������";
		break;
	}
	return 0;
}*/

int main()
{
	// ����� ��� �� switch, ������ ��� ��� ����� ��� ���� ������ �������� �������
	int num;
	cin >> num;
	switch (num)
	{
	case -1:
		cout << "Negative number";
		break;
	case 1:
		cout << "Positive number";
		break;
	
	default:
		cout << "Undefined number";
		break;
	}
	return 0;
}
