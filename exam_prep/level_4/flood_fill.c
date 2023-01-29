#include "flood_fill.h"
/*
Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone
by replacing characters inside with the character 'F'. A zone is an group of
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this:

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
*/

void flood_fill(char **area, t_point size, t_point begin)
{
    char curr_char = area[begin.y][begin.x];
    area[begin.y][begin.x] = 'F';
    if (begin.x > 0 && area[begin.y][begin.x - 1] == curr_char)
        flood_fill(area, size, (t_point) {begin.x - 1, begin.y});
    if (begin.x < size.x - 1 && area[begin.y][begin.x + 1] == curr_char)
        flood_fill(area, size, (t_point) {begin.x + 1, begin.y});
    if (begin.y > 0 && area[begin.y - 1][begin.x] == curr_char)
        flood_fill(area, size, (t_point) {begin.x, begin.y - 1});
    if (begin.y < size.y - 1 && area[begin.y + 1][begin.x] == curr_char)
        flood_fill(area, size, (t_point) {begin.x, begin.y + 1});
}

#include <stdlib.h>
#include <stdio.h>
char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}