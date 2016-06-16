#include <string.h>

// http://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html

int match(char *regexp, char *text);
int matchhere(char *regexp, char *text);
int matchstar(int c, char *regexp, char *text);

/* match: search for regexp anywhere in text */
/*@
requires ((strlen(regexp)>=0) && \valid(regexp+(0..(strlen(regexp)+1)-1)));
requires ((strlen(text)>=0) && \valid(text+(0..(strlen(text)+1)-1)));
assigns \nothing;
*/
int match(char *regexp, char *text)
{
  if (regexp[0] == '^')
    return matchhere(regexp+1, text);
  /*@
  loop invariant ((strlen(regexp)>=0) && \valid(regexp+(0..(strlen(regexp)+1)-1)));
  loop invariant ((strlen(text)>=0) && \valid(text+(0..(strlen(text)+1)-1)));
  loop assigns text;
  loop variant strlen(text);
  */
  do {    /* must look even if string is empty */
    if (matchhere(regexp, text))
      return 1;
  } while (*text++ != '\0');
  return 0;
}

/* matchhere: search for regexp at beginning of text */
/*@
requires ((strlen(regexp)>=0) && \valid(regexp+(0..(strlen(regexp)+1)-1)));
requires ((strlen(text)>=0) && \valid(text+(0..(strlen(text)+1)-1)));
assigns \nothing;
*/
int matchhere(char *regexp, char *text)
{
  if (regexp[0] == '\0')
    return 1;
  if (regexp[1] == '*')
    return matchstar(regexp[0], regexp+2, text);
  if (regexp[0] == '$' && regexp[1] == '\0')
    return *text == '\0';
  if (*text!='\0' && (regexp[0]=='.' || regexp[0]==*text)) {
    //@assert regexp[0]!='\0';
    return matchhere(regexp+1, text+1);
  }
  return 0;
}

/* matchstar: search for c*regexp at beginning of text */
/*@
requires ((strlen(regexp)>=0) && \valid(regexp+(0..(strlen(regexp)+1)-1)));
requires ((strlen(text)>=0) && \valid(text+(0..(strlen(text)+1)-1)));
assigns \nothing;
*/
int matchstar(int c, char *regexp, char *text)
{
  /*@
  loop invariant ((strlen(regexp)>=0) && \valid(regexp+(0..(strlen(regexp)+1)-1)));
  loop invariant ((strlen(text)>=0) && \valid(text+(0..(strlen(text)+1)-1)));
  loop assigns text;
  loop variant strlen(text);
  */
  do {    /* a * matches zero or more instances */
    if (matchhere(regexp, text))
      return 1;
  } while (*text != '\0' && (*text++ == c || c == '.'));
  return 0;
}
