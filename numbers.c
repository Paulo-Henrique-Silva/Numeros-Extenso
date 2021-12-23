//This was made by: Paulo
//Github: Paulo-Henrique-Silva

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char *convertsNum(char *num); 

int main()
{
    char input[1024] = {'\0'};

    do 
    {
        system("cls");
        printf("\t\t\t\tNUMBERS TO WORDS");

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
            printf("\n%s", convertsNum(input));

        getch(); //stops before reset
    }
    while(strcmp(input, "E") != 0);

    printf("\nExiting...");

    getch();
    return 0;
}

char *convertsNum(char *num)
{
    char *answer;

    char *firstDigit[] = 
    {
        "One", "Two", "Three", "Four", "Five", 
        "Six", "Seven", "Eight", "Nine"
    };

    int numIn_intForm = atoi(num);

    switch(strlen(num))
    {
        case 1:
            answer = firstDigit[numIn_intForm - 1]; //-1 because it is an array
            break; 
        default:
            answer = "Sorry, this number is too long!";
            break;
    }

    return answer;
}