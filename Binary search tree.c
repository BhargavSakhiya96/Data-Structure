/*******************************
 * File Name	: Lab3.c
 * Author	: Shamseddin Elmasri
 * Date		: Mar 11, 2021
 * Description	: This file is the skeleton for Lab 3 (Binary Search Tree).

 * Instructions	:
 *			1) Complete the structure for the binary tree nodes. This structure should contain a data field,
 *                         and two pointers (one for right child and the other for the left child).
 *                         You may add more fields to the structure if necessary.
 *
 *	                2) Complete the following functions:
 *
 *                              insertNode(): Creates a new node, inserts it to the binary search tree,
 *                                            and updates the height of the tree and its total number of nodes
 *
 *                              printInOrder(): Prints all the nodes in the tree in the ascending order
 *
 *                              deleteNode(): Deletes a specific node in the tree.
                                              (Cover all cases: node with no child, node with one child, and node with two children)
 *
 *                              deleteTree(): Deletes entire tree.
 *
 *     			3) Uncomment the commented lines only to test your work for the intermediate and advanced outcomes, otherwise
 *                         do not modify any line in main() function.
 *
 *                      4) You may add more functions for your program, however these functions must not be called from main().
 *  
 * Reference: https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
 *
 * Student Name: Bhargav Sakhiya
 * Student Number: 8689749
 *
 */

#include <stdio.h>
#include <stdlib.h>



#define SCALE_FACTOR 5

int a[16] = { 0 };      //array used to store nodes for second tree (intermediate outcomes)
int index = 0;
int count;


/* Definition of tree nodes*/
typedef struct Node {
    struct Node* leftChild;
    struct Node* rightChild;
    int data;
}treeNode;



/* Private Function Prototypes*/
void insertNode(treeNode** node, int value);
void printInOrder(treeNode* root);
void deleteNode(treeNode** root, int value);
void deleteTree(treeNode** node);

void postOrderCopy(treeNode* node);
int scaleUpAndDeleteOdd(int array[], int);
void createNewTree(int* array, treeNode** root);
void printPreOrder(treeNode* root);
int treeHeight(treeNode* node);



int main()
{
    int input[15] = { 43, 68, 77, 53, 12, 8, 59, 30, 16, 74, 36, 61, 20, 94, 2 };

    treeNode* treeRoot = NULL;

    int noOfNodes = 0;      // Total number of nodes in the tree

    /* Insert nodes into the tree */
    for (int i = 0; i < 15; i++) {

        insertNode(&treeRoot, input[i]);
    }

    printf("Inorder traversal of the given tree \n");
    printInOrder(treeRoot);

    /***Advanced Outcomes******

    int height = treeHeight(treeRoot);

    printf("\nThe tree has a height of %i and contains %i number nodes\n", height, noOfNodes);

    ****************/

    printf("\n");

    /****Intermediate Outcomes*****/

    postOrderCopy(treeRoot);        // Copy tree into the globally defined array 'a' in post-order traversal
    
    // Print out elements of array 'a'
    for (int i = 0; i < 15; i++) {

            printf("%i \n", a[i]);
    }

    /*****************/

    printf("\n");

    /***** Advanced Outcomes ******

    height = treeHeight(treeRoot);
    printf("\nThe tree has a height of %i and contains %i number nodes\n", height, noOfNodes);


    /****************/


    /****This section is prepared to test the tree******/
    int test[] = { 20, 43, 59, 77, 8 };                                  //
                                                                         //   
    for (int i = 0; i < sizeof test / sizeof * test; i++) {              //
                                                                         //
        printf("\nDelete %i:", test[i]);                             //
        deleteNode(&treeRoot, test[i]);                              //
        printf("\nInorder traversal of the modified tree \n");       //
        printInOrder(treeRoot);                                      //
    }                                                                    //
    /***********************/

    deleteTree(&treeRoot);      // Delete first tree

    // Intermediate Outcomes
    /***************/

    int numberOfElements = scaleUpAndDeleteOdd(a, SCALE_FACTOR);
    printf("\n");
    // Print out elements of array 'a' after modification
    for (int i = 0; i < numberOfElements; i++) {

            printf("%i\n ", a[i]);
    }

    treeNode* newTreeRoot = NULL;

    createNewTree(a, &newTreeRoot);         // Create new tree using elements of array 'a'
    printf("Preorder traversal of the new tree: \n");
    printPreOrder(newTreeRoot);

    deleteTree(&newTreeRoot);      // Delete second tree

    /**************/

    return 0;
}


