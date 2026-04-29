#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char SYMBOLS[] = {'.', '-', '=', '+', '%', '&', '#', '@'};

typedef struct
{
    char flagopt;
    char* description;
    int has_val; // 0 or 1
} optflag;

optflag OPTINFO[] = {
    {'?', "Lists all available options for the program", 0},
    {'h', "Specifies a desired display height for the image to be shown", 1},
    {'w', "Specifies a desired display width for the image to be show.", 1},
};

char *OPTS = ":?w:h:";


int main(int argc, char** argv)
{
    // Ensure correct usage
    int opt;

    while ((opt = getopt(argc, argv, OPTS)) != -1)
    {
        switch (opt) {
            case ':':
                printf("Missing value for -%c\n", optopt);
                return 1;

            case '?':
                if (optopt == '?')
                {
                    for (int i = 0, len = sizeof(OPTINFO) / sizeof(OPTINFO[0]); i < len; i++)
                    {
                        optflag cur_opt = OPTINFO[i];

                        printf("-%c: %s. ", cur_opt.flagopt, cur_opt.description);

                        if (cur_opt.has_val) {printf("Option must take a value.\n");}
                        else {printf("Option does not take a value.\n");}
                    }
                }
                else
                {
                    printf("Unrecognised option. Use the -? option for more information.\n");
                }
                return 2;
            default:
                printf("Correct usage: ./bmshoe [opt1, opt2, ...] file.bmp. Use the -? option for more information.\n");
                return 3;
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