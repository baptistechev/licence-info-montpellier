#include <stdio.h>
char *s;
void g(void){printf("%c\n",s[0]);} // génère signal SIGSEGV
void f(void){g();}
int main(){f();}
