# include "expander.h"

char    *ft_search(char **p1, char **p2, char *str)
{
    int k;
    //char *str_copy;

    k = 0;
    while (p1[k] != NULL)
    {
        if (strncmp(str, p1[k], strlen(p1[k])) == 0 && (strlen(p1[k]) == (strlen(str))))
        {
            break; 
        }
        k++;
    }
    return (ft_strdup(p2[k]));
}

char *expand_tilde(char *str, char **p1, char **p2)
{
    int    i;
    int j;
    int n;
    int k;
    int    l;
    char *str_tilde;
    char *str_expanded;

    i = 0;
    j = 0;
    n = 0;
    k = 0;
    l = 0;
    printf("inside str_tilde\n");
    while(str[i] != 0)
    {
        if(str[i] == '~' && (isspace(str[i + 1]) || str[i + 1] == ':' || str[i + 1] == '/' || str[i + 1] == 0))
            n++;
        i++;
    }
    printf("str inside str_tilde is : %s\n", str);
    printf("n inside str_tilde is : %d\n", n);
    if (n == 0)
    {    
        printf("n is 0\n");
        return(str);
    }
    if (n > 0)
    {
        str_tilde = ft_search(p1, p2, "HOME");
        printf("str_tilde is : %s\n", str_tilde);
        str_expanded = calloc ((strlen(str_tilde) * n) + strlen(str) - n + 1, sizeof(char));
        int tmp = (strlen(str_tilde) * n) + strlen(str) - n;
        printf("tmp is %d\n", tmp);
        while(l < tmp) //(ft_strlen(str_tilde) * n) + ft_strlen(str) - n)
        {
            if (str[j] == '~' && (isspace(str[j + 1]) || str[j + 1] == ':' || str[j + 1] == '/' || str[j + 1] == 0))
            {
                k = 0;
                printf("inside if statement tilde expand_tilde\n");
                while(str_tilde[k] != 0)
                {
                    printf("inside while loop tilde expand_tilde\n");
                    str_expanded[l] = str_tilde[k];
                    l++;
                    k++;
                }
                j++;
            }
            str_expanded[l] = str[j];
            j++;
            l++;
        }
        free(str_tilde);
        printf("str_expanded before returning in expand_tilde : %s\n", str_expanded);
        return (str_expanded);
    }
    else
    {
        printf("else was triggered\n");
        return (str);
    }
}
