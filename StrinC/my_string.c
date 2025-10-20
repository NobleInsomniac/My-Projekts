#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define min(a,b) ( ((a)<(b)) ? a : b )

typedef struct   
{
    char * txt;
    long long len;

}string;

// length of string
long long charcount(const string *s);
// copy  string 
void mystrdup( string *cp,  const string *org);
// compare two string
int my_strcmp(const string *s1, const string *s2);
// lower case a string
string con_lower(const string *s);
// free dynamically allocated memory
void free_string(string *s);
// comncatinate two strings
string my_strcat(const string *, const string *);
// search for a charcter in string by linear search
bool lstrsearch(const string *s, const char c);
// returns a slice (of length l)of the given string starting from the  character at the 'start' position(assuming the string is 0-indexed)
string *slicer(const string* s, int i, int l);
// return a pointer to the first occurence of the substring in the given string
string *my_substrsearch( const string *, const string *);
//return a pointer to the first occcurence of the given char in a string
string *my_charsearch(const string *, const char );
//return a pointer to the last occcurence of the given char in a string
string *my_rcharsearch(const string *, const char );
// gives no of occurencexs of a char
long long int occ_count(const string *, const char);
// #TODO Tokenize the string i.e. implement .split() in c
string** splitter(const string* , char);
string make_string( char * t)
{
    string a;
    a.txt = t;
    a.len = charcount(&a);
    return a;
}

// To calculate length
long long charcount(const string *s)
{
    long long  i = 0;

    while(s->txt[i] != '\0')
    {
        i++;
    }
   
    return i;
}

// to copy string
void mystrdup(string *cp,  const string *org)
{
    long long n = org->len;
    //fuck gotta rm this 
    cp->txt = (char *)malloc(n + 1);    
    
    for(int i = 0; i < n + 1; i++)
    {
        cp->txt[i] = org->txt[i];
    }
    cp->len = n;
}
// comparsion

int my_strcmp(const string *s1, const string *s2)
{
    // -1 means s1 is lexographically smaller than s2
    // 1 means s1 is lexographically larger than s2
    // 0 means equal
   
    int n = min(s1->len, s2->len);
    for(int i = 0; i < n; i++)
    {
        if (s1->txt[i] < s2->txt[i])
        {
            return -1;
        }
        else if(s1->txt[i] > s2->txt[i])
        {
            return 1;
        }
    }
    
    if(s1->len < s2->len)
    { 
    return -1;
    } 

    else if (s1->len > s2->len)
    {
        return 1;
    }

    return 0;
}

// lower case a string
string con_lower(const string *s)
{
    string lowstr;
    int l = charcount(s);
    lowstr.txt = (char *)malloc(l + 1);

    for (int i = 0; i < l; i++)
    {

        if (s->txt[i] >= 'A' && s->txt[i] <= 'Z')
            lowstr.txt[i] = s->txt[i] + 32;

        else
            lowstr.txt[i] = s->txt[i];
    }

    lowstr.txt[l] = '\0';  
    lowstr.len = l;
    return lowstr;
}

