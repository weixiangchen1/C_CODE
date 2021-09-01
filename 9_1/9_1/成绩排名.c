#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct student
{
	char name[15];
	char num[15];
	int score;
};
int main()
{
	struct student students[100];
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%d", students[i].name, students[i].num, &students[i].score);
	}
	struct student max = students[0];
	struct student min = students[0];
	for (int i = 1; i < n; i++)
	{
		if (max.score < students[i].score)
		{
			max = students[i];
		}
		if (min.score > students[i].score)
		{
			min = students[i];
		}
	}
	printf("%s %s\n", max.name, max.num);
	printf("%s %s\n", min.name, min.num);
	return 0;

}