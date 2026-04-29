#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char SYMBOLS[] = {'.', '-', '=', '+', '%', '&', '#', '@'};
char *OPTS = "?w:h:";

int main(int argc, char** argv)
{
    // Ensure correct usage
    int opt;

    while ((opt = getopt(argc, argv, OPTS) != -1))
    {
        switch (opt) {
            case '?':
                
            
            default:
                printf("Correct usage: ./bmshoe file.bmp {opt1, opt2, ...}. Use the --help flag for more information.\n");
                return 1;
        }
    }
        
    // Open .bmp file for reading
    char* f_name = argv[1];
    FILE* f = fopen(f_name, "r");
    if (f == NULL)
    {
        printf("Could not open %s.", f_name);
        return 1;
    }
}