////////////////////////////////////////////////
///
//  This source code is to practice writting different 
//  data structures. This source file is specific towards
//  linked lists
//
///
////////////////////////////////////////////////

#include<iostream>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


//for any good linked list, we need a data strucutre that has a pointer to the previous node
//the data stored in the node and a pointer to the next node or NULL if its the end of the list

typedef struct node_t
{
    //Pointer to the next node object
    struct node_t *next;
    //value stored in the node
    int value;
}node_t;

/*!
 *  @brief generates a random number between 0 and 999
 *  @returns the generated number
 */
int generateNumber()
{
    return rand()%1000;
}


int main()
{
    std::cout << "Welcom to the Linked List example." << std::endl;
    std::cout << "Enter a value between 1 and 10 and this script will create that many nodes in the linked list!" << std::endl;
    
    std::string input;
    std::getline(std::cin, input);
    int numNodes = std::stoi(input, 0, 10);
    numNodes = (numNodes % 10) + 1;
    //Set our seed for the random number generator.
    srand(time(NULL));
    node_t* head = NULL;
    head = (node_t *) malloc(sizeof(node_t)); //creates a pointer to the memory allocated and casts it to a node_t pointer
    head->value = generateNumber();
    //lets add a node
    head->next = (node_t* )malloc(sizeof(node_t));
    head->next->value = generateNumber();
    head->next->next = NULL;
    
    std::cout << "number of nodes input: " << numNodes << '\n' << std::endl;
    node_t* current = head;
    while(current != NULL)
    {
        std::cout << current->value << std::endl;
        current = current->next;
    }
    return 1;
} 