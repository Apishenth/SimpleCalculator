#include <stdio.h>
#include <stdlib.h>

void WriteFile (FILE *file,int data,int operator)
{
    if (file == NULL)
    {
        perror("Unable to open file");
    }

    else if (operator == 0) /* wont print + operator infront of the first number in the file */
    {
        fprintf(file," %d ",data);
    }

    else if (operator == -1) /* will print = sign infront of the total number */
    {
        fprintf(file,"= %d ",data);
    }

    else if (data != 0)/* will print '+' operator for all the numbers except the total and 0  Eg: wont print + 0 in the file */
    {
        fprintf(file,"+ %d ",data);
    }

}