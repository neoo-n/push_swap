int	ft_tabintsize(int *tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}
#include <stdio.h>
int main(void)
{
	int tab[2] = {1, 0};
	printf("%i\n", ft_tabintsize(tab));
	return (0);
}