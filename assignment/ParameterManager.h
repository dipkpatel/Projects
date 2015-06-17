/*******************************************************************************************************************/
/*Parameter Manager header file
 * Course : CIS 2750 
 * Prof. David McCaughan
 *  Assignment 1: Software Development in C
 *  Created on: Jan 10, 2015
 * 	Last Modified: Jan 23, 2015
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
/*The library declarations*/

/*******************************************************************************************************************/
/*The Boolean ADT enumeration*/
typedef enum
{ false,
true
}Boolean;
/***************************************************************************************************************/
/*The Parameter List ADT */
typedef struct ParameterList{
	struct node_list * head;
	struct node_list * curr;
}ParameterList;

/*Nodes that will be inside the List*/
typedef struct node_list{
	char * string;
	struct node_list * next;
}node;
/****************************************************************************************************************************************************/
/*Parameter Type identifiers enumerations*/
typedef enum
{
INT_TYPE,
REAL_TYPE,
BOOLEAN_TYPE,
STRING_TYPE,
LIST_TYPE
}param_t;

/****************************************************************************************************************************************************/
/*The unions parameter values structure*/
union param_value{
	int  int_val;
	float real_val;
	Boolean bool_val;
	char *str_val;
	ParameterList *list_val;
};
/****************************************************************************************************************************************************/

/*The functions and hash table implementations were derived from
* http://www.sparknotes.com/cs/searching/hashtables/section3.rhtml
*The Hash List and table structures*
*The hash table list struct
*The identifier is the variable name
*the value is type unions since it can be any type defined in union
*/
/*****************************************/
typedef struct elements_table{
	char * identifier;
	union param_value * value;
	param_t ptype;
	int has_val;
	int required;
	struct elements_table * next;

}elements;
/*****************************************/
/*The actual hash table structure
 * The actual table, size of the table and number of elements dynamically made
 */
typedef struct ParameterManager_struct{
	int size;
	elements **head_element;
}ParameterManager;


/*****************************************/
/*The function definition for the hash tables*/

/*PARAMETER LIST */
/*****************************************************************************
* PM_create
* 
* Creates and initializes a Parameter Manager LIST
* 
* Preconditions : none
*
* Postconditions: Memory is allocated successfully, Returns the pointer to the LIST created
*				  if Memory allocation failed, Returns a NULL pointer
******************************************************************************/
ParameterList* param_create();
/*****************************************************************************
* PL_next
* 
* Retrieves the next item in a ParameterList
* 
* Preconditions : An  ParameterList is present.
*
* Postconditions: The next item in the ParameterList is returned to the user.
******************************************************************************/
char * PL_next(ParameterList *l);
/*****************************************************************************
* addParamList
* 
* Adds the string to the back of a Parameter List
* 
* Preconditions : An Parameter List must exist and a valid string are passed in.
*
* Postconditions: The string is added to the front of the ParameterList,
******************************************************************************/
int addParamList(ParameterList * list, char * value);
/*****************************************************************************
* destroyList
* 
* Destroys a Parameter List and frees all the allocated memory
* 
* Preconditions : An Parameter List passed in properly.
*
* Postconditions: All memory allocated to the ParameterList is freed.
******************************************************************************/
int destroyList(ParameterList * list);
/*****************************************************************************
* PM_create
* 
* Creates and initializes a Parameter Manager Object
* 
* Preconditions : A size greater than or equal to 1 is passed in
*
* Postconditions: Memory is allocated successfully
*                 Returns NULL if there is an error allocating memory.
******************************************************************************/
ParameterManager * PM_create(int size);
/*****************************************************************************                       
* hashing
*
*  A Hash function used to get the position of a parameter in the hash table.
* It iterates the lenght of String and multipies it self by 33, a constant, with the additions 
* of the characters contained at that string iterator, after the iterator is done, the hash value is mod by
* size of the parameter manager to contain the hash index values between the size of the parameter manager.
* 
* Preconditions : A valid parameter name and a size greater than or equal to 1.
*
* Postconditions: Returns the position of the parameter in the hash table.
*                              
******************************************************************************/
int hashing( ParameterManager * table,char * string);
/******************************************************************************
* search_param
*
* A search function to find the location of the element/parameter being 
* managed by the Parameter Manager object
*
*Preconditions: A Parameter Manager Object must exits and string_param must be valid
*
* Postconditions: If the Parameter is found Returns a pointer to the location of the Parameter in the Parameter Manager Object
*				  If the Parameter is not in the Parameter Manager Object, return a NULL pointer.
******************************************************************************/
elements * search_param(ParameterManager * table, char * string_param);
/*****************************************************************************
* PM_hasValue
* 
*  to checks whether or not a registered parameter has a value .
* 
* Preconditions : An Parameter Manager object exist and has valid parameter name.
*                 The parameter must be registerd in the Parameter Manager Object
* 
* Postconditions: Returns 1 if the parameter has an assigned value
*                 Returns 0 if there is no value
*                 
******************************************************************************/
int PM_hasValue(ParameterManager *p, char * pname);
/*****************************************************************************
* PM_getValue
* 
* retrives the a parameters has been assigned.
* 
* Preconditions : A Parameter Manager object must exist and valid parameter name.
*                 The parameter must be registerd and it has a value or the function return undefined or null
* 
* Postconditions: Returns the value assigned to the parameter.
				  If no value has been assigned, return undefined or
******************************************************************************/
union param_value PM_getValue (ParameterManager * p, char * pname);

