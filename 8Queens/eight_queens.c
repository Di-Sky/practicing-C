#define SIZE 8
#include <unistd.h>
#include <stdio.h>

int calc;

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

short	fill_field(int (*f)[SIZE], int j)
{
	int		i;
	int		sol;
	int		ret;

	i = 0;
	ret = 0;
	if (j == SIZE)
		return (1);
	while (i < SIZE)
	{
		while (f[i][j] && i < SIZE)
			i++;
		if (i == SIZE)
			break ;
		put_queen(f, j + 1, i + 1);
		if ((sol = fill_field(f, j + 1)))
			ret += sol;
		erase_queen(f, j, 0);
	}
	return (ret);
}
	
int		ft_eight_queens_puzzle(void)
{
	int		field[SIZE][SIZE];
	int		ans;

	erase_queen(field, -1, 1);
	ans = fill_field(field, 0);
	return (ans);
}

int		main(void)
{
	write(1, "Hello world!\n", 13);
	printf ("%d\n", ft_eight_queens_puzzle());
	return (0);
}