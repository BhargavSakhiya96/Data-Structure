/*******************************************************************************************
 * File Name	: Lab2.c
 * Author	: Shamseddin Elmasri
 * Date		: Jan 10, 2021
 *
 * Description	: This file is the skeleton for lab 2 (Queues)
 *
 * Instructions	:
 *			- Complete enqueue1(), enqueue2(), enqueue3(), dequeue1(),
 *			  dequeue2(), dequeue3() functions.
 *
 *			- For advanced marks merge all the enqueuing and dequeuing
 *			  functions into one enqueue() and  one dequeue() respectively.
 * 
 * Student Name : Bhargav Sakhiya
 * student no   : 8689749
 */


#include <stdio.h>
#include <time.h>
#include <limits.h>

#define MAX_SIZE 40                             // Maximum size of queue



enum Queue {

    HIGH_PRIORITY,
    MED_PRIORITY,
    LOW_PRIORITY
};



/* Private Functions Prototypes */
void enqueue1(int);
void enqueue2(int);
void enqueue3(int);
int dequeue1();
int dequeue2();
int dequeue3();
void displayQueues(void);
int queueIsEmpty(enum Queue priority);



/* Queues Definitions */
int highPriorityQueue[MAX_SIZE] = { 0 };
int medPriorityQueue[MAX_SIZE] = { 0 };
int lowPriorityQueue[MAX_SIZE] = { 0 };

/* Indexes Definitions */
int hRear = 0, mRear = 0, lRear = 0;
int hFront = 0, mFront = 0, lFront = 0;
/* TypeDefs for timers */
time_t now, start, enqueueHighStart, enqueueMedStart, enqueueLowStart, dequeueStart;



/*** Do not change anything in this function unless for merging the enqueuing and
     dequeuing functions for the advanced outcomes ***/
int main(void)
{
    int dataHigh = 4, dataMed = 4, dataLow = 4;

    /* Add five elements to each queue*/
    for (int i = 0; i < 4; i++) {

        enqueue1(i);
        enqueue2(i);
        enqueue3(i);
    }

    displayQueues();

    /* Start timers */
    time(&start);
    time(&enqueueHighStart);
    time(&enqueueMedStart);
    time(&enqueueLowStart);
    time(&dequeueStart);
    time(&now);

    /* Run program for 30 seconds */
    while (difftime(now, start) < 30) {

        time(&now);     // Capture time

        /* Add an element to High Priority Queue if 4 seconds elapsed */
        if (difftime(now, enqueueHighStart) >= 4) {

            enqueue1(dataHigh);
            dataHigh++;
            time(&enqueueHighStart);        // Restart high priority enqueue timer
            displayQueues();
        }

        /* Add an element to Medium Priority Queue if 3 seconds elapsed */
        if (difftime(now, enqueueMedStart) >= 3) {

            enqueue2(dataMed);
            dataMed++;
            time(&enqueueMedStart);         // Restart medium priority enqueue timer
            displayQueues();
        }

        /* Add an element to Low Priority Queue if 2 seconds elapsed */
        if (difftime(now, enqueueLowStart) >= 2) {

            enqueue3(dataLow);
            dataLow++;
            time(&enqueueLowStart);         // Restart low priority enqueue timer
            displayQueues();
        }

        time(&now);     // Capture time


        /* Dequeue every second */
        if (difftime(now, dequeueStart) >= 1) {

            /* Dequeue based on priority */
            if (!queueIsEmpty(HIGH_PRIORITY)) {

                dequeue1();
            }
            else if (!queueIsEmpty(MED_PRIORITY)) {

                dequeue2();
            }
            else {
                dequeue3();
            }

            time(&dequeueStart);    // Restart dequeue timer
            displayQueues();
        }
    }

    return 0;
}



// FUNCTION      : enqueue1()
// DESCRIPTION   : This function adds an element to the rear of the high priority queue 
// PARAMETERS    : int value - represents the element to be added to the queue
// RETURNS       : Nothing
void enqueue1(int value) {

    if (MAX_SIZE == hRear) {                      // checking the codition wherether queue is full or not
        printf("Queue is full\n");
    }
    else {
    highPriorityQueue[hRear] = value;             // storing value into queue 
        hRear = hRear + 1;                        // incrementing rear value
    }

}



// FUNCTION      : enqueue2()
// DESCRIPTION   : This function adds an element to the rear of the medium priority queue 
// PARAMETERS    : int value - represents the element to be added to the queue
// RETURNS       : Nothing
void enqueue2(int value) {

    if (MAX_SIZE == mRear) {                               // checking the codition wherether queue is full or not
        printf("Queue is full\n");
    }
    else
    {
    medPriorityQueue[mRear] = value;                         // storing value into queue 
    mRear = mRear + 1;                                       // incrementing rear value
    }
}



