#include<stdio.h>
#include<string.h>

char s[114514];
int i;
int scores[] = { 0, 15, 30, 40 };

int A_Set_Score;
int B_Set_Score;
int A_Game_Score;
int B_Game_Score;
int A_Ball;
int B_Ball;
int Set_Type;
int Game_Type;

void gt1()
{
	if (s[i] == 'A')
	{
		if (A_Ball == -1)
		{
			A_Game_Score++;
			if (A_Game_Score == 6)
			{
				A_Set_Score++;
				A_Game_Score = 0;
				B_Game_Score = 0;
			}
			A_Ball = 0;
			B_Ball = 0;
		}
		else if (B_Ball == -1)
		{
			A_Ball = 3;
			B_Ball = 3;
		}
		else
		{
			A_Ball++;
			if (A_Ball >= 4)
			{
				if (B_Ball < 3)
				{
					A_Game_Score++;
					if (A_Game_Score == 6)
					{
						A_Set_Score++;
						A_Game_Score = 0;
						B_Game_Score = 0;
					}
					A_Ball = 0;
					B_Ball = 0;
				}
				else
				{
					A_Ball = -1;
				}
			}
		}
	}
	else
	{
		if (B_Ball == -1)
		{
			B_Game_Score++;
			if (B_Game_Score == 6)
			{
				B_Set_Score++;
				A_Game_Score = 0;
				B_Game_Score = 0;
			}
			A_Ball = 0;
			B_Ball = 0;
		}
		else if (A_Ball == -1)
		{
			A_Ball = 3;
			B_Ball = 3;
		}
		else
		{
			B_Ball++;
			if (B_Ball >= 4)
			{
				if (A_Ball < 3)
				{
					B_Game_Score++;
					if (B_Game_Score == 6)
					{
						B_Set_Score++;
						A_Game_Score = 0;
						B_Game_Score = 0;
					}
					A_Ball = 0;
					B_Ball = 0;
				}
				else
				{
					B_Ball = -1;
				}
			}
		}
	}
	printf("  Set:%3d :%3d\n", A_Set_Score, B_Set_Score);
	printf(" Game:%3d :%3d\n", A_Game_Score, B_Game_Score);
	if(A_Ball == -1)
		printf("Point: AD :   \n");
	else if(B_Ball == -1)
		printf("Point:    : AD\n");
	else
		printf("Point:%3d :%3d\n", scores[A_Ball], scores[B_Ball]);
}

void gt2()
{
	if (s[i] == 'A')
	{
		if (A_Ball == -1)
		{
			A_Game_Score++;
			if (A_Game_Score == 7)
			{
				A_Set_Score++;
				A_Game_Score = 0;
				B_Game_Score = 0;
				Game_Type = 1;
			}
			A_Ball = 0;
			B_Ball = 0;
		}
		else if (B_Ball == -1)
		{
			A_Ball = 3;
			B_Ball = 3;
		}
		else
		{
			A_Ball++;
			if (A_Ball >= 4)
			{
				if (B_Ball < 3)
				{
					A_Game_Score++;
					if (A_Game_Score == 7)
					{
						A_Set_Score++;
						A_Game_Score = 0;
						B_Game_Score = 0;
						Game_Type = 1;
					}
					A_Ball = 0;
					B_Ball = 0;
				}
				else
				{
					A_Ball = -1;
				}
			}
		}
	}
	else
	{
		if (B_Ball == -1)
		{
			B_Game_Score++;
			if (B_Game_Score == 7)
			{
				B_Set_Score++;
				A_Game_Score = 0;
				B_Game_Score = 0;
				Game_Type = 1;
			}
			A_Ball = 0;
			B_Ball = 0;
		}
		else if (A_Ball == -1)
		{
			A_Ball = 3;
			B_Ball = 3;
		}
		else
		{
			B_Ball++;
			if (B_Ball >= 4)
			{
				if (A_Ball < 3)
				{
					B_Game_Score++;
					if (B_Game_Score == 7)
					{
						B_Set_Score++;
						A_Game_Score = 0;
						B_Game_Score = 0;
						Game_Type = 1;
					}
					A_Ball = 0;
					B_Ball = 0;
				}
				else
				{
					B_Ball = -1;
				}
			}
		}
	}
	printf("  Set:%3d :%3d\n", A_Set_Score, B_Set_Score);
	printf(" Game:%3d :%3d\n", A_Game_Score, B_Game_Score);
	if (A_Ball == -1)
		printf("Point: AD :   \n");
	else if (B_Ball == -1)
		printf("Point:    : AD\n");
	else
		printf("Point:%3d :%3d\n", scores[A_Ball], scores[B_Ball]);
}

