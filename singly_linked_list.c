/*
	Name: singly_linked_list.c
	Copyright: 
	Author: Prabhath Buddhika
	Date: 05-12-25 09:38
	Description: This source file defines the functions used with the singly linked list data structure.
*/

#include <stdlib.h>
#include "singly_linked_list.h"

//insert a node to the front of the linked list.
void insert_front(int data_item){
	list_item* a = (list_item*)malloc(sizeof(list_item));	//allocate memory for the new node of the list.
	a->d = data_item;										//new node stores the new data item.
	a->next = front;										//next of the new node points to the front of the list.
	front= a;												//front is now adjusted to point to the new node.
	number_of_items++;										//increment the number of items in the list.
}

//insert a node to the end of the linked list.
void insert_end(int data_item){
	list_item* x = front;										//new variable for a node is set to the front of the list.
	while(x->next != NULL){										//until the next of x points to NULL which is the end of the list...
		x = x->next;											//adjust x to the next of the x.
	}
	list_item* a = (list_item*)malloc(sizeof(list_item));		//allocate memory for the new node of the list.
	a->d = data_item;											//new node stores the new data item.
	a->next = x->next;											//next of new node points to the next of x.
	x->next = a;												//next of x points to the new node a.
	number_of_items++;											//increment the number of items in the list.
}

//insert a node to the given item number of the linked list.
//the given 'position' must be within the size of the current list.
void insert_at(int data_item,unsigned int position){
	unsigned int p = 0;											//a locla variable to navigate through the list.
	list_item* x = front;										//new variable for a node is set to the front of the list.
	if(position <= number_of_items){							//ensure the position is valid within the existinng list.
		for(p=0; p<position-2; p++){							//node at two positions before the position points to the node before the position.
			x = x->next;										//x is updated to the address of the next node in the list.
		}
		list_item* a = (list_item*)malloc(sizeof(list_item));	//allocate memory for the new node of the list.
		a->d = data_item;										//new node stores the new data item.
		a->next = x->next;										//next of new node points to the next of x which the item at the 'position'.
		x->next = a;											//next of x is assigned the address of the new node.
		number_of_items++;										//increment the number of items in the list.
	}
	//if the given 'position' is beyond the last element of the list, ignore the insert and report error to the user.
	else{
		printf("Insert Failed! List is shorter than the given position number (%d).\n",position);
	}	
}

//remove a node from the front of the linked list.
int remove_front(){
	int dt = -1;							//return -1 by default if the list is empty.
	list_item* x = front;					//new variable for a node is set to point to the front of the list.
	if(x != NULL){							//ensure front isnot NULL. If NULL, the list must be empty.
		dt = x->d;							//local variable dt stores the data item stored in the list item.
		front = x->next;					//adjust the front to point to the next item of the list.
		free(x);							//delete the node pointed by x and free its memory.
	}
	number_of_items--;						//decrement the number of items in the list.
	return dt;								//return the data item to the caller function.

}

//remove a node from the end of the linked list.
int remove_end(){
	int dt = -1;							//return -1 by default if the list is empty.
	list_item* x = front;					//new variable for a node is set to point to the front of the list.
	list_item* y;							//another variable to point to the node before the node to be removed.
	if(x != NULL){
		while(x->next != NULL){				//until the node pointed by x is not NULL...
			y = x;							//y become x
			x = x->next;					//x becomes the next node of x.
		}
		dt = x->d;							//store the data item of the node pointed by x in local  variable dt.
		y->next = NULL;						//next of the node pointed by y is NULL. This is the new end of the list.
		free(x);							//delete the node y which is at position and free its memory.
	}
	number_of_items--;						//decrement the number of items in the list.
	return dt;								//return the data item to the caller function.

}

//remove a node from the given item number of the linked list.
//the given 'position' must be within the size of the current list.
int remove_at(unsigned int position){
	unsigned int p = 0;											//a locla variable to navigate through the list.
	list_item* x = front;										//new variable for a node is set to point to the front of the list.
	list_item* y;												//another variable for a node to track the node to be removed.
	if(position <= number_of_items){
		for(p=0; p<position-2; p++){							//node at two positions before the position points to the node before the position.
			x = x->next;										//x is updated to the address of the next node in the list.
		}
		y = x->next;											//y points to the node next to x. Hence, y is the node to be removed.
		x->next = y->next;										//next of x points to the next of y which is the part of the list beyond the position.
		free(y);												//delete the node y which is at position and free its memory.
		number_of_items--;										//decrement the number of items in the list.
	}
	//if the given 'position' is beyond the last element of the list, ignore the remove and report error to the user.
	else{
		printf("Remove Failed! List is shorter than the given position number (%d).\n",position);
	}	
}

//get the number of items available in the linked list.
int get_number_of_items(){
	return number_of_items;				//return the number of items in the list.
}

//traverse the singly linked list
void traverse_list(){
	list_item* x = front;				//new variable for a node is set to point to the front of the list.
	while(x != NULL){					//until the end of the list is found...
		printf("%d\n",x->d);			//print the data item of each node
		x = x->next;					//go to the next node.
	}
}