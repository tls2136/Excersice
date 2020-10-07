#define _CRT_NO_SECURE_WARNINGS
#pragma warning(disable: 4996)
#define MAX_COUNT 5
#define PI 3.14159
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("범위를 벗어났습니다!\n")
#define SUM(a,b) ((a)+(b))
#define MUL(a,b) ((a)*(b))
#define PRINT_EXPR(x) printf(#x" = %d\n", x)
#define NAME_CAT(x,y) (x ## y)
#define VER 7
#define BIT16
#pragma pack(push,2)

typedef struct
{
	char ch;
	int in;
}Sample1;

#pragma pack(pop)

typedef struct
{
	char ch;
	int in;
}Sample2;


struct profile1
{
	char name[20]; int age; double height; char* intro;
};
struct profile2
{
	char name[20]; double grade; int eng;
};
struct student
{
	int id; char name[20]; double grade;
};
struct book
{
	char title[40]; char author[15]; int page; int price;
};
struct cracker
{
	char name[20]; int price; int calories;
};
struct vision
{
	double left; double right;
};
struct children
{
	unsigned int son : 2; unsigned int daughter : 2; unsigned int pet : 3;
};
struct score
{
	int kor; int eng; int mat;
};
struct marriage
{
	char name[20]; int age; char sex; double height;
};
struct address
{
	char name[20]; int age; char tel[20]; char addr[80];
};
struct add2
{
	char name[10]; int age; char add_num[30]; char add[30];
};
struct list
{
	char name[20]; int num; char add[20]; char addnum[20];
};
struct add
{
	char name[20]; int age; char addr_num[10]; char addr[20];
};
typedef struct
{
	int num;
	char name[20];
}Student;

typedef struct list List;
typedef struct add Add;

int str_len(char*);
void my_gets(char* ps);
char* my_strcpy(char* pd, char* ps);
char* my_strcat(char* pd, char* ps);
int my_strcmp(char* pa, char* pb);
void p_ch(char* ch);
void p_end();
void char_prt_array(char* title, char* pa, int cnt);
void int_prt_array(char* title, int* pa, int cnt);
void input_int_array(char* title, int* pa, int cnt);
void input_char_array(char* title, char* pa, int cnt);
void line(int cnt);
void prt_asc(char ch);
char prt_upper(char ch);
void print_ary1(int* pa, int size);
void assign();
void add_ten(int a);
int* psum(int, int);
void prt_array2(char* title, int* pa[], int);
void swap_ptr(char** ppa, char** ppb);
void swap_ptr2(char* pa, char* pb);
void print_ary2(int(*)[4]);
void func(int (*)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int big(int a, int b);
void print_str(char**);
struct vision exchange(struct vision);
void input_data(struct profile2* pp);
void elite(struct profile2* pp);
void prt_animal(char** pa, int cnt);
void prt_list(Add list, int cnt);
void input_data1(int*, int*);
double average(int, int);
