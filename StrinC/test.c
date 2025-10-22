#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct   
{
    char * txt;
    long long len;

}string;

string make_string(char* t)
{
    string a;
    mystrdup(&a,&(string) {t,0});
    return a;
}

// To calculate length
long long int charcount(string *s)
{
    long long  i = 0;

    while(*(s->txt + i) != '\0'){
        i++;
    }
   
    return i;
}
void mystrdup(string *cp,  const string *org)
{
    long long n = charcount(org);
    cp->txt = (char *)malloc(n + 1);    
    
    for(long long int i = 0; i < n; i++)
    {
        cp->txt[i] = org->txt[i];
    }
    cp->txt[n] = '\0';
    cp->len = n;
}


string *mystrcat(string *pre, const string *suf)
{
    long long  n = pre->len;
    long long  m = suf->len;
    pre->txt = realloc(pre->txt, n+m+1);

    for(long long i = n; i < n+m; i++)
    {
        *(pre->txt + i)= *(suf->txt+i-n);
    }
    *(pre->txt + n+m) = '\0';
    pre->len = n+m;
    return pre;
}

int main()
{
    char c;
    int c;
    
    return 0;
}