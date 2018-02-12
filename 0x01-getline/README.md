#Holberton School - Getline

## Description of Files

<h3>_Allowed Functions:_</h3>
<pre><code>
read
write
malloc
free
strcpy
strncpy
strcat
strdup
memset
memcpy
</code></pre>

### Sample Main:
<pre><code>
int main(int ac, char *argv[])
{
    int fd;
    char *line;

    if (ac != 2)
        return (1);
    fd = open(argv[1], 0);
    line = NULL;
    while ((line = _getline(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    fd2 = open(argv[2], 0);
    while ((line = _getline(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    free(line);
    close(fd);
    return (0);
}
</code></pre>
