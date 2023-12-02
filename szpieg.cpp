#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	unsigned long long x;
	unsigned long long n;
	bool z;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		 if (x < 10) {
			 string p = "";
			 p += "1";
			 p += char(48 + x);
			v.push_back(p);
		}
		else {
			 int tab[10]{};
			z = false;
			unsigned long long a = 2;
			while (x > 1) {
				if (a > 7) {
					x = 1;
					z = true;
				}
				if (x % a == 0) {
					tab[a]++;
					x /= a;
				}
				else {
					a++;
				}
			}
			if (z == true) {
				v.push_back("0");
			}
			else {
				int j = 0;
				string w = "";
				if (tab[3] >= 2) {
					tab[9] = tab[3] / 2;
					tab[3] %= 2;
				}
				if (tab[2] >= 3) {
					tab[8] = tab[2] / 3;
					tab[2] %= 3;
				}
				if (tab[2] > 0 && tab[3] == 1) {
					tab[6]++;
					tab[2]--;
					tab[3]--;
				}
				if (tab[2] > 1) {
					tab[4] = tab[2] / 2;
					tab[2] %= 2;
				}
				while (j!=10) {
					if (tab[j] > 0) {
						w += char(48 + j);
						tab[j]--;
					}
					else {
						j++;
					}
				}
				v.push_back(w);
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
/*XVII Tydzień Informatyki, dzień trzeci. Dostępna pamięć: 32 MB 11.10.2023
Szpieg krainy Deszczowców miał wyszpiegować Niezwykle Poufne Wiadomości (NPW) i dostał listę kryjówek, gdzie
ma je pozostawić. Kryjówki zostały ponumerowane w dość specyficzny sposób. Każda kryjówka ma przyznany numer y.
Aby nie wysyłać jawnie tego numeru, zamiast niego wysłano liczbę x. Aby z liczby x odczytać właściwy numer kryjówki
czyli y należy znaleźć najmniejszą dodatnią liczbę y, taką, że iloczyn cyfr liczby y w zapisie dziesiętnym wynosi x. Czasem
dla niepoznaki kontrwywiadu wstawiono taką liczbę x, że nie posiada ona swojego odpowiednika w postaci y. Pomóż
odszyfrować numery kryjówek.

Wejście
W pierwszym wierszu dana jest liczba całkowita n oznaczająca ilość numerów kryjówek, 1 <= n <= 1000. W następnych
wierszach podane są kolejne numery. W kolejnych wierszach znajduje się jedna liczba x, 0 <= x <= 2 * 109
, tworząca i-ty
numer kryjówki.

Wyjście
Twój program powinien wypisać n liczb, każdą w osobnym wierszu. Liczba w wierszu i powinna być odkodowanym
i numerem kryjówki (y). Dla każdego z numerów sprawdź czy istnieje liczba y spełniająca warunki zadania i jeśli taka
liczba istnieje to wypisz ją, a jeśli taka liczba nie istnieje to wypisz 0. Każda liczba – numer kryjówki – ma minimalnie 2
cyfry.

Przykład
Wejście
2
10
11
Wyjście
25
0
All of the commented text is an assignment content from XVII Tydzień Informatyki in 8LO in Poznań
*/