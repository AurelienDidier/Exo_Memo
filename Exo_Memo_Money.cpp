#include <iostream>
#include <vector>
#include <array>

using namespace std;

static vector<array<int, 4>> memo;
static array<int, 4> moneyValues { 1, 4, 6, 11 };

int somme(array<int, 4> tab) {
	int somme = 0;
	for (int i = 0; i < 4; i++) {
		somme += tab[i];
	}
	return somme;
}

int money(int n) {
	const array<int, 4> initTab { 0, 0, 0, 0 };
	if (memo.size() == 0) {
		memo.push_back(initTab);
	}
	if (memo.size() <= n) {
		for (int i = memo.size(); i < n; i++) {
			memo.push_back(initTab);
		}
	}
	if (n == 0) {
		return 0;
	}
	if (memo.size() > n && memo[n] != initTab) {
		return somme(memo[n]);
	} else {
		int iMinValue = 0;
		int minSomme = n;
		for (int i = 0; i < 4; i++) {
			if (n - moneyValues[i] >= 0) {
				if (memo[n - moneyValues[i]] == initTab) {
					int current = money(n - moneyValues[i]);
					if (current < minSomme) {
						minSomme = current;
						iMinValue = i;
					}
				} else {
					int current = somme(memo[n - moneyValues[i]]);
					if (current < minSomme) {
						minSomme = current;
						iMinValue = i;
					}
				}

			}
		}
		//copie les cases du meilleur résultat avec +1 à la valeur de la pièce
		for (int i = 0; i < 4; i++) {
			memo[n][i] = memo[n - moneyValues[iMinValue]][i];
		}
		memo[n][iMinValue] = memo[n - moneyValues[iMinValue]][iMinValue] + 1;
		cout << "le nombre de piece est: ";
		for (int i = 0; i < 4; i++) {
			cout << memo[n][i];
		}
		return somme(memo[n]);
	}
}

int main() {

	int result = money(1);
	int result2 = money(10);
	int result3 = money(4);
	cout << result;
	cout << result2;
}
