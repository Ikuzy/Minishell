

void pwd_(void)
{
    char tab[1000];
    getcwd(tab, 1000);
    ft_putstr(tab);
    exit(0);
}