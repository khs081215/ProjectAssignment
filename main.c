#include <stdio.h>
#include <string.h>

typedef struct {
	char num[1000]; //숫자를 나눠서 입력받는다.
	int digit;  //자릿수를 저장한다
} bigNum;

bigNum  getBigNum();
bigNum reverse(bigNum number);

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
		clean();
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

void printFirst() {
	printf("+++Warnning : Please input 1000digit int type number+++\n");
	printf("(Info ) (1 : +) (2 : -) (3 : *) (4 : /) (0 : Exit)\n");
	return;
}
void printEnd(int count) {
	printf("\n\nExit\n");
	printf("Count : %d\n", count);
	printf("Thanks\n");
	return;
}
void printLine() {
	printf("----------------------------------------------------------\n\n");
	return;
}

void plus() {
	bigNum num[3];
	int M = 0, m = 0, i;
	printf("input FirstNumber : ");
	num[0] = getBigNum();
	clean();
	printf("input SecondNumber : ");
	num[1] = getBigNum();
	printf("\n%s\n + \n%s \n", num[0].num, num[1].num);

	num[0] = reverse(num[0]);
	num[1] = reverse(num[1]);

	if (num[0].digit > num[1].digit) {
		M = num[0].digit;
		m = num[1].digit;
		num[1].digit = M;
		for (int i = m; i < M; i++) {
			num[1].num[i] = '0';
		}
		num[1].num[M] = '\0';
	}
	else if (num[0].digit == num[1].digit) {
		M = num[0].digit;
		m = num[1].digit;
	}
	else {
		M = num[1].digit;
		m = num[0].digit;
		num[0].digit = M;
		for (int i = m; i < M; i++) {
			num[0].num[i] = '0';
		}
		num[0].num[M] = '\0';
	}

	for (int i = 0; i < M + 1; i++) {
		num[2].num[i] = '0';
	}
	num[2].num[M + 1] = '\0';

	for (i = 0; i < M; i++) {

		if ((num[2].num[i] + num[0].num[i] + num[1].num[i]) - '0' - '0' > '9') {
			num[2].num[i] = num[2].num[i] + num[0].num[i] + num[1].num[i] - '0' - 10 - '0';
			num[2].num[i + 1] = num[2].num[i + 1] + 1;
			if (i == M - 1) {
				M++;
				break;
			}
		}
		else
			num[2].num[i] = num[2].num[i] + num[0].num[i] + num[1].num[i] - '0' - '0';
	}

	num[2].num[M] = '\0';
	num[2].digit = M;
	num[2] = reverse(num[2]);
	printf("\n(Output)\n%s\n", num[2].num);
}

