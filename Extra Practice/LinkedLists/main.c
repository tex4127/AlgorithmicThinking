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
    struct node_t *prev;
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

/*!
 *  @brief adds a node to our linked list. 
 */
node_t* push(node_t* cur_node, int val)
{
    //First, we need to check if we were given the end of the list. If not, we just need to move until the end
    node_t* c_n = cur_node;
    while(c_n->next != NULL){c_n = c_n->next;} //This will move us to the end of the list
    node_t* n_n = (node_t*)malloc(sizeof(node_t));
    c_n->next = n_n;
    n_n->value = val;
    return n_n;
}

void pop_all(struct node_t* headNode)
{
    struct node_t* tmp;
    while(headNode != NULL)
    {
        tmp = headNode;
        headNode = headNode->next;
        std::cout << "freeing memory at: " << &tmp << '\n';
        std::cout << "next node at: " << &headNode <<'\n';
        free(tmp);
    }
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
    //add another node
    head->next->next = (node_t*)malloc(sizeof(node_t));
    head->next->next->value = generateNumber();
    //ensure the pointer for the end of the list is actually NULL
    head->next->next->next = NULL;
    std::cout << "number of nodes input: " << numNodes << '\n' << std::endl;
    node_t* current = head;
    std::cout << "head @: " << &head << '\n';
    std::cout << "node1 @: " << &head->next << '\n';
    std::cout << "node2 @: " << &head->next->next << '\n';
    while(current != NULL)
    {
        std::cout << "Value at memory address: " << current << '\n';
        std::cout << current->value << std::endl;
        current = current->next;
    }
    current = head;
    while(current != NULL)
    {
        std::cout << "Value at memory address: " << current << '\n';
        std::cout << current->value << std::endl;
        current = current->next;
    }

    std::cout << "Now testing our push method. The hope is to add 3 more nodes that all only have 2 digit numbers stored as their data." << std::endl;
    pop_all(head);
    //lets first reset our list then move to the current value
    current = head;
    
    return 1;
} 