#include <stdio.h>
#include <string.h>
#include "sado.h"

void input_data1(int* pa, int* pb)
{
	printf("두정수 입력: ");
	scanf("%d%d", pa, pb);
}

double average(int a, int b)
{
	int tot;
	double avg;

	tot = a + b;
	avg = tot / 2.0;

	return avg;
}

int main1005_13()
{
	int a = 10, b = 20;
	int x = 30, y = 40;
	int res;

	printf("a + b = %d\n", SUM(a, b));
	printf("x + y = %d\n", SUM(x, y));
	res = 30 / MUL(2, 5);
	printf("res: %d\n", res);

	return 0;
}

int main1005_12()
{
	double radius, area;

	printf("반지름을 입력하시오: ");
	scanf("%lf", &radius);
	area = PI * radius * radius;
	if (area > LIMIT) ERR_PRN;
	else printf("원의 면적: %.2lf (%s)\n", area, MSG);
	return 0;
}

int main1005_11()
{
	Student a = { 315,"홍길동" };
	printf("학번: %d, 이름: %s\n", a.num, a.name);
	return 0;
}


int main1005_10()
{
	FILE* afp, * bfp;
	int num = 10;
	int res;

	afp = fopen("a.txt", "r");
	fprintf(afp, "%d", num);

	bfp = fopen("b.txt", "wb");
	fwrite(&num, sizeof(num), 1, bfp);

	fclose(afp);
	fclose(bfp);

	bfp = fopen("b.txt", "rb");
	fread(&res, sizeof(res), 1, bfp);
	printf("%d", res);

	fclose(bfp);
	return 0;
}

int main1005_9()
{
	FILE* fp;
	int age;
	char name[20];
	char name2[20];
	int res;

	fp = fopen("a.txt", "r");

	res = fscanf(fp, "%d", &age);
	res = fscanf(fp, "%s", name);
	fgets(name2, sizeof(name2), fp);
	printf("나이: %d, 이름: %s%s\n", age, name, name2);
	fclose(fp);

	return 0;
}

int main1005_8()
{
	FILE* ifp, * ofp;
	char name[20];
	int kor, eng, mat;
	int tot;
	double avg;
	int res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL)
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");
	if (ofp == NULL)
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}
	printf("파일을 열었습니다.\n");
	while (1)
	{

		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &mat);
		if (res == EOF)
		{
			break;
		}
		tot = kor + eng + mat;
		avg = tot / 3.0;
		fprintf(ofp, "이름: %s, 총점: %d, 평균: %.1lf\n", name, tot, avg);
	}
	fclose(ifp);
	fclose(ofp);

	return 0;
}

void prt_animal(char** pa, int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
		printf("%d번째 동물: %s\n", i + 1, *(pa + i));
}

void prt_list(Add list, int cnt)
{
	printf("[%d] %s\n 나이: %d\n 우편번호: %s\t주소: %s\n\n", cnt + 1, list.name, list.age, list.addr_num, list.addr);
}

int main1005_7()
{

	FILE* fp;
	char str[20];

	fp = fopen("a.txt", "a+");

	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}
	printf("파일이 열렸습니다.\n");

	fp = fopen("a.txt", "a+");

	while (1)
	{
		printf("과일이름: ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0)
		{
			break;
		}
		else if (strcmp(str, "list") == 0)
		{
			fseek(fp, 0, SEEK_SET);
			while (1)
			{
				fgets(str, sizeof(str), fp);
				if (feof(fp))
				{
					break;
				}
				printf("%s", str);
			}
		}
		else
		{
			fprintf(fp, "%s\n", str);
		}
	}
	fclose(fp);
}

int main1005_6()
{

	FILE* fp;
	int ary[10] = { 13,10, 13, 13, 10, 26, 13, 10 };
	int i, res;

	fp = fopen("c.txt", "wb");

	i = 0;
	while (i < 10)
	{
		fputc(ary[i], fp);
		i++;
	}
	fclose(fp);

	fp = fopen("c.txt", "rt");
	while (1)
	{
		res = fgetc(fp);
		if (res == EOF) break;
		printf("%4d", res);
	}
	fclose(fp);
}

int main1005_5()
{
	int ch;

	while (1)
	{
		ch = fgetc(stdin);

		if (ch == EOF)
		{
			break;
		}
		fputc(ch, stdout);

	}
}