/******************************************************************************
*adding_element
*
* adds an element/parameter to the Parameter Manager Object 
*
*Preconditions: A Parameter Manager object exists, valid ptype and valid string type
*
*Postconditions: Returns 1 if able to malloc memory and add the newly create parameter 
*				in the Parameter Manager object
*				Returns 0 if memory allocation, invalid ptype or string type error
*
******************************************************************************/
int adding_element(char *string, ParameterManager * table,param_t ptype, int required);
/*****************************************************************************
* PM_manage
* 
* To registers parameters to that need to be managed by a Parameter Manager object
* 
* Preconditions : An initialized ParameterManager and a valid parameter name.
*                 A valid parameter type, and whether the parameter is required
*                 or not. The parameter should not already be registered, otherwise it will result 
*				 parameter manage error.
*  
* Postconditions: Returns 1 if the parameter is registered successfully
                  Returns 0 if there is a memory allocation error or if the parameter is already registered
******************************************************************************/
int PM_manage(ParameterManager *p, char *pname, param_t ptype, int required);
/*****************************************************************************
* PM_parseFrom
* 
* This functions parses values for the registered parameters in the Parameter Manager Object
* 
* Preconditions : An Parameter Manager object it present and a valid input stream and valid comment character
*  
* Postconditions: Returns 1 if the file is successfully parsed and all
*                 required parameters and option parameters that were in the file
*                 are read in.
*                 Returns 0 if there is a parse error.
*                 Returns 0 if a required parameter is not read in.
*                 
******************************************************************************/
int PM_parseFrom(ParameterManager *p,FILE *fp,char comment);
/*****************************************************************************
* required
* 
* Checks whether a registered parameter has a required value assigned to it, and if it does
* checks to see whether it has been assigned a value.
* 
* Preconditions : An initialized Parameter Manager
*
* Postconditions: Return 1 if all required parameters have a value. 
*                 Return 0 if any required parameter does not have a value
******************************************************************************/
int required(ParameterManager * p);

/*****************************************************************************
* PM_destroy
* 
* It destroys the Parameter Manager object and frees all the allocated memory
* 
* Preconditions : An initialized ParameterManager.
*
* Postconditions: Frees all memory allocated for the ParamaterManager.
				  Returns 1 on success.
******************************************************************************/
int PM_destroy(ParameterManager *table);
/*****************************************/



