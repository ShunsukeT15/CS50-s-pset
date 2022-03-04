#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCKSIZE 512

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage:./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Your file can't be opend.\n");
        return 1;
    }

    uint8_t input_buffer[BLOCKSIZE];
    int count = 0;
    FILE *image = NULL;


    while (1)
    {
        int size = fread(input_buffer, sizeof(uint8_t), BLOCKSIZE, file);
        if (size == 0)
        {
            break;
        }
        else if (input_buffer[0] == 0xff && input_buffer[1] == 0xd8 && input_buffer[2] == 0xff && (input_buffer[3] & 0xf0) == 0xe0)
        {
            if (image != NULL)
            {
                fclose(image);
                count += 1;
            }

            char filename[7];
            sprintf(filename, "%03i.jpg", count);
            image = fopen(filename, "w");

        }
        if (image != NULL)
        {
            fwrite(input_buffer, sizeof(uint8_t), size, image);
        }
    }
    fclose(image);
    fclose(file);
    return 0;
}