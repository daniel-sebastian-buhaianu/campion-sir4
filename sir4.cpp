#include <fstream>
#define NMAX 100
using namespace std;
ofstream g("sir4.out");
bool uz[NMAX];
int a[NMAX], k, n;
void citire();
void afisare();
void sortare();
int main()
{
	citire();
	bool ok;
	do
	{
		ok = 0;
		int p = k*k;
		int cs = p/100%10; 
		int cz = p/10%10;
		k = cs*10 + cz;
		if (!uz[k])
		{
			a[n++] = k;
			ok = uz[k] = 1;
		}
	} while (ok);
	afisare();
	sortare();
	afisare();
	g.close();
	return 0;
}
void sortare()
{
	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
		{
			int c1 = a[i] < 10 ? a[i] : a[i]/10;
			int c2 = a[j] < 10 ? a[j] : a[j]/10;
			if (c1 > c2)
				swap(a[i], a[j]);
		}
}
void afisare()
{
	for (int i = 0; i < n; i++)
		g << a[i] << ' ';
	g << '\n';
}
void citire()
{
	ifstream f("sir4.in");
	f >> k;
	f.close();
}
