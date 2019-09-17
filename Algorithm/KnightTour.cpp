#include <iostream> 
#include <cstdlib>
#include <ctime>
#define N 8 

static int biasX[N] = { 1,1,2,2,-1,-1,-2,-2 };
static int biasY[N] = { 2,-2,1,-1,2,-2,1,-1 };

bool isAvailable(int a[], int x, int y)
{
	return (x >= 0 && y >= 0) && (x < N && y < N) && (a[y*N + x] < 0);
}

int getAvailCount(int a[], int x, int y)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
		if (isAvailable(a, (x + biasX[i]), (y + biasY[i])))
			count++;

	return count;
}

bool nextMove(int a[], int *x, int *y)
{
	int minDegIdx = -1, c, minDeg = (N + 1), nx, ny;

	int start = rand() % N;
	for (int count = 0; count < N; ++count)
	{
		int i = (start + count) % N;
		nx = *x + biasX[i];
		ny = *y + biasY[i];
		if ((isAvailable(a, nx, ny)) &&
			(c = getAvailCount(a, nx, ny)) < minDeg)
		{
			minDegIdx = i;
			minDeg = c;
		}
	}

	if (minDegIdx == -1)
		return false;

	nx = *x + biasX[minDegIdx];
	ny = *y + biasY[minDegIdx];

	a[ny*N + nx] = a[(*y)*N + (*x)] + 1;

	*x = nx;
	*y = ny;

	return true;
}

void print(int a[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			printf("%d\t", a[j*N + i]);
		printf("\n");
	}
}

bool neighbour(int x, int y, int xx, int yy)
{
	for (int i = 0; i < N; ++i)
		if (((x + biasX[i]) == xx) && ((y + biasY[i]) == yy))
			return true;

	return false;
}

bool findClosedTour(int sx, int sy) {
	int a[N*N];
	for (int i = 0; i < N*N; ++i)
		a[i] = -1;


	int x = sx, y = sy;
	a[y*N + x] = 1;

	for (int i = 0; i < N*N - 1; ++i)
		if (nextMove(a, &x, &y) == 0)
			return false;

	if (!neighbour(x, y, sx, sy))
		return false;

	print(a);
	return true;
}
bool findClosedTour()
{
	int sx = rand() % N;
	int sy = rand() % N;

	return findClosedTour(sx, sy);
}

int main()
{
	srand(time(NULL));

	while (!findClosedTour());

	return 0;
}