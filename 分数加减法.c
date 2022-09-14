#include <stdio.h>
#include <stdlib.h>

void approximation(int, int);//处理公约数
void fadd(int, int, int, int);//分数加
void fsub(int, int, int, int);//分数减

void approximation(int e, int f) {
	if (e == 0) {
		printf("结果为：0");
		return;
	}
	if (e % f == 0) {
		printf("结果为：%d", e / f);
		return;
	}
	int appr = 1;//公约数
	int symbol;//正负号保留
	symbol = e * f < 0 ? -1 : 1;
	if (e < 0) {
		e = -e;
	}
	if (f < 0) {
		f = -f;
	}
	for (int i = 2; i <= (e < f ? e : f); i++) {//找公约数
		if (e % i == 0 && f % i == 0) {
			appr = i;
		}
	}
	e = e / appr * symbol;
	f = f / appr;
	printf("结果为：%d / %d\n", e, f);
}

void fadd(int a, int b, int c, int d) {
	int e, f;
	if (b == d) {
		e = a + c;
		f = b;
	} else {
		e = a * d + c * b;
		f = b * d;
	}
	approximation(e, f);
}

void fsub(int a, int b, int c, int d) {
	int e, f;
	if (b == d) {
		e = a - c;
		f = b;
	} else {
		e = a * d - c * b;
		f = b * d;
	}
	approximation(e, f);
}

int main(void) {
	int a, b, c, d;
	char add_sub;
	printf("================分数加减计算器================\n输入分子和分母（如a/b+c/d）:");
	scanf("%d/%d", &a, &b);
	scanf("%c", &add_sub);
	scanf("%d/%d", &c, &d);
	if (b == 0 || d == 0) {
		printf("分母不能为0\n");
		exit(1);
	}
	if (add_sub == '+') {
		fadd(a, b, c, d);
	} else if (add_sub == '-') {
		fsub(a, b, c, d);
	} else {
		printf("输入有误\n");
	}

	return 0;
}
