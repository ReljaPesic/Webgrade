#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){
  int n;
  if(scanf("%d", &n) != 1 || n < 2 || n > 100) {
    printf("-1\n");
    return 1;
  }
  
  int niz[n];
  
  for(int i = 0; i < n; i++) {
    scanf("%d", &niz[i]);
  }
  
  double zbir_parnih = 0;
  double zbir_kvadrata_neparnih = 0;
  int br_parnih = 0;
  int br_neparnih = 0;
  for(int i = 0; i < n; i++) {
    if(i % 2 == 0) {
      zbir_parnih += niz[i];
      br_parnih++;
    } else {
      zbir_kvadrata_neparnih += pow(niz[i], 2);
      br_neparnih++;
    }
  }    
  zbir_parnih /= br_parnih;
  zbir_kvadrata_neparnih /= br_neparnih;
  
  zbir_kvadrata_neparnih = sqrt(zbir_kvadrata_neparnih);
  

  printf("%.2f\n", zbir_parnih + zbir_kvadrata_neparnih);
  return 0;
}
