#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
// check if there is an argument
if (argc > 1)
{
// convert the argument to a double
double d = atof(argv[1]);
// print the result
printf("The double value of %s is %lf\n", argv[1], d);
}
else
{
// print an error message
printf("No argument given\n");
}
return 0;
}
