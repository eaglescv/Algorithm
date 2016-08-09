#include "MazeSolver.h"

void main(int argc, char* argv[])
{
	int i = 0;
	int j = 0;


	MazeInfo Maze;
	if (argc < 2)
	{
		printf("Usage: MazeSolver <MazeFile>\n");
		return;
	}

	if (GetMaze(argv[1], &Maze) == FAIL)
	{
		return;
	}

	if (Solve(&Maze) == FAIL)
	{
		return;
	}

	for (i = 0; i < Maze.RowSize; ++i)
	{
		for (j = 0; j < Maze.ColumnSize; ++j)
		{
			printf("%c", Maze.Data[i][j]);
		}
		printf("\n");
	}
	
	getchar();
}
