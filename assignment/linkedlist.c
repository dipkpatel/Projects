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
/*Library Declaration*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedlist.h"

/*Creating a list */
LinkedList* list_create(){
	LinkedList * newList = NULL;
  /*checking if the new list is malloced properly, if it is, set inner value pointers to null and return the list, else
  it is a memory allocation error and returns null.*/
  if ((newList = malloc(sizeof(LinkedList))) != NULL) {
    newList->head = NULL;
    newList->curr = NULL;
    return newList;
  } else {
    /*if there is a memory allocation error*/
    printf("\nLinked List Error: List Not Created\n");
    return NULL;
  }
  return NULL;
}



/*Linked List ADD Functions: adding items to the back to the list*/
int add_List(LinkedList * list, char * value) {
  node * new_value = NULL;
  node * temp;
  /*checks if the list is null or not, if its not null, create a new node 
  * and pass in the value and return it. else its  a parse error. */

  /*checking if the new node is malloced properly*/

  if ((new_value = malloc(sizeof(node))) != NULL) {
    /*checks whether the list is empty*/
    if (strlen(value)== 0){
      new_value->string =NULL;
      new_value->next = NULL;
      new_value->value = NULL;
    }else{
      /*if the list is not empty then allocate memory and copy the value*/
      /*checking if the memory is being malloced for the new node string*/
     	 if ((new_value->string = malloc(sizeof(char) * (strlen(value) + 1)))!= NULL) {
  			/*copying the value to the string*/
       		 strcpy(new_value->string, value);
       		 new_value->next = NULL;
       		 new_value->value = NULL;
     	 }
    }

  } else {
    /*memory fail*/
    printf("\nLinked List Error: Not able to add new Value to string\n");
    return 0;
  }
  /*checking if there is an element in the list or not, if there is add the newly created element to the back of the list
  else make the list point to the new element created.*/
  if (list->head == NULL) {
    list->head = new_value;
    list->curr = new_value;
  } else {
    /*find the place where the node needs to go and add it ther*/
    temp = list->curr;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_value;
  }
  printf("\nLinked List: Value Added :-> %s\n",value);
    
  /*returns 1 if successful*/
  return 1;
}

/*Linked List Functions: Incrementor to go through the list and return all the values*/
char * PL_next(LinkedList *l) {
  node * temp;

  /*checks if the list and if the head of the list are null, if not, then gets the string from the head of the list
  * increments the list pointer head by 1 and returns the value of the string. */

  if ((l != NULL) && (l->head != NULL)) {
    temp = l->head;
    l->head = temp->next;
    return temp->string;
  }
  /*return null if list is empty*/
  return NULL;
}

/*Linked List Functions: Destroying the Linked List*/
int destroyList(LinkedList * list) {
  /*Checks whether the list is empty or not and if it is not empty, frees all the elements with in the list*/
  node * temp = NULL;
  /*if List is not null, increment list and free*/
  if (list != NULL) {

    /*while the head pointer is not null*/
    while (list->curr != NULL) {

      temp = list->curr;
      list->curr = temp->next;
      /*free the "char * string" */
      free(temp->string);
      /*frees the node after freed all the internal elements*/
      free(temp);
    } 
  }

  /*free the list*/
  free(list);
  /*return true on success or else 0 for failiure*/
  return 1;
}