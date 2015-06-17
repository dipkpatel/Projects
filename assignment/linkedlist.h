/*******************************************************************************************************************/
/*Linked List header file
 * Course : CIS 2750 
 * Prof. David McCaughan
 *  Assignment 3: System Tools/Visualization
 *  Created on: March 10, 2015
 * 	Last Modified: March 13, 2015
 *  Author: Dipkumar Patel
 * Student ID: 0763246
 * Email: dipkumar@mail.uoguelph.ca
 */
/**************************************************************************
******  *  ******  *  *  *    *   **    **        **      ******
*    *  *  *    *  * *   *    *   * *  * *       *  *     *    *
*    *  *  ******  **    *    *   *  *   *      *    *    *    *
*    *  *  *       **    *    *   *      *     ********   * **
*    *  *  *       * *   *    *   *      *    *        *  *  *
******  *  *       *  *  ******   *      *   *          * *   *
************************************************************************/
/***************************************************************************************************************/
/*The Linked List ADT */
typedef struct List{
	struct node_list * head;
	struct node_list * curr;
}LinkedList;

/*Nodes that will be inside the List*/
typedef struct node_list{
	char * string;
	char * value;
	struct node_list * next;
}node;
/****************************************************************************************************************************************************/
/*Linked LIST */
/*****************************************************************************
* list_create
* 
* Creates and initializes a Linked LIST
* 
* Preconditions : none
*
* Postconditions: Memory is allocated successfully, Returns the pointer to the LIST created
*				  if Memory allocation failed, Returns a NULL pointer
******************************************************************************/
LinkedList* list_create();
/*****************************************************************************
* PL_next
* 
* Retrieves the next item in a LinkedList
* 
* Preconditions : An  LinkedList is present.
*
* Postconditions: The next item in the LinkedList is returned to the user.
******************************************************************************/
char * PL_next(LinkedList *l);
/*****************************************************************************
* add_List
* 
* Adds the string to the back of a Linked List
* 
* Preconditions : An Linked List must exist and a valid string are passed in.
*
* Postconditions: The string is added to the front of the LinkedList,
******************************************************************************/
int add_List(LinkedList * list, char * value);
/*****************************************************************************
* destroyList
* 
* Destroys a Linked List and frees all the allocated memory
* 
* Preconditions : An Linked List passed in properly.
*
* Postconditions: All memory allocated to the LinkedList is freed.
******************************************************************************/
int destroyList(LinkedList * list);
