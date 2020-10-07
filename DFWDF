#include <stdio.h>

int input_data(void);
double average(void);
void print_data(double);

int cnt = 0;
static int tot = 0;

int main(void)
{
	double avg;

	tot = input_data();
	avg = average();
	print_data(avg);

	return 0;
}

void print_data(double avg)
{
	printf(" 입력한 양수의 개수 : %d\n", cnt);
	printf(" 전체 합과 평균 : %d, %.1lf\n", tot, avg);
}
