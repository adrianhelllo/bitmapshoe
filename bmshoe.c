#include <stdio.h>
#include <string.h>

const char SYMBOLS[] = {'.', '-', '=', '+'};

int main(int argc, char** argv)
{
    // Ensure correct usage
    if (argc != 2)
    {
        printf("Correct usage: ./bmshoe file.bmp\n");
        return 1;
    }

    // Open .bmp file for reading
    char* f_name = argv[1];
    FILE* f = fopen(f_name, "r");
    if (f == NULL)
    {
        printf("Could not open %s.", f_name);
        return 1;
    }

    // Find file extension separator
    int sep = 0, cur = 0, len = strlen(f_name);
    while (cur < len)
    {
        if (cur == '.')
        {
            sep = cur;
        }
        cur++;
    }

    // Find file extension
    int ext_len = len - (sep + 1);
    char extension[ext_len];
    for (int i = 0; i < ext_len; i++)
    {
        extension[i] = f_name[len - ext_len + i];
    }

    printf("%s", extension);
}