void gt3()
{
	if (Set_Type == 1)
	{
		if (s[i] == 'A')
		{
			A_Ball++;
			if (A_Ball >= 7 && A_Ball - B_Ball >= 2)
			{
				A_Set_Score++;
				A_Game_Score = 0;
				B_Game_Score = 0;
				A_Ball = 0;
				B_Ball = 0;
				Game_Type = 1;
			}
		}
		else
		{
			B_Ball++;
			if (B_Ball >= 7 && B_Ball - A_Ball >= 2)
			{
				B_Set_Score++;
				A_Game_Score = 0;
				B_Game_Score = 0;
				A_Ball = 0;
				B_Ball = 0;
				Game_Type = 1;
			}
		}
		printf("  Set:%3d :%3d\n", A_Set_Score, B_Set_Score);
		printf(" Game:%3d :%3d\n", A_Game_Score, B_Game_Score);
		printf("Point:%3d :%3d\n", A_Ball, B_Ball);
	}
	else
	{
		if (s[i] == 'A')
		{
			if (A_Ball == -1)
			{
				A_Game_Score++;
				if (A_Game_Score >= 8 && A_Game_Score - B_Game_Score >= 2)
				{
					A_Set_Score++;
					A_Game_Score = 0;
					B_Game_Score = 0;
				}
				A_Ball = 0;
				B_Ball = 0;
			}
			else if (B_Ball == -1)
			{
				A_Ball = 3;
				B_Ball = 3;
			}
			else
			{
				A_Ball++;
				if (A_Ball >= 4)
				{
					if (B_Ball < 3)
					{
						A_Game_Score++;
						if (A_Game_Score >= 8 && A_Game_Score - B_Game_Score >= 2)
						{
							A_Set_Score++;
							A_Game_Score = 0;
							B_Game_Score = 0;
						}
						A_Ball = 0;
						B_Ball = 0;
					}
					else
					{
						A_Ball = -1;
					}
				}
			}
		}
		else
		{
			if (B_Ball == -1)
			{
				B_Game_Score++;
				if (B_Game_Score >= 8 && B_Game_Score - A_Game_Score >= 2)
				{
					B_Set_Score++;
					A_Game_Score = 0;
					B_Game_Score = 0;
				}
				A_Ball = 0;
				B_Ball = 0;
			}
			else if (A_Ball == -1)
			{
				A_Ball = 3;
				B_Ball = 3;
			}
			else
			{
				B_Ball++;
				if (B_Ball >= 4)
				{
					if (A_Ball < 3)
					{
						B_Game_Score++;
						if (B_Game_Score >= 8 && B_Game_Score - A_Game_Score >= 2)
						{
							B_Set_Score++;
							A_Game_Score = 0;
							B_Game_Score = 0;
						}
						A_Ball = 0;
						B_Ball = 0;
					}
					else
					{
						B_Ball = -1;
					}
				}
			}
		}
		printf("  Set:%3d :%3d\n", A_Set_Score, B_Set_Score);
		printf(" Game:%3d :%3d\n", A_Game_Score, B_Game_Score);
		if (A_Ball == -1)
			printf("Point: AD :   \n");
		else if (B_Ball == -1)
			printf("Point:    : AD\n");
		else
			printf("Point:%3d :%3d\n", scores[A_Ball], scores[B_Ball]);
	}
}

int main()
{
	while (scanf("%s",s) !=EOF)
	{
		A_Set_Score = 0;
		B_Set_Score = 0;
		A_Game_Score = 0;
		B_Game_Score = 0;
		A_Ball = 0;
		B_Ball = 0;
		Set_Type = 1;
		Game_Type = 1;
		for (i = 0; i < strlen(s); i++)
		{
			if (Game_Type == 1)
			{
				gt1();
			}
			else if (Game_Type == 2)
			{
				gt2();
			}
			else  //3
			{
				gt3();
			}
			if (A_Game_Score == 5 && B_Game_Score == 5)
			{
				Game_Type = 2;
			}
			if (A_Game_Score == 6 && B_Game_Score == 6)
			{
				Game_Type = 3;
			}
			if (A_Set_Score == 2 && B_Set_Score == 2)
			{
				Set_Type = 2;
			}
			if (A_Set_Score == 3)
			{
				printf("A wins!");
			}
			if (B_Set_Score == 3)
			{
				printf("B wins!");
			}
		}
	}
}