// FUNCTION      : createNode()
// DESCRIPTION   : This function creates a new node 
// PARAMETERS    :	
//		int value	 - Data/Key to be stored in the node
// RETURNS       : Address of new node
treeNode* creatNode(int value) {
    treeNode* temp = (treeNode*)malloc(sizeof(treeNode));        // calling malloc function and create new node
    if (temp != NULL) {                                           // checking is temp NULL or not 
        temp->data = value;                                       // storing value in datafield 
        temp->leftChild = NULL;                                   // storing NULL into the leftChild 
        temp->rightChild = NULL;                                  // storing NULL into the rightChild
    }
    return temp;
}

// FUNCTION      : insertNode()
// DESCRIPTION   : This function creates a new node and inserts it to a given binary search tree
// PARAMETERS    :	
//		treeNode** ptrRoot  - Used to store address of root pointer
//		int value	 - Data/Key to be stored in the node
// RETURNS       : Nothing
void insertNode(treeNode** ptrRoot, int value) {

    treeNode* tempPtr = *ptrRoot;

    if (tempPtr == NULL) {                                 // checking condition for storing first node                        
        (*ptrRoot) = creatNode(value);                      // calling creatNode and storing address into the ptrRoot
        }
    else if (value < tempPtr->data) {                        // checking if value is less than datafiled so new node will be stored in left side 
        insertNode((&tempPtr->leftChild), value);
    }
    else if (value > tempPtr->data) {                        // checking if value is less than datafiled so new node will be stored in left side
        insertNode((&tempPtr->rightChild), value);
    }
}



// FUNCTION      : printInOrder()
// DESCRIPTION   : This function prints out a given binary search tree in in-order traversal
// PARAMETERS    :	
//		treeNode* root  - Pointer to root of the binary search tree
// RETURNS       : Nothing
void printInOrder(treeNode* root) {  
    if (root == NULL)  return;                                // checking if root is NULL or not 
    printInOrder(root->leftChild);                             // recursion to the leftChild 
    printf("%d\n", root->data);                              
    printInOrder(root->rightChild);                          // recursion to the rightChild
}

// FUNCTION      : maxVlaueNode()
// DESCRIPTION   : This function find max value in tree
// PARAMETERS    :	
//		treeNode* root  - Pointer to root of the binary search tree
// RETURNS       : return address of max value node
treeNode* maxValueNode(treeNode* node) {
    treeNode* current = node;                          
    while (current->rightChild != NULL)                   // running while loop until it reach to the NULL 
        current = current->rightChild;                      // traversing to the next right side node 
    return current;                                       // return node address 
}

// FUNCTION      : deleteNode()
// DESCRIPTION   : This function deletes a specific node in the tree given a specific key
// PARAMETERS    :	
//		treeNode** ptrRoot  - Used to store address of root pointer
//              int value        - Key of node to be deleted
// RETURNS       : Nothing
void deleteNode(treeNode** ptrRoot, int value) {

    treeNode* temptr = *ptrRoot;
    treeNode* temp;
    if (temptr == NULL) {                                   // checking if root is null or not 
        printf("Tree is Empty\n");
        return;
    }
    else if (value < (*ptrRoot)->data) {                     // checking condition if value is less than to the data in root 
        deleteNode(&(*ptrRoot)->leftChild, value);            // recursion to the left child by calling delete function again 
    }
    else if (value > (*ptrRoot)->data) {                     // checking condition if value is greter than to the data in root 
        deleteNode(&(*ptrRoot)->rightChild, value);           // recursion to the right child by calling delete function again
    }
    else {
        if ((*ptrRoot)->leftChild == NULL) {                           // checking if node left child is null 
            temp = *ptrRoot;                                                  
            *ptrRoot = (*ptrRoot)->rightChild;                        // storing rightChild adress into the ptrRoot 
            free(temp);                                              

        }

        else if ((*ptrRoot)->rightChild == NULL) {                   // checking if node right child is null 
            temp = *ptrRoot;
            *ptrRoot = (*ptrRoot)->leftChild;                       // storing leftChild adress into the ptrRoot 
            free(temp);
        }

        else if ((*ptrRoot)->leftChild != NULL && (*ptrRoot)->rightChild != NULL) {            // condition if node has two children 
            temp = maxValueNode((*ptrRoot)->leftChild);                                     // calling maxValueNode which return max node value
            (*ptrRoot)->data = temp->data;                                                      // storing max value node data into the ptr root
            deleteNode(&(*ptrRoot)->leftChild, temptr->data);                                   // recurion to the left subtree 
        }
        else if((*ptrRoot)->leftChild == NULL && (*ptrRoot)->rightChild == NULL) {
            temp = *ptrRoot;
            free(temp);
        }

    }
}




