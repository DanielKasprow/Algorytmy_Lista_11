#include <iostream>
#include <conio.h>

using namespace std;

int sz[24][24]; int m, n, mn_1,xx=1,yy=1,xxx=1,yyy=1;
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

void init();
void drukujdroge();

void skocz(int x, int y, int nr) {
	if (sz[x][y] == -1) {
		if (xx == xxx & yy == yyy && nr == 0){}
		else
			sz[x][y] = nr;
		if (nr == mn_1 && xxx + 1 == x && yyy + 1 == y)
			drukujdroge();
		for (int i = 0; i < 8; i++)
			skocz(x + dx[i], y + dy[i], nr + 1);
		sz[x][y] = -1;
	}
}

void init() {
	int i, j;
	cout << "Podaj wysokosc planszy: ";
	cin >> n;
	cout << "Podaj szerokosc planszy: ";
	cin >> m;
	cout << "Podaj miejsce poczatkowe(wysokosc): ";
	cin >> yy;
	cout << "Podaj miejsce poczatkowe(szerokosc): ";
	cin >> xx;
	cout << "Podaj miejsce koncowe(wysokosc): ";
	cin >> yyy;
	cout << "Podaj miejsce koncowe(szerokosc): ";
	cin >> xxx;
	mn_1 = m * n -1;

	for (i = 0; i < m + 4; i++)
		for (j = 0; j < n + 4; j++)
			sz[i][j] = -2;
	for (i = 2; i < m + 2; i++)
		for (j = 2; j < n + 2; j++)
			sz[i][j] = -1;

	if (xx == xxx & yy == yyy)
	{
		mn_1 += 1;
	}
}

void drukujdroge() {
	cout << "Rozwiazanie :\n";
	for (int i = 2; i < n + 2; i++) {
		for (int j = 2; j < m + 2; j++) 
		{
			cout.width(3);
			cout << sz[j][i];
		}
		cout << "\n";
	}
	cout << "Nacisnij \n";
	_getch();
}

int main() 
{
	init();
	skocz(xx + 1,yy + 1, 0);
	cout << "KONIEC";
	_getch();
	return 0;
}