int main1005_4()
{
	int ch;

	while (1)
	{
		ch = getchar();

		if (ch == EOF)
		{
			break;
		}
		putchar(ch);

	}
}

int main1005_3()
{
	FILE* fp;
	char str[] = "banana";
	int i;

	fp = fopen("b.txt", "w");

	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}
	printf("파일이 열렸습니다.\n");
	i = 0;
	while (str[i] != '\0')
	{
		fputc(str[i], fp);
		i++;
	}
	fputc('\n', fp);
	fclose(fp);
}


int main1005_2()
{
	FILE* fp;
	int ch;
	fp = fopen("C:\\Users\\pc1009pc\\source\\repos\\Project1\\a.txt", "r");

	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}
	printf("파일이 열렸습니다.\n");
	while (1)
	{
		ch = fgetc(fp);
		if (ch == -1) /* EOF */
		{
			break;
		}
		putchar(ch);
	}
	fclose(fp);
}

int main1005_1()
{
	FILE* fp;

	fp = fopen("C:\\Users\\pc1009pc\\source\\repos\\Project1\\a.txt", "r");
	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}
	printf("파일이 열렸습니다.\n");
	fclose(fp);
}


int main0929_9()
{
	struct profile2 new_staff[5];

	input_data(new_staff);
	elite(new_staff);
}

void elite(struct profile2* pp)
{
	int i;
	printf("\n\n##########\t엘리트 명단\t##########\n\n");
	for (i = 0; i < 5; i++)
	{
		if (((pp + i)->grade >= 4.0) && ((pp + i)->eng >= 900))
		{
			printf("%d번째 사원\n", i + 1);
			printf("이름 입력: %s\n", (pp + i)->name);
			printf("학점점수: %.1lf\n", (pp + i)->grade);
			printf("영어점수: %d\n\n", (pp + i)->eng);
		}
	}

}
void input_data(struct profile2* pp)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		/*
		printf("%d 번째 사원 입력\n", i + 1);
		printf("이름 입력: ");
		scanf_s("%s", (pp + i)->name, 20);
		printf("학점 입력: ");
		scanf_s("%lf", &(pp + i)->grade);
		printf("영어점수 입력: ");
		scanf_s("%d", &(pp + i)->eng);
		printf("\n\n");
		*/
		printf("%d 번째 사원 입력\n", i + 1);
		printf("이름 입력: ");
		scanf_s(" %s", (pp + i)->name, 20);
		printf("학점 입력: ");
		scanf_s("%lf", &(pp + i)->grade);
		printf("영어점수 입력: ");
		scanf_s("%d", &(pp + i)->eng);
		printf("\n\n");
	}
}



int main0929_7()
{
	struct address list[5] = {
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"이순신", 35, "222-2222", "서울 건청동"},
		{"장보고", 19, "333-3333", "완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555", "황해도 해주"},
	};
	int temp[5] = { 0, };
	int i, j;

	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
	}

	return 0;
}

int main0929_6()
{
	struct marriage m1 = { "이승욱", 38, 'm', 183.4 };
	struct marriage* mp = &m1;

	printf("이름: %s\n", &mp->name);
	printf("나이: %d\n", mp->age);
	printf("성별: %s\n", mp->sex == 'm' ? "남자" : "여자");
	printf("키: %.1lf\n", mp->height);
}

int main0929_5()
{
	struct score yuni = { 90, 80, 70 };
	struct score* ps = &yuni;
	struct score ary[50] = { 0, };
	int i = 0, j;
	char ch;

	while (1)
	{
		printf("국어성적 입력: ");
		scanf_s("%d", &ary[i].kor);
		getchar();
		printf("영어성적 입력: ");
		scanf_s("%d", &ary[i].eng);
		getchar();
		printf("수학성적 입력: ");
		scanf_s("%d", &ary[i].mat);
		getchar();
		i++;
		printf("계속입력하시겠습니까 ? (y/n)");
		scanf("%c", &ch);
		if (ch == 'n') break;
		getchar();
	}
	for (j = 0; j < i; j++)
	{
		printf("[%d] 국어: %d, 영어: %d, 수학: %d\n", i + 1, ary[j].kor, ary[j].eng, ary[j].mat);

	}

	return 0;
}

int main0929_4()
{
	struct children my = { 1, 2, 3 };
	int sum;
	printf("struct children의 크기: %d바이트\n", sizeof(my));
	sum = my.son + my.daughter + my.pet;
	printf("자식 수: %d\n", sum);

	return 0;
}

