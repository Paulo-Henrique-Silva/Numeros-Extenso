//This was made by: Paulo
//Github: Paulo-Henrique-Silva

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void convertsNum(char *num); 

int main()
{
    char input[1024] = {'\0'};

    do 
    {
        system("cls");
        printf("\t\t\t\tNUMBERS TO WORDS - 1 to 9999");

        printf("\n\nType the Number(E - Exit): ");
        fgets(input, 1024, stdin);

        input[strlen(input) - 1] = '\0';
        strupr(input);
        //removes \n in last char and converts the input to upper case

        if(strcmp(input, "E") == 0)
            continue;
        else if(atoi(input) == 0) //if it is not a number
            printf("\nInvalid Input!");
        else
            convertsNum(input);

        getch(); //stops before reset
    }
    while(strcmp(input, "E") != 0);

    printf("\nExiting...");

    getch();
    return 0;
}

void convertsNum(char *num)
{
    int 
    numIn_intForm = atoi(num),
    firstDigit_num = numIn_intForm % 10, 
    secondDigit_num = (numIn_intForm % 100 - firstDigit_num) / 10, 
    thirdDigit_num = (numIn_intForm % 1000 - secondDigit_num) / 100, 
    fourthDigit_num = (numIn_intForm % 10000 - thirdDigit_num) / 1000; 
    //calculates each digit of the Number

    char 
    *numbersBefore_20[] =
    {
        " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", 
        " Sixteen", " Seventeen", " Eighteen", " Nineteen"
    },

    *firstDigit_str[] = 
    {
        "", " One", " Two", " Three", " Four", " Five", 
        " Six", " Seven", " Eight", " Nine"
    },

    *secondDigit_str[] = 
    {
        "", "", " Twenty", " Thirty", " Forty", " Fifty", 
        " Sixty", " Seventy", " Eighty", " Ninety"
    },

    *thirdDigit_str[] = 
    {
        "", " One Hundred", " Two Hundred", " Three Hundred", " Four Hundred", " Five Hundred", 
        " Six Hundred", " Seven Hundred", " Eight Hundred", " Nine Hundred"
    };
    //numbers strings

    switch(strlen(num))
    {
        case 1:

            printf("\nAnswer =%s", firstDigit_str[firstDigit_num]);
            break; 

        case 2:

            if(numIn_intForm < 20)
            {
                printf("\nAnswer =%s", numbersBefore_20[firstDigit_num]);
            }
            else
            {
                printf("\nAnswer =%s%s", 
                secondDigit_str[secondDigit_num], firstDigit_str[firstDigit_num]);
            }
            break;

        case 3:

            if(numIn_intForm % 100 < 20) //(0XX) if "XX" is smaller than 20
            {
                printf("\nAnswer =%s%s",
                thirdDigit_str[thirdDigit_num], numbersBefore_20[firstDigit_num]);
            }
            else
            {
                printf("\nAnswer =%s%s%s", 
                thirdDigit_str[thirdDigit_num],
                secondDigit_str[secondDigit_num], firstDigit_str[firstDigit_num]);
            }
            break;

        default:
            printf("\nSorry, this number is too long!");
            break;
    }
}