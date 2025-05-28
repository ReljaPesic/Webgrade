#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* podniska(char* s1, char*s2);

int main() {
  char s1[64];
  char s2[64];

  scanf("%s %s", s1, s2);
  char* pocetak = podniska(s1, s2);
  
  if(pocetak == NULL) printf("-1\n"); 
  else {
    char * resenje = pocetak - strlen(s1);
    printf("%ld\n", resenje - s2);
  }
 return 0;
}

char* podniska(char* s1, char*s2) {
    if(*s1 == '\0') return s2;  //nasli resenje
    if(*s2 == '\0') return NULL; //nismo nasli resenje ili greska
    if(*s1 == *s2) {
      if(*(s1 + 1) != *(s2 + 1)) {
        return 
      }
      return podniska(s1 + 1, s2 + 1);
    }
    if(*s1 != *s2) return podniska(s1, s2 + 1);
}
int isti(char* s1, char* s2) {

}