int main0929_3()
{
	struct vision robot;

	printf("시력입력: ");
	scanf_s("%lf %lf", &(robot.left), &(robot.right));
	robot = exchange(robot);
	printf("바뀐 시력: %.1lf %.1lf\n", robot.left, robot.right);

	return 0;
}

struct vision exchange(struct vision robot)
{
	double temp;

	temp = robot.left;
	robot.left = robot.right;
	robot.right = temp;

	return robot;
}

int main0929_2()
{
	struct cracker ppoddo;
	strcpy(ppoddo.name, "바사삭");

	printf("%s의 가격과 열량을 입력하시오: ", ppoddo.name);
	scanf("%d %d", &ppoddo.price, &ppoddo.calories);
	printf("%s의 가격: %d\n", ppoddo.name, ppoddo.price);
	printf("%s의 열량: %dkcal", ppoddo.name, ppoddo.calories);

}

int main0929_1()
{
	struct student
		s1 = { 315, "홍길동", 2.4 },
		s2 = { 316, "이순신", 3.7 },
		s3 = { 317, "세종대왕", 4.4 },
		s4 = { 318, "이승욱", 4.5 };

	struct student max;

	max = s1;
	if (s2.grade > max.grade) max = s2;
	if (s3.grade > max.grade) max = s3;
	if (s4.grade > max.grade) max = s4;

	printf("학번: %d\n", max.id);
	printf("이름: %s\n", max.name);
	printf("학점: %.1lf\n", max.grade);

	return 0;
}

int main0928_5()
{
	struct profile1 yuni;
	struct profile1 seungwook;

	strcpy(yuni.name, "서하윤");
	strcpy(seungwook.name, "이승욱");
	yuni.age = 17;
	yuni.height = 164.5;
	seungwook.age = 38;
	seungwook.height = 184.5;

	yuni.intro = (char*)malloc(80);
	seungwook.intro = (char*)malloc(80);

	printf("%s 자기소개: ", yuni.name);
	gets(yuni.intro);

	printf("이름: %s\n", yuni.name);
	printf("나이: %d\n", yuni.age);
	printf("키: %.1lf\n", yuni.height);
	printf("자기소개: %s\n\n", yuni.intro);
	free(yuni.intro);

	printf("%s 자기소개: ", seungwook.name);
	gets(seungwook.intro);

	printf("이름: %s\n", seungwook.name);
	printf("나이: %d\n", seungwook.age);
	printf("키: %.1lf\n", seungwook.height);
	printf("자기소개: %s", seungwook.intro);
	free(seungwook.intro);

	return 0;
}

int main0928_4()
{
	int* p_num_list, cnt = 0, sum = 0, limit = 0, i;

	printf("사용할 최대 개수를 입력하세요: ");
	scanf_s("%d", &limit);
	p_num_list = (int*)malloc(limit * sizeof(int));

	while (cnt < limit)
	{
		printf("숫자를 입력하세요 (9999를 누르면 종료: ");
		scanf_s("%d", p_num_list + cnt);
		if (p_num_list[cnt] == 9999) break;
		cnt++;
	}

	for (i = 0; i < cnt; i++)
	{
		if (i > 0) printf(" + ");
		printf("%d", *(p_num_list + i));
		sum = sum + p_num_list[i];
	}
	printf(" = %d\n", sum);
	free(p_num_list);

	return 0;
}


int main0928_3()
{
	int num[MAX_COUNT], count = 0, sum = 0, i;
	while (count < MAX_COUNT)
	{
		printf("숫자를 입력하세요 (9999를 누르면 종료): ");
		scanf("%d", num + count);
		if (num[count] == 9999) break;
		count++;
	}

	for (i = 0; i < count; i++)
	{
		if (i > 0) printf(" + ");
		printf(" %d ", num[i]);
		sum = sum + num[i];
	}
	printf(" = %d\n", sum);
}

int main0928_2()
{
	char temp[80];
	char* str[21] = { 0 };
	int i = 0;

	while (i < 20)
	{
		printf("문자열을 입력하세요: ");
		gets(temp);
		if (strcmp(temp, "end") == 0) break;
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}
	print_str(str);

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	return 0;
}

void print_str(char** ps)
{
	while (*ps != 0)
	{
		printf("%s\n", *ps);
		ps++;
	}
}

