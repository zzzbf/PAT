#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {
	if (n < 2) return false; // ¿Óµã2
	if (n == 2 || n == 3) return true;
	int sqrtn = (int)sqrt(n);
	if (n % 6 != 5 && n % 6 != 1) 
		return false;
	for (int i = 5; i <= sqrtn; i+=6) 
		if (n%i == 0 || n % (i + 2) == 0) 
			return false;
	return true;
}
int main()
{
	int n, ans = -1;
	scanf("%d", &n);
	if (isPrime(n - 6) && isPrime(n)) ans = n - 6;
	else if (isPrime(n + 6) && isPrime(n)) ans = n + 6;
	else 
		while ((!isPrime(n) || !isPrime(n + 6)) && (!isPrime(n) || !isPrime(n - 6))) n++;// ¿Óµã1
	if (ans == -1) printf("No\n%d", n);
	else printf("Yes\n%d", ans);
	return 0;
}