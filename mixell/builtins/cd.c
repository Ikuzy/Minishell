

void change_directory(int ac, char **av)
{
    if(ac > 1)
    {
        if(!av[1])
            av[1] = getenv("HOME");
        if(!av[1])
        {
            put_str("HOME not set\n");
            exit(1);
        }
        if(chdir(av[1]) == -1)
        {
            ft_putstr("path invalide");
            exit(1);
        }
    }
}