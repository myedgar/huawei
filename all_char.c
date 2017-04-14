#include <stdio.h>
#include <string.h>

#define M 1000

int main()
{
    char str[M];
    while(scanf("%s", str) != EOF)
    {
        int i;
        char a[26] = {0};
        char b[26] = {0};
        int length = strlen(str);
        for(i = 0; i < length; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                if(a[str[i]-'a'] == 0)
                {
                    printf("%c", str[i]);
                    a[str[i]-'a'] = 1;
                }
            }
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                if(b[str[i]-'A'] == 0)
                {
                    printf("%c", str[i]);
                    b[str[i]-'A'] = 1;
                }
            }
        }
        printf("\n");
    }
}
