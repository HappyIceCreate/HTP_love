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
		cout << "Понедельник";
		break;
	case 2:
	    cout << "Вторник";
		break;
	case 3:
	    cout << "Среда";
		break;
	case 4:
		cout << "Четверг";
		break;
	case 5:
		cout << "Пятница";
		break;
	case 6:
		cout << "Суббота";
		break;
	case 7:
		cout << "Воскресенье";
		break;
	
	default:
		cout << "Дня недели с таким номером не существует";
		break;
	}
	return 0;
}*/

int main()
{
	// Выбор пал на switch, потому что это новый для меня способ создания условий
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