void free_string(string *s) {
    free(s->txt);
    s->txt = NULL;
    s->len = 0;
}
//Works fine
string *mystrcat(const string *pre, const string *suf)
{

    string *res = malloc(sizeof(string));

    long long  n = pre->len;
    long long  m = suf->len;

    res->txt = (char *)malloc(n + m + 2);

    for(long long  i = 0;i < n; i++)
    {
        *(res->txt+i) = *(pre->txt + i); 
    }

    for (long long  j = n; j < n+m; j++)
    {
       *(res->txt +j) = *(suf->txt+ j - n);
    }

   *(res->txt + n + m + 1) = '\0';
    res->len = charcount(res);

    return res;
 
}
// find a character with linear search
bool lstrsearch(const string *s, char c)
{
    long long int n = s->len;
    for(int i = 0; i < n;i++)
    {
        if (*(s->txt + i)  == c)
        {
            return true;
        }
    }
    return false;
}
// Return a slice of the given string starting from start of length  l
string *slicer(const string* s, int start, int l)
{
    string *slice = malloc(sizeof(string));
    slice->txt = (char*)malloc(l+1);
    long long int n = s->len;
    for(int i = 0; i < l; i++)
    {
        *(slice->txt + i) = *(s->txt+ start + i);
    }
    slice->len = l;
    return slice;

}
//Return a pointer to the place where the substring occurs in a string
string *my_substrsearch(const string *needle, const string *haystack)
{

    long long int n = haystack->len;
     long long int k = needle->len;
     if (k == 0)
     {
         return slicer((string *)haystack, 0,0);
     }
    for (long long int i = 0; i <= n - k; i++)
    {
        long long int j;
        if (*(haystack->txt + i)  == *(needle->txt))
        {
            for ( j = 0; j < k;j++)
            {
                if (*(haystack->txt + i + j)  != *(needle->txt + j))
                {
                    break;
                }

                
            }
            if (j == k)
                {
                    return slicer((string *)haystack, i, needle->len);
                }
        }
    }
    return NULL;
}
//return the first occurence of the character c in the string s
string *my_charsearch(const string *s, const char c)
{
    string* res;
    long long int n = s->len;
    for(long long int i = 0; i < n; i++)
    {
        if(*(s->txt + i) == c)
        {
            res->txt = s->txt + i;
            
            return res;
        }
    }

return NULL;
}
//return the lsat occurence of the character c in the string s
string *my_rcharsearch(const string *s, const char c)
{
    string* res;
    long long int n = s->len;
    for(long long int i = n-2; i >= 0; i--)
    {
        if(*(s->txt + i) == c)
        {
            res->txt = s->txt + i;
            return res;
        }
    }

return NULL;
}
// gives no of occurencexs of a char
long long int occ_count(const string *s, const char c)
{
    long long int n = s->len;
    long long int count = 0;

    for(long long int i = 0; i < n; i++)
    {
        if(*(s->txt + i) == c)
        {
            count++;
        }
    }
    return count;
}
// #TODO debug
string** splitter(const string* s, char dlr)
{
    long long int occ = occ_count(s, dlr);
    
    long long int n = s->len;

    string* slices[] = (string *)malloc(occ+1);

    long long int start = 0, c = 0;
    for(long long int i = 0; i < n+1;i++)
    {
        if (*(s->txt + i) == dlr)
        {
            
            *(slices[c]) = *(slicer(s, start,i-start));
            i += 1;
            start = i;
            c++;
        }
        else if(*(s->txt + i) == '\0')
        {
            *(slices[c]) = *(slicer(s, start,i-start));
            i += 1;
            start = i;
            c++; 
        }

    }
    return slices;
}

//int main (int argc, char* argv[])
int main()
{
    /*if (argc < 2)
    {
        return 1;
    }*/

    /*
    // Create string a and set its text
    string a;
    //a.txt = "Hello";
    // Print the length of string a
    printf("%lli\n", charcount(&a));
    long long len = charcount(&a);

    // Create string b and set its text
    string b;
    b.txt = "Yellow";

    // Uncomment to copy string a into b and print results
    
    mystrdup(&b, &a);
    printf("%lli\n", len);
    printf("%s\n", b.txt);
    

    // Compare strings a and b, print comparison result
    bool res = my_strcmp(&a, &b);
    printf("%d\n", res);

    // Uncomment to convert string a to lowercase and print result
    //char * gh = con_lower(&a);
    //printf("%s\n", gh);

    return 0;


    string a;
    string b;

     a.txt = "Hello";
     a.len = charcount(&a);
     b.txt = " World!";
     b.len = charcount(&b);
     
     string *a_ptr = &a;
     string *b_ptr = &b;

     string *r = mystrcat(a_ptr,b_ptr);

     printf("%s\n",r->txt);

     free_string(r);
     return 0;
        */
   // string a;
   //a.txt = "Pikachu";
   //a.len = charcount(&a);
   // printf("%d\n",lstrsearch(&a, *argv[1]));

   /* string a;
    a.txt = "i hate my life";
    a.len = charcount(&a);
    string c;
    c.txt = "hate";
    c.len = charcount(&c);
    string *b;
    b = my_substrsearch(&c, &a);
    if (b == NULL)
    {
        printf("NULL\n");
        return 1;
    }
    printf("%s", b->txt);
   */
  string *a;
  a->txt = "hello cat";
  a->len = charcount(a);
 string ** b=  ((splitter(a,' ')));
 printf("%s\n", *(*(b))->txt);
    return 0;
}