// FUNCTION      : enqueue3()
// DESCRIPTION   : This function adds an element to the rear of the low priority queue 
// PARAMETERS    : int value - represents the element to be added to the queue
// RETURNS       : Nothing
void enqueue3(int value) {

    if (MAX_SIZE == lRear) {                                     // checking the codition wherether queue is full or not
        printf("Queue is full\n");
    }
    else
    {
    lowPriorityQueue[lRear] = value;                            // storing value into queue
    lRear = lRear + 1;                                       // incrementing rear value
    }
}



// FUNCTION      : dequeue1()
// DESCRIPTION   : This function retrieves the element located at the front of the high priority queue
// PARAMETERS    : Nothing
// RETURNS       : Data of high priority queue's head node
int dequeue1(void) {
    int temp;                                                                // creating temp variable for storing front head value
    if (hRear == 0) {                                                        // checking condition for Queue is empty or not
        printf("queue is empty\n");
     }
    else
    {
       temp = highPriorityQueue[hFront];
        for (int i = 0; i < hRear-1; i++) {                                    // running for loop for shifting elements to the next index 
            highPriorityQueue[i] = highPriorityQueue[i + 1];
        }
        hRear--;                   // decrementing rear value
    }
    return temp;
}



// FUNCTION      : dequeue2()
// DESCRIPTION   : This function retrieves the element located at the front of the medium priority queue
// PARAMETERS    : Nothing
// RETURNS       : Data of medium priority queue's head node
int dequeue2(void) {
    int temp;                                                            // creating temp variable for storing front head value
    if (mRear == 0) {                                                  // checking condition for Queue is empty or not
        printf("Queue is empty\n");
      }
    else
    {
        temp = medPriorityQueue[mFront];
        for (int i = 0; i < mRear-1; i++) {                                     // running for loop for shifting elements to the next index
            medPriorityQueue[i] = medPriorityQueue[i + 1];
        }
       mRear--;                                                               // decrementing rear value
    }
    return temp;  
}



// FUNCTION      : dequeue3()
// DESCRIPTION   : This function retrieves the element located at the front of the low priority queue
// PARAMETERS    : Nothing
// RETURNS       : Data of low priority queue's head node
int dequeue3(void) { 
    int temp;                                                              // creating temp variable for storing front head value
    if (lRear == 0) {                                                     // checking condition for Queue is empty or not
        printf("Queue is empty \n");
     }
    else
    { 
         temp = lowPriorityQueue[lFront];
        for (int i = 0; i < lRear-1; i++) {                            // running for loop for shifting elements to the next index
            lowPriorityQueue[i] = lowPriorityQueue[i + 1];
        }
        lRear--;                                             // decrementing rear value
    }
     return temp;
}



// FUNCTION      : queueIsEmpty()
// DESCRIPTION   : This function is used to check if a certain queue is empty
// PARAMETERS    : enum Queue priority - HIGH_PRIORITY, MED_PRIORITY or LOW_PRIORITY
// RETURNS       : 1 if empty, 0 otherwise
int queueIsEmpty(enum Queue priority) {

    int* rear = NULL;

    /* Copy addresses of indexes based on queue chosen*/
    switch (priority) {

    case HIGH_PRIORITY:

        rear = &hRear;
        break;

    case MED_PRIORITY:

        rear = &mRear;
        break;

    case LOW_PRIORITY:

        rear = &lRear;
        break;

    default:

        printf("Invalid entry\n");
        return 1;
    }

    return *rear == 0;
}



// FUNCTION      : displayQueues()
// DESCRIPTION   : This function displays the contents of all the queues.
// PARAMETERS    : Nothing
// RETURNS       : Nothing
void displayQueues(void) {

    if (hRear == 0) {
        printf("High priority queue is empty\n");
    }
    if (mRear == 0) {
        printf("Medium priority queue is empty\n");
    }
    if (lRear == 0) {
        printf("Low priority queue is empty\n");
    }

    printf("\033[2J");      // Clear screen
    printf("\033[0;0H");    // Reset cursor

    /* Display contents of the high proirity queue */
    for (int i = 0; i < hRear; i++) {

        printf(" %d ", highPriorityQueue[i]);
    }
    printf("\n");

    /* Display contents of the medium proirity queue */
    for (int i = 0; i < mRear; i++) {

        printf(" %d ", medPriorityQueue[i]);
    }
    printf("\n");

    /* Display contents of the low proirity queue */
    for (int i = 0; i < lRear; i++) {

        printf(" %d ", lowPriorityQueue[i]);
    }
    printf("\n");
}
