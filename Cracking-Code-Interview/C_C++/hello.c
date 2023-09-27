#include <stdio.h>

#define MAX(x,y) x > y ? x : y
#define Square(x) ((x) * (x))
#define message(a,b) \
   printf(#a " and " #b " : we love you! \n")
#define tokenpster(n) printf("token" #n " = %d", token##n)

int main(){

   // printf("Max between 20 and 10 is %d\n", MAX(10, 20));
   // printf("The square is: %d\n", Square(2)); 
   // message(Moses, William);
   int token34 = 40; 
   tokenpster(34);
   return 0;
}
