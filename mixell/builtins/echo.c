

void echo(int ac, char **av)
{
    int n_line ;
    int start_i ;

    n_line = 1;
    start_i = 1;
    if(ac > 1 && av[1][0] == '-' && av[1][1] == 'n')
    {
        n_line = 0;
        start_i++;
    }

    while(start_i < ac)
    {
        ft_putstr(av[start_i]);
        if(start_i < ac - 1)
            write(1, " ", 1);
        start_i++;
    }

    if(n_line)
        write(1, "\n", 1);
}