int main0928_1()
{
	char temp[80];
	char* str[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("문자열을 입력하세요: ");

		gets(temp);
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
	}

	for (i = 0; i < 3; i++)
	{
		printf("%s", *(str + i));
	}
	for (i = 0; i < 3; i++)
	{
		free(str[i]);
	}
	return 0;
}

int main0925_3()
{
	int* pi;
	int size = 5;
	int cnt = 0;
	int num;
	int i;

	pi = (int*)calloc(size, sizeof(int));

	while (1)
	{
		printf("양수를 입력하시오: ");
		scanf("%d", &num);
		if (num <= 0) break;
		if (cnt < size)
		{
			pi[cnt++] = num;
		}
		else
		{
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int));
			pi[cnt++] = num;
		}
	}
	for (i = 0; i < cnt; i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi);

	return 0;
}

int main0925_2()
{
	int* pa;
	int* pi;
	int paary[4] = { 1,2,3,4 };
	int i, sum = 0;
	pi = (int*)malloc(5 * sizeof(int));
	pa = paary;
	if (pi == NULL)
	{
		printf("메모리가 부족합니다.\n");
		exit(1);
	}
	printf("다섯 명의 나이를 입력하세요");
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", pi + i);
		sum += *(pi + i);
		printf("paary[%d]: %d", i, pa[i]);
	}
	printf("다섯 명의 평균나이: %.1lf\n", (sum / 5.0));
	free(pi);

	return 0;
}

int main0925_1()
{

	int* pi;
	double* pd;
	int* pc;
	pi = (int*)malloc(4); /* 1G바이트 = 1,000,000,000 */
	if (pi == NULL)
	{
		printf("#으로 메모리가 부족합니다.\n");
		exit(1);
		/*
		exit(0) 정상적인 종료, exit(1) 비정상적인 종료
		return은 다른 thread는 계속 돌아감. 프로세스 강제 종료
		*/
	}

	pd = (double*)malloc(sizeof(double));

	*pi = 10;
	*pd = 3.4;
	/* pc = (int*)pi; */

	printf("정수형으로 사용: %d\n", *pi);
	printf("실수형으로 사용: %.1lf\n", *pd);

	free(pi);
	free(pd);

	return 0;
}

int main0924_9()
{
	int sel;
	printf("1. 두 정수의 합\n");
	printf("2. 두 정수의 곱\n");
	printf("3. 두 정수 중 큰 값 계산\n");
	printf("원하는 작업을 선택하세요: ");

	scanf_s("%d", &sel);

	switch (sel)
	{
	case 1: func(sum); break;
	case 2: func(mul); break;
	case 3: func(big); break;
	}
	return 0;
}

int main0924_8()
{
	int (*fp)(int, int);
	int res;

	fp = sum;
	res = fp(10, 20);
	printf("result: %d\n", res);

	return 0;
}
void func(int (*func)(int, int))
{
	int a, b;
	int res;

	printf("두 정수값을 입력하시오: ");
	scanf_s("%d%d", &a, &b);
	res = func(a, b);
	printf("결과값은: %d\n", res);
}

int sum(int a, int b)
{
	int res;
	res = a + b;
	return res;
}

int mul(int a, int b)
{
	int res;
	res = a * b;
	return res;
}

int big(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int main0924_7()
{
	int ary[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d ", *(ary[i] + j));
			printf("%p ", &ary[i][j]); /* ary[i][j] 변수의 기능*/
		}
		printf("\n\n");
	}

	print_ary2(ary);

	return 0;
}

void print_ary2(int(*pa)[4])
{

	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d ", *(*(pa + i) + j));
			printf("%p ", pa[i] + j);
		}
		printf("\n");
	}
}

int main0924_6()
{
	int ary[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int(*pa)[4];
	int i, j;
	int cnt = sizeof(pa);
	int cnt1 = sizeof(ary);
	int cnt2 = sizeof((*pa)[0]);
	printf("pa의 크기: %d", cnt);
	printf("ary의 크기: %d", cnt1);
	printf("(*pa)[0]의 크기: %d\n\n", cnt2);


	int num;
	pa = ary;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			num = (j * i) + j;
			printf("%d ", pa[i][j]);


		}
		printf("\n");
	}

	return 0;
}

