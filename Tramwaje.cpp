#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, a, x;
    bool z;
    vector<int> v;
    stack<int> s;
    queue<int> q;
    vector<string> odp;
    cin >> n >> a;
    for (int i = 0; i < a; i++) {
        while (s.size() > 0) {
            s.pop();
        }
        v.clear();
        for (int j = 0; j < n; j++) {
            cin >> x;
            v.push_back(x);
            q.push(j+1);
        }
        for (int j = 0; j < n; j++) {
            z = true;
            while (z == true) {
                if (s.empty() == false && v[j] == s.top()) {
                     s.pop();
                     z = false;
                }
                else if (q.empty() == false && v[j] != q.front()) {
                    s.push(q.front());
                    q.pop();
                }
                else if (q.empty() == false && v[j] == q.front()) {
                    z = false;
                    q.pop();
                }
                else {
                    z = false;
                    j = n;
                    odp.push_back("NIE");
                }
            }
        }
        if (q.empty() == true && s.empty() == true) {
            odp.push_back("TAK");
        }
    }
    for (int i = 0; i < odp.size(); i++) {
        cout << odp[i] << endl;
    }

}

//polecenie zad:
/*XVII Tydzień Informatyki, dzień pierwszy. Dostępna pamięć: 32 MB 09.10.2023
W IKArii na północy miasta znajduje się tor krańcowy. Nie było miejsca na wybudowanie pełnej pętli, dlatego
tramwaje wjeżdżają na jeden tor i na nim zmieniają kierunek ruchu wracając na trasę. Na torze za każdym
razem tramwaj zmienia kierunek jazdy (patrz rysunek).
Tramwaje muszą zgodnie z rozkładem opuszczać tor z określoną kolejnością. N tramwajów przyjeżdża
z kierunku A w kolejności linii od 1 do N. Kierownik musi wiedzieć, czy można tak przestawić tramwaje, żeby
po opuszczeniu toru w kierunku B linie tramwajowe były ustawione w kolejności a1,...,aN.

Napisz program, który zdecyduje, czy można osiągnąć wymaganą kolejność linii tramwajowych. Możesz
założyć, że:
• tramwaj może wjeżdżać od razu na tor w kierunku B,
• w każdej chwili na stacji może się znajdować dowolnie wiele tramwajów,
• każdy tramwaj, który wjechał na tor krańcowy, nie może wrócić na tor w kierunku A, jak również każdy
wagon, który opuścił tor krańcowy w kierunku B, nie może z powrotem na nią wjechać.

Wejście
Pierwszy wiersz wejścia zawiera dwie liczby całkowite N i M, (1 ≤ N,M ≤ 1000) oddzielone pojedynczym
odstępem. Każdy z następnych M wierszy zawiera N liczb całkowitych ai,...,aN pooddzielanych pojedynczymi
odstępami.

Wyjście
Każdy z M wierszy wyjścia powinien zawierać jedno słowo TAK lub NIE. Są to odpowiedzi dla kolejnych
sposobów organizacji podanych na wejściu.

Przykład
Wejście
5 2
1 2 3 5 4
5 4 1 2 3

Wyjście
TAK
NIE
All of the commented text is a assignment content from XVII Tydzień Informatyki in 8LO in Poznań
*/