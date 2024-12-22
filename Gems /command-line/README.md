
# Command line arguments


```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Print total number of arguments
    printf("Number of arguments (argc): %d\n\n", argc);
    
    // Print all arguments
    printf("All arguments (argv):\n");
    for(int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    
    // Example: Program that adds two numbers from command line
    if(argc == 3) {
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);
        printf("\nSum of %d and %d is: %d\n", num1, num2, num1 + num2);
    }
    
    return 0;
}

```

Let me explain the key concepts:

1. `argc` (Argument Count):
   - This is an integer that represents the number of arguments passed to the program
   - It's always at least 1 because `argv[0]` is the program name itself
   - For example, if you run: `./program arg1 arg2`, argc would be 3

2. `argv` (Argument Vector):
   - This is an array of strings (char pointers)
   - `argv[0]` is always the program name/path
   - `argv[1]` is the first actual argument
   - `argv[argc-1]` is the last argument

Here's how to compile and run the program:
```bash
gcc program.c -o program
./program hello world
```

This would output:
```
Number of arguments (argc): 3

All arguments (argv):
argv[0]: ./program
argv[1]: hello
argv[2]: world
```

Common uses for command line arguments:
1. Passing configuration options
2. Specifying input/output files
3. Setting program modes or flags
4. Providing initial values

Here's a simple example of how you might use it in practice:
```c
if(argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
}
// Use argv[1] as filename
```

