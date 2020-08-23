#include<iostream>
#include <cmath>

using namespace std;

long long a, b, c, d;

long long gcd(long long t1, long long t2) {
	return t2 == 0 ? t1 : gcd(t2, t1%t2);
}

void func(long long m, long long n) {
	if (m*n == 0) {
		printf("%s", n == 0 ? "Inf" : "0");
		return;
	}
	bool flag = ((m > 0 && n < 0) || (m < 0 && n > 0));// 负数标志
	m = abs(m);
	n = abs(n);
	long long x = m / n;
	printf("%s", flag ? "(-" : ""); // 如果是负数，要打印(-c a/b)的形式，所以先打印(-
	if (x != 0) printf("%lld", x);// 分子大于分母， 则打印c
	if (m%n == 0) {// 分子恰好被分母整除，结束
		if (flag) printf(")");
		return;
	}
	if (x != 0) printf(" "); // 如果没打印x，不能打印空格
	m = m - x * n;// 分子剩余部分
	long long t = gcd(m, n);// 约分
	m = m / t; n = n / t;
	printf("%lld/%lld%s", m, n, flag ? ")" : "");
	
}
int main() {
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	func(a, b); printf(" + "); func(c, d); printf(" = "); func(a * d + b * c, b * d); printf("\n");
	func(a, b); printf(" - "); func(c, d); printf(" = "); func(a * d - b * c, b * d); printf("\n");
	func(a, b); printf(" * "); func(c, d); printf(" = "); func(a * c, b * d); printf("\n");
	func(a, b); printf(" / "); func(c, d); printf(" = "); func(a * d, b * c);
	return 0;
}