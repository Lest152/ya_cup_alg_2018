#include <iostream>

using namespace std;

struct timeClock
{
	int h=0;
	int m=0;
};

timeClock& mirrorTime(int h, int m)
{
	timeClock t;

	if ((h < 0 || h > 11)
		&&
		(m < 0 || m > 59)
		)
		return t;

	t.h = h > 0 ? 12 - h : 0;
	t.m = m > 0 ? 60 - m : 0;

	return t;
}

int main()
{
	int h, m;

	cout << "Input time: ";
	cin >> h >> m;

	auto [x, y] = mirrorTime(h, m);
	
	cout << "Current time: " << x << ' ' << y << endl;
}