#include<iostream>
#include<string.h>
using namespace std;
//문제 링크 https://www.acmicpc.net/problem/1080


int main()
{
	int M = 0, N = 0; //M*N Matrix
	int trial = 0;
	printf("Type in the size of Matrix\n");
	scanf("%d %d", &M, &N);
	int** M1 = new int*[M];
	int** M2 = new int*[M];
	int** Check = new int*[M];

	for (int i = 0; i < M; i++)
	{
		M1[i] = new int[N];
		memset(M1[i], 0, sizeof(int)*N);
	}

	
	for (int i = 0; i < M; i++)
	{
		M2[i] = new int[N];
		memset(M2[i], 0, sizeof(int)*N);
	}

	for (int i = 0; i < M; i++)
	{
		Check[i] = new int[N];
		memset(Check[i], 0, sizeof(int)*N);
	}

	printf("Type in the Matrix M1\n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &M1[i][j]);
		}
		printf("\n");
	}


	printf("Type in the Matrix M2\n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &M2[i][j]);
			if (M2[i][j] != M1[i][j])
				Check[i][j] = 1; //다르면 1 같으면 0
			else
				Check[i][j] = 0;
		}
		printf("\n");
	}
	
	

	printf("\n");


	if (M < 3 || N < 3)
	{
		int checking = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				checking += Check[i][j];
			}
		}

		


		if (checking != 0)
		{
			trial = -1;
		}
		
		
		else
		{
			trial = 0;
		}
	}
	else 
	{
		for (int i = 0; i < M - 2; i++)
		{
			for (int j = 0; j < N - 2; j++)
			{
				if (Check[i][j] == 1)
				{
					for (int x = i; x < i + 3; x++)
					{
						for (int y = j; y < j + 3; y++)
						{
							if (Check[x][y] == 0)
								Check[x][y] = 1;
							else
								Check[x][y] = 0;
						}
					}

					trial = trial + 1;


				}

				if (j == N - 3 && (Check[i][j] == 1 || Check[i][j + 1] == 1 || Check[i][j + 2] == 1))
				{
					trial = -1;
					break;
				}
			}
		}
	}

	/*
	printf("\n");


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
		{
			printf(" %d ", Check[i][j]);
		}
		printf("\n");

	}
	*/

	printf("Tried for %d time\n\n\n", trial);
	
	for (int i = 0; i < M; i++)
	{
		delete[]M1[i];
	}

	delete[]M1;

	for (int i = 0; i < M; i++)
	{
		delete[]M2[i];
	}

	delete[]M2;

	for (int i = 0; i < M; i++)
	{
		delete[]Check[i];
	}
	
	delete[]Check;
	
	return 0;
}