int main0924_5()
{
	int ary[5];

	printf("ary의 값: %p\n", ary);
	printf("ary의 주소: %p\n", &ary);

	printf("ary + 1: %p\n", ary + 1);
	printf("&ary + 1: %p\n", &ary + 1);

	return 0;
}

int main0924_4()
{
	char* ptr_ary[] = { "eagle", "tiger", "lion", "squirre" };
	int count;

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
	print_str(ptr_ary);

	return 0;
}


int main0924_3()
{
	short data = 3;
	short* p = &data;
	short** pp = &p;

	printf("[Before ] data: %d\n", data);
	*p = 4;
	printf("[Use *p ] data: %d\n", data);
	**pp = 5;
	printf("[Use **p] data: %d\n", data);

	return 0;
}

int main0924_2()
{
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);
	swap_ptr(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);

	return 0;
}

void swap_ptr(char** ppa, char** ppb)
{
	char* pt;
	pt = *ppa;
	*ppa = *ppb;
	*ppb = pt;
	printf("%s", *ppa);
}

void swap_ptr2(char* pa, char* pb)
{
	char* pt;
	printf("함수안 pa : %p, pb : %p\n", pa, pb);
	pt = pa;
	pa = pb;
	pb = pt;
	printf("함수안 pa : %p, pb : %p\n", pa, pb);
}

int main0924_1()
{
	int a = 10;
	int* pi;
	int** ppi;

	pi = &a;
	ppi = &pi;

	printf("-----------------------------------------------\n");
	printf("변수\t\t변수값\t\t&연산\t\t*연산\t\t**연산\n");
	printf("  a\t%14d\t%14p\t\n", a, &a);
	printf(" pi\t%14p\t%14p\t%14d\n", pi, &pi, *pi);
	printf("ppi\t%14p\t%14p\t%14p%14u\n", ppi, &ppi, *ppi, **ppi);
	printf("-----------------------------------------------\n");

	return 0;

}

int main0923_7()
{
	int i, j, sum = 0, total = 0;
	char* array_name[10] = { "철수", "철희", "영수", "영희" };
	char* array_major[10] = { "국어", "영어", "수학", "과학" };
	int score1[4] = { 45, 63, 93, 91 };
	int score2[4] = { 20, 39, 10, 94 };
	int score3[4] = { 73, 65, 84, 92 };
	int score4[4] = { 47, 58, 93, 28 };
	int score_total[4] = { 0 };
	double score_avg[4] = { 0 };
	int* score[4] = { score1, score2, score3, score4 };

	printf("\n#############################\t성\t적\t#############################\n\n");
	for (i = 0; i < 4; i++)
	{
		sum = 0;
		printf("%s :\n", array_name[i]);
		for (j = 0; j < 4; j++)
		{
			printf("[%s] %d", array_major[j], score[i][j]);
			if (j < 3)
				printf(", ");
			sum += score[i][j];
			score_total[j] += score[i][j];
		}
		score_avg[i] = sum / 4.0;
		printf("\t총합: %d \t평균: %.2lf\n", sum, score_avg[i]);
		total += sum;
	}
	printf("\n과목별 점수 #################################################################\n\n");
	for (i = 0; i < 4; i++)
	{
		printf("[%s]: %d\t", array_major[i], score_total[i]);
	}
	printf("\n\n전체 과목 총점: %d, 전체 평균: %.2lf\n", total, total / 4.0 / 4.0);
	printf("\n############################################################ end ############\n\n");
	return 0;
}

int main0923_6()
{
	int ary1[4] = { 1,2,3,4 };
	int ary2[4] = { 11,12,13,14 };
	int ary3[4] = { 21,22,23,24 };
	int* pary[3] = { ary1, ary2, ary3 };

	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", pary[i][j]);
			/*	*(pary[i] + j)	*/
		}
		printf("\n");
	}
	return 0;
}

int main0923_5()
{
	char* pary[5];
	int i;

	pary[0] = "dog";
	pary[1] = "elaphant";
	pary[2] = "horse";
	pary[3] = "tiger";
	pary[4] = "lion";

	for (i = 0; i < 5; i++)
	{
		printf("pary[%d] %s\n", i, pary[i]);
	}
	return 0;
}

