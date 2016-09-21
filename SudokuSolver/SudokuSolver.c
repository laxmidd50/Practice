#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SudokuSolver.h"

void Solve(const char* const board, int n);
char* SolveHelper(const char* const board, int n, int row, int col);
void PrintBoard(const char* const board, int n);
char* MakeCopyBoard(const char* const board, int n);
int ValidDigit(const char* const board, int n, int row, int col, int digit);

int boxsize;

void Solve(const char* const board, int n)
{
	boxsize = sqrt((double)n);
	if (n != boxsize*boxsize)
		return;
	PrintBoard((char*)board, n);
	char* result = SolveHelper(board, n, 0, 0);
	if (result != NULL)
	{
		PrintBoard(result, n);
		free(result);
	}
	else
	{
		printf("Can't be solved!\n");
	}
}

char* SolveHelper(const char* const board, int n, int row, int col)
{
	char* board2 = MakeCopyBoard(board, n);
	while (row < n && board[row*n+col] != 0)
	{
		col++;
		if (col >= n)
		{
			row++;
			col = 0;
		}
	}
	if (row >= n)
		return board2;

	int digit;
	char * result = NULL;
	for (digit = 1; digit <= n && result == NULL; digit++)
	{
		if (ValidDigit(board2, n, row, col, digit))
		{
			board2[row*n+col] = digit;
			result = SolveHelper(board2, n, row, col);
		}
	}
	free(board2);
	return result;
}

void PrintBoard(const char* const board, int n)
{
	int row, col;
	for (row = 0; row < n; row++)
	{
		if (row != 0 && row%boxsize == 0)
		{
			for (col = 0; col < n+(n/boxsize-1)*boxsize; col++)
				printf("-");
			printf("\n");
		}
		for (col = 0; col < n; col++)
		{
			if (col != 0 && col%boxsize == 0)
				printf(" | ");
			if (board[row*n+col] == 0)
				printf(".");
			else
				printf("%d", board[row*n+col]);
		}
		printf("\n");
	}
	printf("\n\n");
}

char* MakeCopyBoard(const char* const board, int n)
{
	char* newboard = malloc(sizeof(char)*n*n);
	if (newboard == NULL)
	{
		printf("Malloc error\n");
		exit(1);
	}
	int row, col;
	for (row = 0; row < n; row++)
		for (col = 0; col < n; col++)
			newboard[row*n+col] = board[row*n+col];
	return newboard;
}


int ValidDigit(const char* const board, int n, int row, int col, int digit)
{
	//printf("%d %d %d %d %p\n", n, row, col, digit, board);
	if (digit > n || digit < 1)
		return 0;

	int i,j;
	for (i = 0; i < n; i++)
	{
		// Check row for duplicates
		if (i != col && board[row*n+i] == digit)
			return 0;

		// Check col for duplicates
		if (i != row && board[i*n+col] == digit)
			return 0;
	}

	int square_col = col/boxsize*boxsize;
	int square_row = row/boxsize*boxsize;

	for (i = square_row; i < square_row+boxsize; i++)
	{
		for (j = square_col; j < square_col+boxsize; j++)
		{
			if ((i != row || j != col) && board[i*n+j] == digit)
			{
				return 0;
			}
		}
	}

	return 1;
}
