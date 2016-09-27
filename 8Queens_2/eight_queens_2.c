#define SIZE 8
#include <unistd.h>
#include <stdio.h>

void	put_queen(int (*f)[SIZE], int j, int i)
{
	int		k;

	i--;
	j--;
	f[i][j] = j + 1;
	k = 1;
	while (j + k <SIZE)
	{
		if (!(f[i][j + k]))
			f[i][j + k] = j + 1;
		if (i + k < SIZE && !f[i + k][j + k])
			f[i + k][j + k] = j + 1;
		if (i - k >= 0 && !f[i - k][j + k])
			f[i - k][j + k] = j + 1;
		k++;
	}
}

void	erase_queen(int (*f)[SIZE], int j, short first)
{
	int start;
	int	i;

	start = j;
	i = 0;
	while (i < SIZE)
	{
		j = start;
		while (++j < SIZE)
			if ((f[i][j] > start) || first)
				f[i][j] = 0;
		i++;
	}
}

void	show_field(int (*f)[SIZE])
{
	int		i;
	int		j;
	int		save;
	char	show;

	j = 0;
	while (j < SIZE)
	{
		i = -1;
		while (++i < SIZE)
			if (f[i][j] == j + 1)
				save = i;
		show = (save + 1) % 10 + '0';
		write(1, &show, 1);
		j++;
	}
	write(1, "\n", 1);
}

void	fill_field(int (*f)[SIZE], int j)
{
	int		i;

	i = 0;
	if (j == SIZE)
	{
		show_field(f);
		return ;
	}
	while (i < SIZE)
	{
		while (f[i][j] && i < SIZE)
			i++;
		if (i == SIZE)
			break ;
		put_queen(f, j + 1, i + 1);
		fill_field(f, j + 1);
		erase_queen(f, j, 0);
	}
}
	
void		ft_eight_queens_puzzle_2(void)
{
	int		field[SIZE][SIZE];

	erase_queen(field, -1, 1);
	fill_field(field, 0);
}

int		main(void)
{
	ft_eight_queens_puzzle_2();
	return (0);
}