void minus() {
	bigNum num[2];
	bigNum snum[3];
	int M = 0, m = 0, count = 0;

	printf("input FirstNumber : ");
	num[0] = getBigNum();
	clean();
	printf("input SecondNumber : ");
	num[1] = getBigNum();
	printf("\n%s\n - \n%s \n", num[0].num, num[1].num);

	num[0] = reverse(num[0]);
	num[1] = reverse(num[1]);

	if (num[0].digit > num[1].digit) {
		snum[0] = num[0];
		snum[1] = num[1];
		M = snum[0].digit;
		m = snum[1].digit;
		for (int i = m; i < M; i++) {
			snum[1].num[i] = '0';
		}
		snum[1].num[M] = '\0';
	}
	else if (num[0].digit == num[1].digit) {
		snum[0] = num[0];
		snum[1] = num[1];
		M = snum[0].digit;
		m = snum[1].digit;

		for (int i = 0; i < M; i++) {
			if (snum[0].num[i] > snum[1].num[i])
				break;
			else if (snum[0].num[i] == snum[1].num[i])
				continue;
			else {
				snum[2] = snum[0];
				snum[0] = snum[1];
				snum[1] = snum[2];
			}
		}
	}
	else {

		snum[0] = num[1];
		snum[1] = num[0];
		M = snum[0].digit;
		m = snum[1].digit;

		for (int i = m; i < M; i++) {
			snum[1].num[i] = '0';
		}
		snum[1].num[M] = '\0';
	}

	for (int i = 0; i < M; i++) {
		snum[2].num[i] = '0';
	}
	snum[2].num[M] = '\0';

	for (int i = 0; i < M; i++) {
		if ((snum[0].num[i] < snum[1].num[i])) {
			snum[2].num[i] = snum[2].num[i] + snum[0].num[i] - snum[1].num[i] + 10;
			snum[2].num[i + 1] = snum[2].num[i + 1] - 1;
			if (i == M - 1) {
				if (snum[0].num[i] == '1') {
					M--;
					break;
				}
			}

		}
		else if (snum[0].num[i] == snum[1].num[i]) {
			snum[2].num[i] = '0';
		}
		else
			snum[2].num[i] = snum[2].num[i] + snum[0].num[i] - snum[1].num[i];
	}

	snum[2].num[M] = '\0';
	snum[2].digit = M;
	for (int i = M - 1; i > 0; i--) {
		if (snum[2].num[i] != '0') {
			break;
		}
		snum[2].num[i] = '\0';
		snum[2].digit = i;
	}
	if (snum[2].num[0] == '\0') {
		snum[2].num[0] = '0';
		snum[2].digit = 1;
	}
	snum[2] = reverse(snum[2]);
	printf("\n(Output)\n%s\n", snum[2].num);
}
void multiple() {














}
void divide() {
	bigNum num[2];
	bigNum snum[4];
	int M = 0, m = 0, count = 0, i, rM = 0;

	printf("input FirstNumber : ");
	num[0] = getBigNum();
	clean();
	printf("input SecondNumber : ");
	num[1] = getBigNum();
	printf("\n%s\n / \n%s \n", num[0].num, num[1].num);

	if (num[0].digit > num[1].digit) {
		snum[0] = num[0];
		snum[1] = num[1];
		M = snum[0].digit;
		m = snum[1].digit;
		for (int i = m; i < M; i++) {
			snum[1].num[i] = '0';
		}
		snum[1].num[M] = '\0';
		snum[1].digit = M;
	}
	else if (num[0].digit == num[1].digit) {
		snum[0] = num[0];
		snum[1] = num[1];
		M = snum[0].digit;
		m = snum[1].digit;

		for (int i = 0; i < M; i++) {
			if (snum[0].num[i] > snum[1].num[i])
				break;
			else if (snum[0].num[i] == snum[1].num[i])
				continue;
			else {
				snum[2] = snum[0];
				snum[0] = snum[1];
				snum[1] = snum[2];
			}
		}
	}
	else {
		snum[0] = num[1];
		snum[1] = num[0];
		M = snum[0].digit;
		m = snum[1].digit;

		for (int i = m; i < M; i++) {
			snum[1].num[i] = '0';
		}
		snum[1].num[M] = '\0';
		snum[1].digit = M;
	}

	for (int i = 0; i < M; i++) {
		snum[2].num[i] = '0';
	}
	snum[2].num[M] = '\0';

	//snum3 초기화 ->이게 값임
	for (int i = 0; i < M - m + 1; i++) {
		snum[3].num[i] = '0';
	}
	snum[3].num[M - m + 1] = '\0';

	// 본방      -----------------------------------------------------------------------------------------------
	while (1) {
		if (M < m)
			break;

		while (snum[0].digit > snum[1].digit)
			snum[1].digit--;

		if (snum[1].digit < m)
			break;

		snum[0] = reverse(snum[0]);
		snum[1] = reverse(snum[1]);

		for (int i = M; i > 0; i--) {
			if (snum[0].num[i] < snum[1].num[i]) {
				count++;
				M--;
				snum[1] = reverse(snum[1]);
				snum[1].digit--;
				snum[1].num[snum[1].digit] = '\0';
			}
		}

		printf("\n%s \n%s\n", snum[0].num, snum[1].num);

		if (M > snum[1].digit) {
			for (int i = snum[1].digit; i > M; i--)
				snum[0].num[i] = '0';
			snum[1].num[M] = '\n';
		}

		//빼기
		for (int i = 0; i < M; i++) {
			if ((snum[0].num[i] < snum[1].num[i])) {
				snum[2].num[i] = snum[2].num[i] + snum[0].num[i] - snum[1].num[i] + 10;
				snum[2].num[i + 1] = snum[2].num[i + 1] - 1;
				if (i == M - 1) {
					if (snum[0].num[i] == '1') {
						M--;
						break;
					}
				}

			}
			else if (snum[0].num[i] == snum[1].num[i]) {
				snum[2].num[i] = '0';
			}
			else
				snum[2].num[i] = snum[2].num[i] + snum[0].num[i] - snum[1].num[i];
		}

		snum[2].num[M] = '\0';
		snum[2].digit = M;
		for (int i = M - 1; i > 0; i--) {
			if (snum[2].num[i] != '0') {
				break;
			}
			snum[2].num[i] = '\0';
			snum[2].digit = i;
		}
		if (snum[2].num[0] == '\0') {
			snum[2].num[0] = '0';
			snum[2].digit = 1;
		}

		printf(" snum2 %s", snum[2].num);
		snum[1] = reverse(snum[1]);
		snum[2].num[snum[2].digit] = '\0';
		snum[2] = reverse(snum[2]);
		printf("snum2%s", snum[2].num);

		snum[0] = snum[2];
		snum[3].num[count] += 1;
	}

	printf("\n(Output)\n몫 : %s\n나머지 : %s\n\n", snum[3].num, snum[0].num);
}

int getDecision() {
	int d = 1234;
	while (1) {
		printf("Mode : ");
		scanf("%d", &d);
		clean();
		if (d == 0) {
			return 0;
		}
		if (!(d == 1 || d == 2 || d == 3 || d == 4)) {
			printf("Please reInput\n\n");
			d = 1234;
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
		break;
	}
	return 1;
}

void clean() {
	char bin;
	scanf("%c", &bin);
	return;
}

bigNum getBigNum() {
	bigNum number;
	scanf("%s", number.num);
	number.digit = strlen(number.num);
	return number;
}

bigNum reverse(bigNum number) {
	char tmp;
	for (int i = 0; i < (number.digit / 2); i++) {
		tmp = number.num[i];
		number.num[i] = number.num[number.digit - 1 - i];
		number.num[number.digit - 1 - i] = tmp;
	}
	return number;
}