// FUNCTION      : postOrderCopy()
// DESCRIPTION   : This function copies the elements from a given binary search tree into
//                 the global array in post-order traversal.
// PARAMETERS    :	
//		treeNode* root   - Pointer to root of the binary search tree
// RETURNS       : Nothing
void postOrderCopy(treeNode* root) {
    if (root != NULL) {
    postOrderCopy(root->leftChild);      // recursion to the left child  
    postOrderCopy(root->rightChild);      // recursion to the right child
    a[index++] = root->data;               // storing data into the array 
   }

}




// FUNCTION      : scaleUpAndDeleteOdd()
// DESCRIPTION   : This function scales up the data field of all nodes in the tree by a factor passed to the function as an argument
//                 then deletes all the odd elements inside the array and returns the number of elements in the
//		           array after modification.                 
//                 This function should reject scale factor of 0.
// PARAMETERS    :	
//		int array[]     - Pointer to array to be scaled up
//              int scaleFactor - Scaling factor
// RETURNS       : Number of elements in the array after modification
int scaleUpAndDeleteOdd(int array[], int scaleFactor) {
    for (int k = 0; k< 15; k++) {                           // running for loop for multiplie scalefactor into array 
        array[k] = array[k] * scaleFactor;
    }
    int size = 15;
    for (int j = 0; j <size;j++) {                             // running for loop to store only even numbers in array 
        if (array[j] % 2 != 0) {
            int l = j + 1;
            for (int i = j;i < size;i++) {
                array[i] = array[l];
                l++;
            }
        }
        j--;
        size--;
    }

    return size;                       // returning total number of element 
}



// FUNCTION      : createNewTree()
// DESCRIPTION   : This function creates a new BST using the elements from the new modified array (maintaining the post-order traversal). 
// PARAMETERS    :	
//		int* array     - Pointer to array to retreive data of nodes for the new tree
//              treeNode** ptrRoot  - Used to store address of root pointer
// RETURNS       : Nothing
void createNewTree(int* array, treeNode** ptrRoot) {
    
    treeNode* temp=NULL;
    for (int i = 0; i < 8; i++) {                   // running for loop for inserting array value into the new BST 
        insertNode(&temp, array[i]);
        (*ptrRoot) = temp;
    }
}




// FUNCTION      : printPreOrder()
// DESCRIPTION   : This function prints out a given binary search tree in pre-order traversal
// PARAMETERS    :	
//		treeNode* root   - Pointer to root of the binary search tree
// RETURNS       : Nothing
void printPreOrder(treeNode* root) {
    if (root == NULL) {                          // checking if root is null or not 
        return;
    }

    printf("%i ", root->data);                                            
    printPreOrder(root->leftChild);                                // recursion to the left child 
    printPreOrder(root->rightChild);                               // recurion to the right child 
}



// FUNCTION      : treeHeight()
// DESCRIPTION   : This function finds and returns the height of a gievn binary search tree.
// PARAMETERS    :	
//		treeNode* root   - Pointer to root of the binary search tree
// RETURNS       : Height of tree
int treeHeight(treeNode* root) {
    return 0;
}



// FUNCTION      : deleteTree()
// DESCRIPTION   : This function deletes all nodes for a given binary search tree
// PARAMETERS    :	
//		treeNode** ptrRoot   - Used to store address of root pointer
// RETURNS       : Nothing
void deleteTree(treeNode** ptrRoot) {
    treeNode* temp = *ptrRoot;                                              
    if (*ptrRoot == NULL)                                        // checking ptrRoot is null or not 
        return;
    deleteTree(&(*ptrRoot)->leftChild);                          // recurison to the leftchild and free the node 
    deleteTree(&(*ptrRoot)->rightChild);                         // recurison to the leftchild and free the node
    temp = (*ptrRoot);                       
    free(temp);                                                  // after all recusrion free the root 
}