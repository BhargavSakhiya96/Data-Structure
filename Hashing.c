/*******************************************************************************************
 * File Name	: Lab4.c
 * Author	: Shamseddin Elmasri
 * Date		: Apr 17, 2021
 * Description	: This file is the skeleton for Lab 4 (Hashing).

 * Instructions	:
 *			1) Complete the state machine as indicated in the comments inside
 *                         each state.
 *                      2) Create your own hash function to find the hash value for each
 *                         input (You may use the example provided in the lecture slides
 *                         as a starting point, however, your hash function must be
 *                         different)
 *                      3) For advanced outcomes, create another state machine inside
 *                         FINISH_STATE to enable the user of restarting the program
 *
 * Student Name: Bhargav Sakhiya    
 * Student Number: 8689749
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


uint32_t hashFunction(char* ptrInputBuffer);


int main()
{
    enum StateMachine
    {
        START_STATE,
        INITIALIZATION_STATE,
        WAIT_FOR_INPUT_STATE,
        GET_HASH_STATE,
        FINISH_STATE

    }State = START_STATE;


    uint32_t counter;                       // Used to count number of valid inputs
    char inputString[20];                   // Stores the user's input string
    char exitMessage[5] = "EXIT";
    uint32_t hashValue;

    while (1)
    {
        switch (State)
        {
        case START_STATE:

            printf("Program started!\n");

            State = INITIALIZATION_STATE;

            break;


        case INITIALIZATION_STATE:
            
            counter = 0;
            
            for (int i = 0; i <=20; i++) {    // running for loop to clear string             
                inputString[i] = 0;
            }
            State = WAIT_FOR_INPUT_STATE;                                  
            // Reset the counter and clear the input string array

            break;


        case WAIT_FOR_INPUT_STATE:


            printf("Enter a string : ");
            gets_s(inputString);                                     
          
            // User enters the input string from the terminal
            
// If the user enters "exit" or "EXIT", go to FINISH_STATE

            if (strcmp(inputString,"exit")==0 || strcmp(inputString, "EXIT")==0) {         // checking if user enter exit or not with help of string compare function
                State = FINISH_STATE;                                                      // if yes then it program will go in last state 
                break;
                
            }
// Check the first character of the input,
// if it's not a letter (upper case or lower case),
// then consider the input as invalid.

              if (inputString[0] >= 65 && inputString[0] <= 90 || inputString[0] >=97 && inputString[0] <= 122) {     // with help of ASCII value we are checking first charchter of string is alphabet or not
                counter++;                                                                 // incrementing counter by 1 so we can count total number of valid input at the end of program 
                State = GET_HASH_STATE;
              }
            else
            {
                printf(" Input is Invalid \n");
            }
// If the input is valid, increment the counter and go
// to GET_HASH_STATE

                // Check the input and set the next state accordingly

            break;


        case GET_HASH_STATE:

            hashValue =  hashFunction(inputString);            // calling hash function and passing string to the function 
            printf("Hash value is = %d\n", hashValue);
            State = WAIT_FOR_INPUT_STATE; 

            
            // Call the hash function and display the hash value
            // Return back to WAIT_FOR_INPUT_STATE

            break;



        case FINISH_STATE:
            
            printf("Program is ended , Total valid input in program is %d  \n",counter);   
            State = FINISH_STATE;
            return 0;
            // Display a message indicating program ended along with the 
            // number of valid inputs entered during the life of the program
            // before entering this state
            //
            // After entering this state, the state machine should remain+
            // in this state

            /* Advanced Outcomes */


           

            // The message should be displayed only once inside this state
// (not before entering this state). This can be done by creating
// another statemachine that runs inside this state. The inner
// state machine should also allow the user to restart the 
// program if "restart" or "RESTART" is entered.

            break;


        default:
            State = START_STATE;
            break;
        }
    }

    return 0;
}



// FUNCTION      : hashFunction()
// DESCRIPTION   : This function receives an string, calculates a hash for it and returns the hash value
// PARAMETERS    :	
//		   char* ptrInputBuffer: Pointer to input string
//
// RETURNS       : calculated hash value
uint32_t hashFunction(char* ptrInputBuffer) {

    uint32_t calculatedHashValue = 1515;
    int c;

    while (c = *ptrInputBuffer++) {                             // with help of incrementing pointer of string this loop will run for every input 
        calculatedHashValue = (calculatedHashValue+c)*3;
    }

    return calculatedHashValue;
}