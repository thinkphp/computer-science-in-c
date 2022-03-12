#include <stdio.h>
#include <math.h>

int n;

void show_triangle(int i, int space, int ch) {

     if(i <= n) { 

        for(int k = 0; k <= space; ++k) 
            printf(" ");
        

        for(int k = 1; k <= ch; ++k) 
            printf("*");
        

        printf("\n");

        show_triangle( i + 1, space - 1, ch + 2 );
     }     	
}

int main() {
	
    double num, num2;

    int ch, space;

    printf("n = ");

    scanf("%lf", &num);

    num2 = sqrt( num );     

    if(num2 * num2 == num) {  
         
       space = num2 - 1;

       ch = 1;

       n = (int)num2;
        
       show_triangle(1, space - 1, 1); 

    } else {

      printf("I cannot show the triangle!");
    } 

}
