#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int fibonacci(int n) {
   int i, j;
   if (n<2)
      return n;
   else {
      #pragma omp task shared(i)
      i=fibonacci(n-1);
      #pragma omp task shared(j)
      j=fibonacci(n-2);
      #pragma omp taskwait
      return i+j;
   }
}


int main(int argc, char **argv){
   int valor = 2;
   int n, resultado;

   char *a = argv[1];
   n = atoi(a);
   
   #pragma omp parallel
   {
      #pragma omp single
      {
          for(int i = 0; i<=n;i++)
          {
              result = fibonacci(n);
              
              result= fibonacci(i);
              printf("fibonacci de (%d) %d =",i,result);
              if(result<5)
              {
                  printf("%d\n",result); 

              }else
              {
                  while (result != 1)
                  {
                      if(result%valor==0)
                      {
                          printf("%d",valor);
                          result=result/valor;
                          if (result != 1)
                          {
                              printf("X");
                          }
                          
                      }else
                      {
                          valor++;
                      }
                      
                  }

                  valor = 2;
                  printf("\n");
                  
              }
              factoredFibonacci(result);

              newResult= factoredFibonacci(result);
              printf("FIB(%d) = %ld\n", i,newResult);
          }
          
      }

      
   }
   printf("Result is %d\n", result);
}


void factoredFibonacci(int numFibonacci) {
    int div = 2;

    if (numFibonacci <= 5) {
        printf("%d", numFibonacci);

    } else {
        while (numFibonacci != 1) {

            if (numFibonacci % div == 0) {
                printf("%d ", div);
                numFibonacci = numFibonacci / div;

                if (numFibonacci != 1)
                    printf("x ");

            } else {
                div++;
            }
        }
    }
}
