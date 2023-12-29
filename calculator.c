#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "terminal.h"
#include "clear.h"
#include "Boolean.h"
#include "LinkedList.h"
#include "writeFile.h"

int NoSelection (char **Array,int row,int col);

void Calculator (FILE * output)
{
    LinkedList* list;
    int i, j, layoutRow = 8, layoutCol = 5, close = FALSE, selectRow, selectCol,sumVal,sumTotal,randomNum=0;
    char ** CalcLayout, userInput;

    /* Creating a random number within the range of 0 to 10 to select the number pad layout*/
    srand(time(0));     
    randomNum = rand()%10;  /* referenced from : https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/ */
     
   

    list = (LinkedList*)malloc(sizeof(LinkedList));
    (*list).head = NULL;

    CalcLayout = (char **) malloc (layoutRow *  sizeof(char *));
    
    for (i=0; i <layoutRow; i++ )
    {
        CalcLayout[i]= (char *) malloc (layoutCol  * sizeof(char));
    }

    

    if ( randomNum % 2 == 0)
    {
        /* Creating layout */
        for (i=0; i< layoutCol; i++)
        {
        
            CalcLayout [0] [i] = ' ';
            CalcLayout [1] [i] = ' ';
            CalcLayout [2] [i] = ' ';
            CalcLayout [3] [i] = ' ';
            CalcLayout [4] [i] = ' ';
            CalcLayout [5] [i] = ' ';
            CalcLayout [6] [i] = ' ';
            CalcLayout [7] [i] = ' ';
        }
        CalcLayout [0] [0] = '1'; CalcLayout [0] [2] = '2'; CalcLayout [0] [4]= '3';
        CalcLayout [2] [0] = '4'; CalcLayout [2] [2] = '5'; CalcLayout [2] [4] = '6';
        CalcLayout [4] [0] = '7'; CalcLayout [4] [2] = '8'; CalcLayout [4] [4] = '9';
        CalcLayout [6] [0] = '+'; CalcLayout [6] [2] = '0'; CalcLayout [6] [4] = '=';
        
        /*Initialization of selection button coordinates*/
        selectRow = 1; selectCol = 0;
        CalcLayout [selectRow] [selectCol] = '^'; 
        sumVal = 0; sumTotal = 0;
    }
    else
    {
        /* Creating layout */
        for (i=0; i< layoutCol; i++)
        {
        
            CalcLayout [0] [i] = ' ';
            CalcLayout [1] [i] = ' ';
            CalcLayout [2] [i] = ' ';
            CalcLayout [3] [i] = ' ';
            CalcLayout [4] [i] = ' ';
            CalcLayout [5] [i] = ' ';
            CalcLayout [6] [i] = ' ';
            CalcLayout [7] [i] = ' ';
        }
        CalcLayout [0] [0] = '+'; CalcLayout [0] [2] = '0'; CalcLayout [0] [4]= '=';
        CalcLayout [2] [0] = '7'; CalcLayout [2] [2] = '8'; CalcLayout [2] [4] = '9';
        CalcLayout [4] [0] = '4'; CalcLayout [4] [2] = '5'; CalcLayout [4] [4] = '6';
        CalcLayout [6] [0] = '1'; CalcLayout [6] [2] = '2'; CalcLayout [6] [4] = '3';
        
        /*Initialization of selection button coordinates*/
        selectRow = 1; selectCol = 0;
        CalcLayout [selectRow] [selectCol] = '^'; 
        sumVal = 0; sumTotal = 0;
    }    
    do
    {
        
        printf("---------\n|%7d| \n---------\n",sumVal);
        
        printf("\n");
		for(i=0; i<layoutRow; i++)
		{
			for(j=0; j<layoutCol; j++)
			{
				printf("%c",CalcLayout[i][j]);
			}
			printf("\n");

		}
        printf("\ncurrent toal : %d",sumTotal);

        disableBuffer();
        scanf("%c",&userInput);
        enableBuffer();

        if(userInput == 'w' )
        {
            if(selectRow != 1)
            {
                CalcLayout[selectRow] [selectCol] = ' ';
                selectRow -= 2;
                CalcLayout [selectRow] [selectCol] = '^';
                clear();
            }
            else
            {
                clear();
            }
        }

        else if(userInput == 's' )
        {
            if(selectRow != 7)
            {
                CalcLayout[selectRow] [selectCol] = ' ';
                selectRow += 2;
                CalcLayout[selectRow] [selectCol] = '^';
                clear();
            }
            else
            {
                clear();
            }
        }

        else if(userInput == 'a' )
        {
            if(selectCol != 0)
            {
                CalcLayout[selectRow] [selectCol] = ' ';
                selectCol -= 2;
                CalcLayout[selectRow] [selectCol] = '^';
                clear();
            }
            else
            {
                clear();
            }
        }

        else if(userInput == 'd' )
        {
            if(selectCol != 4)
            {
                CalcLayout[selectRow] [selectCol] = ' ';
                selectCol += 2;
                CalcLayout[selectRow] [selectCol] = '^';
                clear();
            }
            else
            {
                clear();
            }
        }
        else if (userInput == 'e')
        {
            if(sumVal < 1000000)
            {
                if(CalcLayout[selectRow-1][selectCol] == '1' )
                {
                    sumVal = sumVal*10+1;
                    clear();
                }
                else if(CalcLayout[selectRow-1][selectCol] == '2' )
                {
                    sumVal = sumVal*10+2;
                    clear();
                }
                else if(CalcLayout[selectRow-1][selectCol] == '3' )
                {
                    sumVal = sumVal*10+3;
                    clear();
                }
                else if(CalcLayout[selectRow-1][selectCol] == '4' )
                {
                    sumVal = sumVal*10+4;
                    clear();
                }
                else if(CalcLayout[selectRow-1][selectCol] == '5' )
                {
                    sumVal = sumVal*10+5;
                    clear();
                }
                else if(CalcLayout[selectRow-1][selectCol] == '6' )
                {
                    sumVal = sumVal*10+6;
                    clear();
                }
                else if(CalcLayout[selectRow-1][selectCol] == '7' )
                {
                    sumVal = sumVal*10+7;
                    clear();
                }
                else if(CalcLayout[selectRow-1][selectCol] == '8' )
                {
                    sumVal = sumVal*10+8;
                    clear();
                }
                else if(CalcLayout[selectRow-1][selectCol] == '9' )
                {
                    sumVal = sumVal*10+9;
                    clear();
                }
                else if(CalcLayout[selectRow-1][selectCol] == '0' )
                {
                    sumVal = sumVal*10+0;
                    clear();
                }

                else if(CalcLayout[selectRow-1][selectCol] == '+')
                {
                    sumTotal = sumTotal + sumVal;
                    insertFront(list,sumVal);
                    sumVal = 0;
                    clear();
                }
                else if (CalcLayout[selectRow-1][selectCol] == '=')
                {
                    freeLinkedList(list,output);
                    if (sumTotal != 0)
                    {
                        WriteFile(output,sumTotal,-1);
                    }
                    else
                    {
                        /* wont print 0 to the file if the total is 0
                        eg: 0 = 0 instead will print 0 */
                    }
                    
                    close = TRUE;
                    clear();
                }
                
            }
            else
            {
                clear();
            }
        }
        else
        {
            clear();
        }


        
        

    } while (close == FALSE );
    
    
}



int main (int argc, char *argv[])
{
    FILE *outputFile = fopen(argv[1],"w");
    Calculator (outputFile);
    return 0;
}