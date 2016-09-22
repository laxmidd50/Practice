#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SudokuSolver.h"

static int SolveHelper(char* const board, int row, int col);
static void PrintBoard(const char* const board);
static int ValidDigit(const char* const board, int row, int col, int digit);
static int boxsize, n;

int Solve(char* const board, int puzzle_size)
{
	n = puzzle_size;
	boxsize = sqrt((double)n);
	if (n != boxsize*boxsize)
		return;
	PrintBoard((char*)board);
	if (SolveHelper(board, 0, 0))
	{
		PrintBoard(board);
		return 1;
	}
	else
	{
		printf("Can't be solved!\n");
		return 0;
	}
}

static int SolveHelper(char* const board, int row, int col)
{
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
		return 1;

	int digit, result = 0;
	for (digit = 1; digit <= n && !result; digit++)
	{
		if (ValidDigit(board, row, col, digit))
		{
			board[row*n+col] = digit;
			if (SolveHelper(board, row, col))
			{
				return 1;
			}
		}
	}
	board[row*n+col] = 0;
	return 0;
}

static void PrintBoard(const char* const board)
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

static int ValidDigit(const char* const board, int row, int col, int digit)
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
