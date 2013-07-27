/*
** aff_grid.c for sources in /share/projets/cproglm/rush_sudoku/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  sam. juil. 27 18:31:12 2013 jalil dabbech
** Last update sam. juil. 27 19:09:50 2013 jalil dabbech
*/

#include "my.h"

/*
char	grid[9][9] = 
{
  {'2', '5', '8', '3', '7', '4', '1', '6', '9'},
  {'1', '7', '9', '5', '8', '6', '2', '4', '3'},
  {'3', '4', '6', '2', '9', '1', '7', '8', '5'},
  {'7', '2', '4', '6', '3', '9', '8', '5', '1'},
  {'8', '1', '5', '4', '2', '7', '9', '3', '6'},
  {'9', '6', '3', '8', '1', '5', '4', '2', '7'},
  {'4', '3', '7', '1', '6', '8', '5', '9', '2'},
  {'6', '8', '1', '9', '5', '2', '3', '7', '4'},
  {'5', '9', '2', '7', '4', '3', '6', '1', '8'}
};
*/

void		put_the_delimiteur()
{
  write(1, " ######DELIMIT##### \n", 21);
}

void		aff_the_grid(char **grid)
{
  int		i;
  int		j;
  static int	nb_grid;

  i = 0;
  write(1, "|------------------|\n", 21);
  while (i < 9)
  {
    j = 0;
    write(1, "| ", 2);
    while (j < 9)
    {
      write(1, &(grid[i][j]), 1);
      if (j != 8)
	write(1, " ", 1);
      else
	write(1, "|\n", 2);
      j++;
    }
    i++;
  }
  write(1, "|------------------|\n", 21);
  nb_grid++;
}
