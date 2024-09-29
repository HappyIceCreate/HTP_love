#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, v;
	cin >> a >> b >> c;
	if ((a > 0 && b > 0 && c > 0) && (a < pow(10, 4) && b < pow(10, 4) && c < pow(10, 4))){
		v = a * b * c;
		cout << v;
	}
	return 0;
}