int main0923_4()
{
	int s[2][3][4] = {
		{{72,80,95,60},{68,98,83,90},{75,72,84,90}},
		{{66,85,90,88},{95,92,88,95},{43,72,56,75}},
	};

	int i, j, k;

	for (i = 0; i < 2; i++)
	{
		printf("%d반 점수: \n", i + 1);
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				printf("%5d", s[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

int main0923_3()
{
	int num1[3][4] = { {1,2,3,4,},{5,6,7,8},{9,10,11,12} };
	int num2[3][4] = { {1},{5,6},{9,10,11} };
	int num3[][4] = { {1},{2,3},{4,5,6} };
	int num4[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int num5[3][4] = { 1,2,3,4,5,6 };
	int num6[][4] = { 1,2,3,4,5,6 };

	int* nums[5] = { num1, num2, num3, num4, num5 };
	int i, j;

	line(20);
	printf("num1[3][4]\n");

	prt_array2("nums", nums, 5);

	return 0;
}

int main0923_2()
{
	int num1[3][4] = { {1,2,3,4,},{5,6,7,8},{9,10,11,12} };
	int num2[3][4] = { {1},{5,6},{9,10,11} };
	int num3[][4] = { {1},{2,3},{4,5,6} };
	int num4[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int num5[3][4] = { 1,2,3,4,5,6 };
	int num6[][4] = { 1,2,3,4,5,6 };

	int i, j;

	line(20);
	printf("num1[3][4]\n");
	for (i = 0; i < 3; i++)
	{
		printf("[%d]", i);
		for (j = 0; j < 4; j++)
		{
			printf("%5d", num1[i][j]);
		}
		printf("\n");
	}


	return 0;
}

int main0923_1()
{
	int score[3][4];
	int tot;
	double avg;
	int i, j;

	for (i = 0; i < 3; i++)
	{
		printf("네 과목의 점수: ");
		for (j = 0; j < 4; j++)
		{
			scanf_s("%d", &score[i][j]);
		}

	}
	for (i = 0; i < 3; i++)
	{
		tot = 0;
		for (j = 0; j < 4; j++)
		{
			tot += score[i][j];
		}
		avg = tot / 4.0;
		printf("총점: %d, 평균 %.2lf\n", tot, avg);
	}
	return 0;

}


int main0922_4()
{
	int* p;
	p = sum(10, 20);
	int res = 9;
	printf("두 정수의 합: %d\n", *p);

	return 0;
}

int* psum(int a, int b)
{
	int res; // 프로그램이 실행될때 bss
	res = a + b;

	return &res;
}

int main0922_3()
{
	int a = 10;

	add_ten(a);
	printf("a:%d\n", a);

	return 0;

}

void add_ten(int a)
{
	a = a + 10;
}

int main0922_2()
{
	auto int a = 0;

	assign();
	printf("main 함수 a: %d\n", a);

	return 0;
}

void assign()
{
	auto int a;

	a = 10;
	printf("assign 함수 a: %d\n", a);

}

int main0922_1()
{
	int a = 10;

	add_ten(a);
	printf("a:%d\n", a);

	return 0;

}

int  main0921_13()
{

	char str1[80] = "pear";
	char str2[80] = "peach";
	printf("과일1: %s\n", str1);
	printf("과일2: %s\n", str2);

	printf("사전에 먼저 나오는 과일 이름: ");
	if (strcmp(str1, str2) > 0)
		printf("%s\n", str2);
	else
		printf("%s\n", str1);


	printf("앞의 3개의 문자를 비교하면 ");
	if (strncmp(str1, str2, 3) == 0)
		printf("같다\n");
	else
		printf("다르다\n");


	printf("나의 함수를 사용해서 비교하면 ");
	if (my_strcmp(str1, str2) == 0)
		printf("같다\n");
	else
		printf("다르다\n");

	return 0;
}

int my_strcmp(char* pa, char* pb)
{

	while ((*pa == *pb) && (*pa != '\0'))
	{
		pa++;
		pb++;
	}
	if (*pa > * pb) return 1;
	else if (*pa < *pb) return -1;
	else return 0;
}

int  main0921_12()
{
	char str[80] = "straw";

	strcat(str, "berry");
	printf("%s\n", str);
	strncat(str, "piece", 3);
	printf("%s\n", str);
	printf("%s\n", my_strcat(str, ": so delicious"));

	return 0;
}

char* my_strcat(char* pd, char* ps)
{
	char* po = pd;

	while (*pd != '\0')
		(*pd)++;
	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';

	return po;
}

int  main0921_11()
{
	char str1[80], str2[80];
	char* resp;
	input_char_array("1st과일", str1, 80);
	input_char_array("2st과일", str2, 80);

	if (strlen(str1) > strlen(str2))
		resp = str1;
	else
		resp = str2;
	printf("이름이 긴 과일: %s\n", resp);

	return 0;
}

int  main0921_10()
{
	char str[20] = "mango tree";
	char str1[20] = "apple";

	strncpy(str, "apple", 6); //문자열 그대로 복사 별도로 '\0'넣지 않음
	printf("%s\n", str);

	return 0;
}

int  main0921_9()
{
	char str[80] = "strawberry";

	printf("바꾸기전 문자열: %s\n", str);
	my_strcpy(str, "apple");
	printf("바꾼 후 문자열: %s\n", str);
	printf("다른 문자열 대입: %s\n", my_strcpy(str, "kiwi"));

	return 0;
}

char* my_strcpy(char* pd, char* ps)
{
	char* po = pd;
	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	return po;
}

int  main0921_8()
{
	char str1[80] = "strawberry";
	char str2[80] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;

	printf("str1[80]: %s\n", str1);
	printf("str2[80]: %s\n", str2);
	printf("*ps1: %s\n", ps1);
	printf("*ps2: %s\n\n", ps2);

	printf("최초문자열: %s\n", str1);
	strcpy(str1, str2);
	printf("strcpy(str1, str2): %s\n", str1);

	strcpy(str1, ps2);
	printf("strcpy(str1, ps2): %s\n", str1);

	strcpy(str1, "banana");
	printf("strcpy(str1, \"banana\"): %s\n", str1);

	return 0;
}

int  main0921_7()
{
	char str[80] = "apple juice";
	char* ps = "banana";

	puts(str);
	puts("\n");
	fputs(ps, stdout);
	puts("c");

	return 0;
}

int main0921_6()
{

	int age;
	char name[20];
	char str[20];

	printf("나이 입력: ");
	scanf_s("%d", &age);
	printf("이름 입력: ");
	getchar();
	fgets(name, sizeof(name), stdin);
	printf("나이: %d, 이름: %s\n", age, name);

	my_gets(str);
	printf("%s", str);
	return 0;

}

void my_gets(char* ps)
{

	char ch;
	while ((ch = getchar()) != '\n')
	{
		*ps = ch;
		ps++;
	}
	*ps = '\0';
}

int main0921_5()
{

	int age;
	char name[20];

	printf("나이 입력: ");
	scanf_s("%d", &age);
	printf("이름 입력: ");
	fgets(name, sizeof(name), stdin);
	printf("나이: %d, 이름: %s\n", age, name);

	return 0;

}

int main0921_4()
{
	char addr[20];
	char food[20];
	printf("주소: ");
	fgets(addr, sizeof(addr), stdin);
	printf("좋아하는 음식: ");
	fgets(food, sizeof(food), stdin);

	addr[strlen(addr) - 1] = '\0';
	food[strlen(food) - 1] = '\0';

	printf("저는 %s 에 삽니다.\n", addr);
	printf("%s 를 좋아합니다.\n", food);

	return 0;
}

int main0921_3()
{
	char str[10];

	printf("문자열 입력: ");
	fgets(str, sizeof(str), stdin);
	printf("입력한 문자열 : %s\n", str);
	printf("마지막자리 : %s\n", str + 9);

	return 0;
}

int main0921_2()
{
	p_ch("Ex12_3");

	char str[80];

	printf("문자열 입력: ");
	scanf_s("%s", str, 79);
	printf("첫번째 단어 :%s\n", str);
	scanf_s("%s", str, 79);
	printf("버퍼에 남아 있는 단어: %s\n", str);
	printf("문자열의 주소': %p\n", str);

	return 0;
}

int main0921_1()
{
	p_ch("Ex12_1");

	char* dessert = "apple""jam";

	printf("오늘의 후식: %s\n", dessert);
	dessert = "banana";
	printf("내일의 후식: %s\n", dessert);

	p_end();
	return 0;
}

int main0918_6()
{
	char str[80];

	printf("문자열 입력(80): ");
	scanf_s("%s", str, 79);
	printf("첫번째 단어: %s", str);
	scanf_s("%s", str, 79);
	printf("두번째 단어: %s\n", str);
	printf("str출력: %s\n", str);

	return 0;
}

int main0918_5()
{
	char* pa = "apple";
	char* pb = "apple";
	char* pc = MSG;

	printf("%s의 주소: %p\n", pa, pa);
	printf("%s의 주소: %p\n", pb, pb);
	printf("%s의 주소: %p\n", pc, pc);
	printf("%s의 주소: %p\n", MSG, MSG);
	printf("%s의 주소: %p\n", MSG + 2, MSG + 2);

	return 0;
}

int main0918_4()
{
	int i;
	char dessert[20] = { 0 };
	printf("문자열(20)을 입력하시오: ");
	scanf_s("%s", dessert, 19);
	printf("오늘 후식은 %s입니다.\n", dessert);

	for (i = 0; i < str_len(dessert); i++)
		printf("%d: %c\n", i, *(dessert + i));
	printf("크기: %d\n", str_len(dessert));
	return 0;
}


int main0918_3()
{
	printf("첫번째 문자: %c\n", *"ma");
	printf("주소값: %p\n", "mango" + 1);
	printf("두번째 문자: %c\n", *("mango" + 1));
	printf("주소값: %p\n", "mango" + 2);
	printf("세번째 문자: %c\n", "mango"[2]);

	char_prt_array("mango", "mango", 5);
	return 0;
}

int main0918_2()
{
	int num, grade;

	printf("학번 입력:");
	scanf_s(" %d", &num);
	rewind(stdin);
	printf("학점 입력: ");
	grade = getchar();
	printf("학번: %d, 학점: %c", num, grade);


	system("pause");
	return 0;

}

int main0918_1(void)
{
	//int res;
	char ch;

	while (1)
	{
		printf("키보드 입력값 : ");
		scanf_s(" %c", &ch, 1);
		printf("%2c [%4d]\n", ch, ch);
		if (ch == -1) break;
		//printf("%d]\n\n", res);
		rewind(stdin);
	}

	return 0;
}

int str_len(char* str)
{
	char* p;
	for (p = str; *p; p++);
	return p - str;
}

char prt_upper(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		ch = ch + ('a' - 'A');
	}

	return ch;

}

void prt_asc(char ch)
{
	printf("%c의 아스키 코드값: %d\n", ch, ch);

}

void print_ary1(int* pa, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}

}

void p_ch(char* ch)
{
	printf("\n#######################################################\n");
	printf("\t\t\t%s", ch);
	printf("\n#######################################################\n\n");
}

void p_end()
{
	printf("\n############################################### END ###\n\n");
}

void input_int_array(char* title, int* pa, int cnt)
{
	printf("[%s 입력]\n", title);
	int i;
	for (i = 0; i < cnt; i++)
	{
		printf("%d 번째 값: ", i + 1);
		scanf_s("%d", pa + i);
	}
	int_prt_array(title, pa, cnt);
}

void input_char_array(char* title, char* pa, int cnt)
{

	printf("[%s 입력]\n", title);
	fgets(pa, cnt, stdin);
	char_prt_array(title, pa, cnt);
}

void line(int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		printf("-");
	}
	printf("\n");
}

void int_prt_array(char* title, int* pa, int cnt)
{

	int i;
	printf("\n%s[%d]:\n[int] ", title, cnt);
	line(30);
	printf("| \t address | no |    value   |\n");
	line(36);
	for (i = 0; i < cnt; i++)
	{
		printf("| %p | %2d | %10d |\n", pa + i, i, *(pa + i));
		line(36);
	}
}

void char_prt_array(char* title, char* pa, int cnt)
{

	int i;
	printf("\n%s[%d]:\n[char] ", title, cnt);
	line(18);
	printf("|  address | no | value |\n");
	line(25);
	for (i = 0; i < cnt; i++)
	{
		if (*(pa + i) == '\0')
		{
			printf("| %p | %2d |  nul  |\n", pa + i, i);
			line(25);
			break;
		}
		else
			printf("| %p | %2d |    %c  |\n", pa + i, i, *(pa + i));
		line(25);
	}

}

void prt_array2(char* title, int* pa[], int cnt)
{
	int i, j, k;
	int row = 3;
	int col = 4;
	for (i = 0; i < cnt; i++)
	{
		line(20);
		printf("%s[%d]\n", title, i);
		line(20);
		for (j = 0; j < row; j++)
		{
			for (k = 0; k < col; k++)
			{
				printf(" %2d ", *(pa[i] + (j * col) + k));
			}
			printf("\n");
		}
		printf("\n");
	}
}
