/*
** main.c for sources in /share/projets/cproglm/rush_sudoku/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  ven. juil. 26 19:53:01 2013 jalil dabbech
** Last update ven. juil. 26 23:37:25 2013 jalil dabbech
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"
#include "my.h"
#include "get_next_line.h"

int		check_line(char *str)
{
  int		i;
  static int	spec_line;
  static int	nbr_line;

  i = 0;
  if (spec_line > 2)
    return (0);
  if (nbr_line == 11)
    my_putstrerror("./sudoku-bi: Too much line.\n", 1);
  while (str[i])
  {
    if (str[i] == '-')
      spec_line++;
    else if ((str[i] <= '0' || str[i] > '9') && str[i] != ' ' &&
	     str[i] != '|' && str[i] != '-')
      return (0);
    else if (i > 20)
      return (0);
    i++;
  }
  nbr_line++;
  if (i != 20)
    return (0);
  return (1);
}

void		replace_space(char *str)
{
  int		i;
  static int	nbr_fig;
  static int	line;

  i = 0;
  while (str[i])
  {
    if (str[i] == 32)
      str[i] = '0';
    else
      nbr_fig++;
    i++;
  }
  line ++;
  if (nbr_fig < 17 && line == 9)
    my_putstrerror("./sudoku-bi: Not enough digits to resolve the grid.\n", 1);
}

char		*clean_str(char *str)
{
  int		i;
  char		*ret;
  int		j;

  if (!check_line(str))
    my_putstrerror("./sudoku-bi: Wrong line.\n", 1);
  ret = my_malloc(9, "malloc grid line.\n");
  i = 0;
  j = 0;
  str[i] = str[i + 1];
  while (str[i])
  {
    str[i] = str[i + 2];
    ret[j] = str[i];
    i+=2;
    j++;
  }
  j--;
  ret[j] = 0;
  replace_space(ret);
  return (ret);
}

void		check_opt(int ac, char **av)
{
  int		i;

  i = 1;
  if (ac == 1)
    return;
  while (i < ac)
  {
    if (my_strcmp(av[i], "-h") == 0)
    {
      my_printf("\033[1;32mUsage: cat <grid> | ./sudoku-bi\n");
      my_printf("Rules:\n\tSudoku is a logic-based, ");
      my_printf("combinatorial number-placement puzzle.\n\t");
      my_printf("The objective is to fill a 9×9 grid with digits so that each");
      my_printf(" column, each row, and each of the nine 3×3 sub-grids that ");
      my_printf("compose the grid contains all of the digits from 1 to 9.\n\t");
      my_printf("The puzzle setter provides a partially completed grid, which");
      my_printf(" typically has a unique solution.\033[0m\n");
    }
    i++;
  }
  exit(EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
  int		i;
  char		*line;
  char		*grid[9];

  i = 0;
  check_opt(ac, av);
  while (i < 11)
  {
    line = get_next_line(0);
    if (i == 0 || i == 10)
    {
      if (my_strcmp(line, "|------------------|") != 0)
	my_putstrerror("./sudoku-bi: Wrong line.\n", 1);
      free(line);
    }
    else
      grid[i - 1] = clean_str(line);
    i++;
  }
  i = 0;
  while (i < 9)
  {
    my_putstr(grid[i]);
    write(1, "\n", 1);
    i++;
  }
  return (0);
}
