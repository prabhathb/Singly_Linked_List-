#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	insert_front(10);
	insert_front(25);
	insert_front(37);
	insert_front(49);
	traverse_list();
	printf("Number of Items in the Singly Linked List = %d\n",get_number_of_items());
	
	insert_end(13);
	traverse_list();
	printf("Number of Items in the Singly Linked List = %d\n",get_number_of_items());
	
	remove_front();
	traverse_list();
	printf("Number of Items in the Singly Linked List = %d\n",get_number_of_items());
	
	remove_end();
	traverse_list();
	printf("Number of Items in the Singly Linked List = %d\n",get_number_of_items());
	
	insert_at(26,2);
	traverse_list();
	printf("Number of Items in the Singly Linked List = %d\n",get_number_of_items());

	insert_at(50,10);
	traverse_list();
	printf("Number of Items in the Singly Linked List = %d\n",get_number_of_items());
	
	remove_at(3);
	traverse_list();
	printf("Number of Items in the Singly Linked List = %d\n",get_number_of_items());
	
	remove_at(4);
	traverse_list();
	printf("Number of Items in the Singly Linked List = %d\n",get_number_of_items());
	return 0;
}