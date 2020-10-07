#include <stdio.h>
#include <string.h>
#include "sado.h"

/*int main(int argc, char** argv)
{
	p_ch("200928");

	for (i = 0; i < argc; i++)
	{
		for (i = 0; i < argc; i++)
		{
			printf("%d번째 인자: %s\n", i, argv[i]);
		}
		return 0;
	}

	char temp[80] = { 0 };
	char **str;
	int max;
	int i;
	max = atoi(*(argv + 1));
	str = (char**)malloc((max + 1) * sizeof(char*));
	i = 0;

	while (1)
	{
		printf("문자열을 입력하시오: ");
		gets(temp);
		if (temp[0] == '\0') break;

		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
		if (i == max)
		{
			printf("문자열 입력이 최대값을 모두 채웠습니다.\n");
			break;
		}
	}
	str[i] = "\0";
	print_str(str);

	i = 0;
	while (str[i] == "\0")
	{
		free(str[i]);
		i++;
	}
	free(str);

	p_end();
	system("pause");
	return 0;
}*/
int main0918_1(); int main0918_2(); int main0918_3(); int main0918_4(); int main0918_5();
int main0921_1(); int main0921_2(); int main0921_3(); int main0921_4(); int main0921_5();
int main0921_6(); int main0921_7(); int main0921_8(); int main0921_9(); int main0921_10();
int main0921_11(); int main0921_12(); int main0921_13();
int main0922_1(); int main0922_2(); int main0922_3(); int main0922_4();
int main0923_1(); int main0923_2(); int main0923_3(); int main0923_4(); int main0923_5();
int main0923_6(); int main0923_7();
int main0924_1(); int main0924_2(); int main0924_3(); int main0924_4(); int main0924_5();
int main0924_6(); int main0924_7(); int main0924_8(); int main0924_9();
int main0925_1(); int main0925_2(); int main0925_3();
int main0928_1(); int main0928_2(); int main0928_3(); int main0928_4(); int main0928_5();
int main0929_1(); int main0929_2(); int main0929_3(); int main0929_4(); int main0929_5();
int main0929_6(); int main0929_7(); int main0929_9();
int main1005_1(); int main1005_2(); int main1005_3(); int main1005_4(); int main1005_5();
int main1005_6(); int main1005_7(); int main1005_8(); int main1005_9(); int main1005_10();
int main1005_11(); int main1005_12(); int main1005_13();
int main1006_1(); int main1006_2(); int main1006_3(); int main1006_4(); int main1006_5();

int main()
{
	p_ch("1006_5");

	main1006_5();

	p_end();
	return 0;
}

int main1006_5()
{
	int a, b;
	double avg;

	input_data1(&a, &b);
	avg = average(a, b);
	printf("%d와 %d의 평균: %.1lf\n", a, b, avg);
}

int main1006_4()
{
	printf("Sample1 구조체의 크기: %d바이트\n", sizeof(Sample1));
	printf("Sample2 구조체의 크기: %d바이트\n", sizeof(Sample2));

	return 0;
}

int main1006_3()
{
	int max;

#if VER >= 6
	printf("버전 %d입니다\n", VER);
#endif
#ifdef BIT16
	max = 32767;
#else
	max = 2147483647;
#endif

	printf("int형 변수의 최대값: %d\n", max);

	return 0;
}

int main1006_2()
{
	int a1, a2;

	NAME_CAT(a, 1) = 10;
	NAME_CAT(a, 2) = 20;
	PRINT_EXPR(a1 + a2);
	PRINT_EXPR(a2 + a1);

	return 0;
}

void func1(void);

int main1006_1()
{
	printf("컴파일 날짜와 시간: %s, %s\n\n", __DATE__, __TIME__);
	printf("파일명: %s\n", __FILE__);
	printf("함수명: %s\n", __FUNCTION__);
	printf("행번호: %d\n", __LINE__);

#line 100 "macro.c"
	printf("\n##########################################\n");
	func1();

	return 0;
}

void func1(void) 
{
	printf("\n");
	printf("파일명: %s\n", __FILE__);
	printf("함수명: %s\n", __FUNCTION__);
	printf("행번호: %d\n", __LINE__);
}
