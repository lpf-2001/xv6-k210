#include "include/types.h"

void*
memset(void *dst, int c, uint n)
{
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
    cdst[i] = c;
  }
  return dst;
}

int
memcmp(const void *v1, const void *v2, uint n)
{
  const uchar *s1, *s2;

  s1 = v1;
  s2 = v2;
  while(n-- > 0){
    if(*s1 != *s2)
      return *s1 - *s2;
    s1++, s2++;
  }

  return 0;
}

void*
memmove(void *dst, const void *src, uint n)
{
  const char *s;
  char *d;

  s = src;
  d = dst;
  if(s < d && s + n > d){
    s += n;
    d += n;
    while(n-- > 0)
      *--d = *--s;
  } else
    while(n-- > 0)
      *d++ = *s++;

  return dst;
}

// memcpy exists to placate GCC.  Use memmove.
void*
memcpy(void *dst, const void *src, uint n)
{
  return memmove(dst, src, n);
}

int
strncmp(const char *p, const char *q, uint n)
{
  while(n > 0 && *p && *p == *q)
    n--, p++, q++;
  if(n == 0)
    return 0;
  return (uchar)*p - (uchar)*q;
}

char*
strncpy(char *s, const char *t, int n)
{
  char *os;

  os = s;
  while(n-- > 0 && (*s++ = *t++) != 0)
    ;
  while(n-- > 0)
    *s++ = 0;
  return os;
}

// Like strncpy but guaranteed to NUL-terminate.
char*
safestrcpy(char *s, const char *t, int n)
{
  char *os;

  os = s;
  if(n <= 0)
    return os;
  while(--n > 0 && (*s++ = *t++) != 0)
    ;
  *s = 0;
  return os;
}

int
strlen(const char *s)
{
  int n;

  for(n = 0; s[n]; n++)
    ;
  return n;
}

// convert uchar string into wide char string 
void wnstr(wchar *dst, char const *src, int len) {
  while (len -- && *src) {
    *(uchar*)dst = *src++;
    dst ++;
  }

  *dst = 0;
}

// convert wide char string into uchar string 
void snstr(char *dst, wchar const *src, int len) {
  while (len -- && *src) {
    *dst++ = (uchar)(*src & 0xff);
    src ++;
  }
  while(len-- > 0)
    *dst++ = 0;
}

int wcsncmp(wchar const *s1, wchar const *s2, int len) {
  int ret = 0;

  while (len-- && *s1) {
    ret = (int)(*s1++ - *s2++);
    if (ret) break;
  }

  return ret;
}

char*
strchr(const char *s, char c)
{
  for(; *s; s++)
    if(*s == c)
      return (char*)s;
  return 0;
}

char*
fmtname(char* name)
{
    static char buf[32 + 1];
    int len = strlen(name);

    // Return blank-padded name.
    if (len >= 32)
        return name;
    memmove(buf, name, len);
    memset(buf + len, ' ', 32 - len);
    buf[32] = '\0';
    return buf;
}

void itoa(uint n, char* s)
{
    int i, sign;
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    int  j;
    char c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


//changed
char* strcat(char* dest, const char* src)
{
    if (dest == NULL || src == NULL) {
        return NULL;
    }  //±£Ö¤dest¡¢src·Ç¿Õ
    char* ret = dest;    //½«destÊ×µØÖ·´¢´æÔÚretÖÐ£¬ÔÚÖºódest++ÔËËãÖÐ£¬¿ÉÒÔ·½±ãÕÒµ½
    while (*dest != '\0')  //ÓÃÖ¸ÕëÍùºóÒ»¸ö¸öÕÒ£¬ÕÒµ½dest½áÎ²µÄ¡\0¡¯
        dest++;
    while ((*dest++ = *src++) != '\0')//°ÑsrcÀïµÄ×Ö·ûÒ»¸ö¸ö·ÅÈëdestºó
        ;
    return ret;  //·µ»Ødest×Ö·û´ÆðÊ¼µØÖ·
}
//changed


int atoi(const char* str)
{
    int s = 0;
    int flag = 0;
    while (*str == ' ')
    {
        str++;
    }

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            flag = 1;
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        s = s * 10 + *str - '0';
        str++;
        if (s < 0)
        {
            s = 2147483647;
            break;
        }
    }
    return s * (flag ? -1 : 1);
}
