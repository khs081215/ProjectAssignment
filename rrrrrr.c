#include <stdio.h>

void clean();

void printFirst();
void printEnd(int count);
void printLine();

void plus();
void minus();
void multiple();
void  divide();

int getDecision();

int main() {
	int d = 1, count = 0;
	while (1) {
		printFirst();
		d = getDecision();
		if (d == 0) {
			break;
		}
		count++;
		printLine();
	}
	printEnd(count);
	while (1);
	return 0;
}

//용덕
void printFirst() {
	printf("( 설명 ) 1 : 덧셈 2 : 뺄셈 3 : 곱셈 4 : 나눗셈 0 : 종료\n");
	return;
}
void printEnd(int count) {
	printf("\n\n종료되었습니다\n");
	printf("연산횟수 : %d", count);
	printf("감사합니다\n");
	return 0;
}
void printLine() {
	printf("----------------------------------------------------------\n\n");
	return 0;
}

//현석
void plus() {
	int n1, n2;
	printf("첫번째 숫자 입력 : ");
	scanf("%d", &n1);
	clean();
	printf("두번째 숫자 입력 : ");
	scanf("%d", &n2);
	clean();
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
}
void minus() {
	int n1, n2;
	printf("첫번째 숫자 입력 : ");
	scanf("%d", &n1);
	clean();
	printf("두번째 숫자 입력 : ");
	scanf("%d", &n2);
	clean();
	printf("%d - %d = %d\n", n1, n2, n1 - n2);
}
void multiple() {
	int n1, n2;
	printf("첫번째 숫자 입력 : ");
	scanf("%d", &n1);
	clean();
	printf("두번째 숫자 입력 : ");
	scanf("%d", &n2);
	clean();
	printf("%d * %d = %d\n", n1, n2, n1*n2);
}
void divide() {
	int n1, n2;
	printf("첫번째 숫자 입력 : ");
	scanf("%d", &n1);
	clean();
	printf("두번째 숫자 입력 : ");
	scanf("%d", &n2);
	clean();
	if (n1%n2) {
		printf("%d / %d = %.2f\n", n1, n2, (float)n1 / n2);
	}
	else printf("%d / %d = %d\n", n1, n2, n1 / n2);
}

//효연
int getDecision() {
	int d = 6974;
	while (1) {
		printf("모드 선택 : ");
		scanf("%d", &d);
		clean();
		if (d == 0) {
			return 0;
		}
		if (!(d == 1 || d == 2 || d == 3 || d == 4)) {
			printf("잘못 입력했습니다! 다시 입력해 주세요\n\n");
			clean();
			continue;
		}
		switch (d) {
		case 1:
			plus();
			break;
		case 2:
			minus();
			break;
		case 3:
			multiple();
			break;
		case 4:
			divide();
			break;
		default: break;
		}
		return 1;
	}
	return 1;
}

void clean() {
	char bin;
	scanf("%c", &bin);
	return;
}
