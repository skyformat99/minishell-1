
int     main(void)
{
    int     fd;
    char    *buf = NULL;
    
    fd  = open("Readme.txt", O_RDONLY);
    (void)fd;
    while (get_next_line(42, &buf) == 1)
    {
        printf("%s\n", buf);
    }
    close(fd);
    return (0);
}
