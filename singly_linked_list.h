/*
	Name: singly_linked_list.h
	Copyright: 
	Author: Prabhath Buddhika
	Date: 05-12-25 09:36
	Description: This header file declares the variables and functions used with the singly linked list data structure.
*/

#include <stdio.h>	//for NULL
#include <stdlib.h>

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

//declare the structure to hold the data item and thepointer to the next node.
struct node{
	int d;
	struct node* next;	
};

//declare the struct node as a user defined data type called list_item.
typedef struct node list_item;

//this vaiable records the number of items available in the linked list.
//this is initially zero and incremented everytime a new item is inserted.
//it decrements everytime an item is removed.
unsigned int number_of_items = 0;

//declare the pointer to the front of the singly linked list
list_item* front = NULL;

//insert a node to the front of the linked list
void insert_front(int data_item);
//insert a node to the end of the linked list
void insert_end(int data_item);
//insert a node to the given item number of the linked list
void insert_at(int data_item,unsigned int position);
//remove a node from the front of the linked list
int remove_front();
//remove a node from the end of the linked list
int remove_end();
//remove the node at the given item number of the linked list
int remove_at(unsigned int position);
//get the number of items available in the linked list
int get_number_of_items();
//traverse the singly linked list
void traverse_list();


#endif 
