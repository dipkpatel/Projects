/*******************************************************************************************************************/
/*Parameter Manager  file
* Course : CIS 2750 
* Prof. David McCaughan
*  Assignment 1: Software Development in C
*  Created on: Jan 10, 2015
*   Last Modified: Jan 23, 2015
*  Author: Dipkumar Patel
* Student ID: 0763246
* Email: dipkumar@mail.uoguelph.ca
*/
/*******************************************************************************************************************
******  *  ******  *  *  *    *   **    **        **      ******
*    *  *  *    *  * *   *    *   * *  * *       *  *     *    *
*    *  *  ******  **    *    *   *  *   *      *    *    *    *
*    *  *  *       **    *    *   *      *     ********   * **
*    *  *  *       * *   *    *   *      *    *        *  *  *
******  *  *       *  *  ******   *      *   *          * *   *
*******************************************************************************************************************/
/*Library Declaration*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ParameterManager.h"
/****************************************************************************************************************************************************/
/*Parameter List Functions*/
/*Parameter LIST create function*/
ParameterList* param_create() {
  ParameterList * newList = NULL;
  /*checking if the new list is malloced properly, if it is, set inner value pointers to null and return the list, else
  it is a memory allocation error and returns null.*/
  if ((newList = malloc(sizeof(ParameterList))) != NULL) {
    newList->head = NULL;
    newList->curr = NULL;
    return newList;
  } else {
    /*if there is a memory allocation error*/
    printf("\nParameter List Error: List Not Created\n");
    return NULL;
  }
  return NULL;
}

/**********************************************************************/
/*Parameter List ADD Functions: adding items to the back to the list*/
int addParamList(ParameterList * list, char * value) {
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
    }else{
      /*if the list is not empty then allocate memory and copy the value*/
      /*checking if the memory is being malloced for the new node string*/
      if ((new_value->string = malloc(sizeof(char) * (strlen(value) + 1)))!= NULL) {

  /*copying the value to the string*/
        strcpy(new_value->string, value);
        new_value->next = NULL;
      }
    }

  } else {
    /*memory fail*/
    printf("\nParameter List Error: Not able to add new Value to string\n");
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
  /*returns 1 if successful*/
  return 1;
}

/**********************************************************************/
/*Parameter List Functions: Incrementor to go through the list and return all the values*/
char * PL_next(ParameterList *l) {
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

/**********************************************************************/
/*Parameter List Functions: Destroying the Parameter List*/
int destroyList(ParameterList * list) {
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

/****************************************************************************************************************************************************/
/*This hash table implementation source was derived from the online from:
* SparkNotes Editors. “SparkNote on Hash Tables.” SparkNotes.com. SparkNotes LLC. n.d.. Web. 13 Jan. 2015.
* */
/*The functions of hash table*/
/*
* Create hash table and operations add, delete, Modify, etc
*/
/****************************************************************************************************************************************************/
/*Parameter Manager Functions: create a Parameter Manager Object to manage parameters*/
ParameterManager * PM_create(int size) {

  ParameterManager * Table = NULL;
  int i = 0;

  /*Checking if the parameter size is greater then 0*/
  if (size > 0) {

    /*allocating memory for the table structure*/
    if ((Table = malloc(sizeof(ParameterManager))) != NULL) {

      /*allocating memory for the table elements of the list*/
      if ((Table->head_element = malloc(sizeof(elements *) * size))
        != NULL) {

  /*initializing all the elements of the table to default value;*/
        for (i = 0; i < size; i++) {
          Table->head_element[i] = NULL;
        }
      } else {
  /*memory allocation error*/
        printf("Parameter Manager Error: ParameterManager Elements Not created-Malloced");
        return NULL;
      }
      /*Setting table size*/
      Table->size = size;
      return Table;
    } else {

      /*memory allocation error*/

      printf("Parameter Manager Error: ParameterManager Object Not created-Malloced");
      return NULL;
    }

  }
  return NULL;

}
/****************************************************************************************************************************************************/
/*Hashing functions for generating a integer value from the string */
int hashing(ParameterManager * table, char * string) {

  int hash_index = 0, i = 0;
  char * temp = string;
  /*Checking if the string is not null*/
  if (string != NULL) {
    /*finds the hash index value by multiplying and adding character of strings */
    for (i = 0; i < strlen(string); i++) {

      hash_index = 33 * hash_index + temp[i];
    }
    /*returns a mod of hash index by table size, so that the hash index value is bounded 
    within the size of the table*/
    return abs(hash_index % table->size);
  } else {

    /*memory allocation error*/

    printf("\nParameter Manager Error: Hashing->Invalid String Parameter-> %s Entered", string);
    return 0;
  }
  return 0;
}
/****************************************************************************************************************************************************/
/*looking up elements from the table*/
elements *search_param(ParameterManager * table, char * string_param) {
  elements * temp;
  int temp_hash_index;
  /*gets the hash value of the string param from the hashing function*/
  temp_hash_index = hashing(table, string_param);

  /*this iterates through the chaining link list*/
  for (temp = table->head_element[temp_hash_index]; temp != NULL; temp = temp->next) {
    /*compare if the string parameter matches identifier*/
    if (strcmp(string_param, temp->identifier)== 0) {
      return temp;
    }
  }
  return NULL;
}
/****************************************************************************************************************************************************/
/*PARAMETER MANAGER union function: return the values stored in the parameter*/
union param_value PM_getValue(ParameterManager * p, char * pname) {

  elements * temp;
  /*check to see if the parameter exist in the parameter manager object*/
  temp = search_param(p, pname);
  /*if parameter is found, chech to see whether it has been assigned a value*/
  if (temp != NULL) {
    /*check to see if the parameter has been assigned a value!*/
    if (temp->has_val == 1) {
      /*if it has a value return the value*/
      return *(temp->value);
    }
  } else {

    /*memory allocation error*/

    /*the parameter is not registered in the parameter manager object*/
    printf("\nParameter Manager Error: %s Not Managed by the ParameterManager",
      pname);
     /*return undefined*/
    return *(temp->value);
  }
  /*return undefined*/
  return *(temp->value);
}

/****************************************************************************************************************************************************/
/*Parameter Manager Function: checks whether the parameter has been assigned a value or not*/
int PM_hasValue(ParameterManager *p, char * pname) {

  elements * temp1;
  /*searching for the parameter in the parameter manager object*/
  if ((temp1 = search_param(p, pname)) != NULL) {

    /*if object found, check if it has been assigned a value, returns 1 if it does.*/
    if (temp1->has_val == 1) {

      /*returns one if the parameter has been assigned a value*/
      return 1;
    }
  } else {

    /*memory allocation error*/

    /*returns null if the parameter is not managed by the PM object*/
    printf("\nParameter Manager ERROR: %s is not managed in the  Parameter Manager", pname);
    return 0;
  }

  return 0;
}

/****************************************************************************************************************************************************/
/*Parameter Manager Destroy Function*/
/*Freeing and destroying the hash table*/
int PM_destroy(ParameterManager * table) {
  elements *temp, *chains;

  /*The table is empty*/
  if (table != NULL) {

    int i;
    /*for loop going through the table of elements and freeing all the data*/
    for (i = 0; i < (table->size); i++) {
      /*temporary variable to keep track of parameters in the table*/
      temp = table->head_element[i];

      /*Checking if the elements are not null*/
      while (temp != NULL) {
  /*incrementing to the next parameter at the index for chaining*/
        chains = temp;
        temp = chains->next;

  /*Checking if string and list have been malloced and freeing if true.*/
        if (chains->ptype == STRING_TYPE) {

    /*freeing the string malloced */
          free(chains->value->str_val);
    /*if the type is list type */
        } else if (chains->ptype == LIST_TYPE)
        {

    /*freeing the list function*/
          if ((destroyList(chains->value->list_val)) == 1) {
      /*if freed the list successfully*/
          } else {
      /*memory leak error List not freed*/
            printf("\nMemory Error, List not Freed\n");
            return 0;
          }
        }
  /*free the union struct for */
        free(chains->value);
  /*freeing the string in element and then freeing the element */
        free(chains->identifier);
        free(chains);
      }
    }
  }
  /*freeing the elements starting with head and then the table*/
  free(table->head_element);
  free(table);
  return 1;
}
/*******************************************************************************************************/
/*Parameter Manager Function: Manage function to determine what parameters the parameter manager*/
/*adding parameters to the hash table*/
int PM_manage(ParameterManager *p, char *pname, param_t ptype, int required) {
  /*variable declaration*/
  int temphash_index = 0;
  elements * checker = NULL,* newelement = NULL;
  /*checks whether the input parameters are valid and appropiate*/
  if ((p != NULL) && (required >= 0) && (strlen(pname) != 0)) {

    /*Checking whether the pname exist in the manager*/
    

    /*The pname is not in the manager, add it to the list*/
    if ((checker = search_param(p, pname)) == NULL) {
      /*gets the hash index value of pname using the hash function*/
      temphash_index = hashing(p, pname); 

      /*checks to make sure that the newelement was malloced properly*/
      if ((newelement = malloc(sizeof(elements))) != NULL) {

  /*assigning values to the new element from the parameter input*/
        char * temp_string = malloc(sizeof(char) * (strlen(pname) + 1));
        newelement->identifier = strcpy(temp_string, pname);
        newelement->required = required;
        newelement->ptype = ptype;
        newelement->has_val = 0;
      } else {
  /*memory allocation error*/
        printf("\nMemory Allocation Failed: Parameter");
        return 0;
      }
      /*mallocing union struct */
      if ((newelement->value = malloc(sizeof(union param_value))) != NULL) {
  /*if the ptype is string, set string to null*/
        if (ptype == STRING_TYPE){
          newelement->value->str_val=NULL;
    /*if ptype is list, set list to null*/
        }else if(ptype == LIST_TYPE){
          newelement->value->list_val=NULL;
        }
      } else {
  /*memory allocation error*/
        printf("\nMemory Allocation Failed: Union\n");
        return 0;
      }

      /*adding the new element in the table*/
      newelement->next = p->head_element[temphash_index];
      p->head_element[temphash_index] = newelement;
      /*returns 1 on success*/
      return 1;

    } else {
      /*memory allocation error*/
      /*the element alrdy exist at that index value in the table*/
      printf("\nPARSE ERROR:An element alreadt existed with the same name parameter");
      return 0;
    }
  } else {
    /*invalid parameter error*/
    printf("\nInvalid PM_manage Parameter Values!\n");
    /*return 0*/

    return 0;
  }
  return 0;
}

/*******************************************************************************************************/
/*Parameter Manager Required Function: checks to see whether all the required parameters have been assigned a value*/
/*Returns 0 if a require parameter has not been assigned a value! else true.*/
int required(ParameterManager * p) {
  int i = 0;
  elements * temp;
  /*a for loop to iterate through the whole Parameter manager object*/
  for (i = 0; i < (p->size); i++) {
    /*if there is a chainning on a hash table index, go through the chainning*/
    for (temp = p->head_element[i]; temp != NULL; temp = temp->next) {
      /*check if the parameter registered is requried or not*/
      if ((p->head_element[i]->required) != 0) {
  /*check if the required parameter has been assigned a value already*/ 
        if ((p->head_element[i]->has_val) != 1) {
    /*if it does not then return 0. parse error*/
          return 0;
        }
      }

    }

  }
  /*return 1 for success*/
  return 1;
}
/*******************************************************************************************************/
/*Parameter Manager Parse Function: takes in a file pointer parameter and parses the required parameters registered in the Parameter
Manager*/
int PM_parseFrom(ParameterManager *p, FILE *fp, char comment) {

  /*Variable Declaration*/
  char character, buffer_param[1024] = { }, buffer_value[1024] = { },
  list_token[1024] = { };
  char * token;
  int i = 0, j = 0, param = 0;
  Boolean enforce = true, stringtype = false;
  param_t find_type;
  int equal_count=1;
  Boolean reading = false;

  elements * param_checker;
         /*checking if the comment character is any of the character mention below and if it is, it is a parse error*/
  if (comment == ';' || comment == ' ' || comment == '{' || comment == '}'
    || comment == '=' || comment == ',') {
     /*invalid parameter error*/
    printf("\nParse ERROR: Invalid comment symbol\n");
    return 0;
  } else {
     /*checks if the file pointer is empty or not*/
    if (fp != NULL) {
       /*A while loop that iterates through the whole inputed parameter file and parses data*/
      while ((character = fgetc(fp)) != EOF) {

         /************************************************************************************/
         /*If the character is a comment*/
        if (character == comment) {
           /*increment character until it goes to new line*/
           /*check for if the last character is a comment*/
          if ((character = fgetc(fp)) == EOF) {
            break;
            
          } else {
       /*while loop that iterates the character until new line is found*/
            while (character != '\n' && character != EOF) {
              character = fgetc(fp);
            }
          }

        }
         /*if the character is and quoation, sets the string flags on and off*/
        else if (character == '"') {
           /*if the flag is on, turn it off and vice versa*/
          if (stringtype == false) {
            stringtype = true;
       /*if the string flag is off, then add the quotation character into the buffer value*/
            if (param != 0) {
              buffer_value[j] = '"';
              j++;
            }
          } else {
       /*setting the string flag off and adding quoatation character to the buffer value*/
            stringtype = false;
            if (param != 0) {
              buffer_value[j] = '"';
              j++;
            }
          }
           /*if the character is a new line*/
        }else if(character == '\n'){
           /*if the string flag is on add the new line character*/
          if (stringtype == true) {
            if (param != 0) {
         /*adds a new line character in the buffer value*/
              buffer_value[j] = '\n';
              j++;
            }
          }

        }
         /*checking if the character is a space and if the string type is on add space char in the buffer value*/
         else if (isspace(character) != 0) /*if the character is a white space*/
        {
           /*if string flag is on, add the space in the value buffer*/
          if (stringtype == true) {
            if (param != 0) {
                  /*adds a space character*/
              buffer_value[j] = ' ';
              j++;
            }
          }else{

         if (param != 0) /*Value*/
         {
           /* code */
           if (reading == true)
          {
            if(stringtype == false){
              if(buffer_value[0]!='{'){ 
                while((character = fgetc(fp))!= ';' ){

                if(character == comment){break;}
                if(isalnum(character)!=0 ){
                  printf("\nParse Error \n");
                  return 0;
                }

                }
                  character = ungetc(character,fp);
              }
            }
        }

         }
         
        }
           /*if the character is equal sign then check if string is on or off*/
        } else if (character == '=') {
           /*if the string is on, add the equal sign in the value buffer*/
          if (stringtype == true) {
            if (param != 0) {
         /*adds a equal sign character*/
              buffer_value[j] = '=';
              j++;
            }
          }
          
           param = 1;/*settting the param flag to value mode*/
          equal_count++;
        }
         /*if the character is equal sign, then value buffer */
        else if (character == ';') {
          reading = false;
          
           /*Found the identifier in the list*/
          if ((param_checker = search_param(p, buffer_param)) != NULL) {
       /*checks if the parameter has been assigned a value*/
            if (PM_hasValue(p, buffer_param) != 1) {
         /*Finding the type registered to the parameter*/
              find_type = param_checker->ptype;

         /*Switch case for determining the type of buffer_value*/
              switch (find_type) {
           /*different cases*/
                case 0:
             /*checking for int type*/
                for (i = 0; i < strlen(buffer_value); i++) {

         /*if the characters in the buffer value are made up of integers*/
                  if ((isdigit(buffer_value[i]) == 0)
                    || (buffer_value[i] == '.')) {
           /*if the value buffer contains a negative in front*/
                    if (buffer_value[0] == '-') {
                      enforce = true;
                    } else {
                      enforce = false;
                    }
                  }
                }
             /*if the flag is on, parse the integer value else parse error*/
                if (enforce == true) {
                  param_checker->value->int_val =
                  atoi(buffer_value);
                  param_checker->has_val = 1;

                } else {
         /*Parse error*/
                  printf("\nRegistered Parameter Type Error: INT TYPE\n");
                  return 0;
                }
                break;
           case 1:/* for checking real type and enforcing it*/

                for (i = 0; i < strlen(buffer_value); i++) {
         /*if the characters in the buffer value are made up of integers*/
                  if ((isdigit(buffer_value[i]) == 0)
                    && (buffer_value[i] != '.')) {
           /*adding a negative sign if the value is negative */
                    if (buffer_value[0] == '-') {
                      enforce = true;
                    } else {
             /*enforce flag is set to false*/
                      enforce = false;
                    }
                  }
                }
             /*to assign the real type value to the element*/
                if (enforce == 1) {
                  param_checker->value->real_val =
                  atof(buffer_value);
         /*sets the has value to 1*/
                  param_checker->has_val = 1;
                } else {
         /*Parse error*/
                  printf( "\n Parsing-Registered Parameter Type Error: REAL TYPE\n");
                  return 0;
                }
                break;

           case 2: /*FOR boolean check type*/
             /*checking to see if the value equals and matches the format for boolean, either by text or integer*/
                if (strcmp(buffer_value, "true") == 0) {
         /*assigns the boolean value to 1*/
                  param_checker->value->bool_val =
                  1;
                  param_checker->has_val = 1;
         /*sets the has value to 1*/

                } else if (strlen("false") == strlen(buffer_value)) {
           /*assigns the boolean value to 0*/
                  param_checker->value->bool_val = 0;
                  param_checker->has_val = 1;
           /*sets the has value to 1*/
                } else {
           /*Parse error*/
                  printf("\nParsing-Registered Parameter Type Error: BOOLEAN TYPE\n");
                  return 0;
                }
                break;
           case 3: /*for string type*/
             /*string type found, check whether the first and last characters are quotations*/
                if (buffer_value[0] == '"'
                  && buffer_value[strlen(buffer_value) - 1]
                  == '"') {
         /*for loop gets rid of the quotations*/
                  for (i = 0; i < (strlen(buffer_value));
                    i++) {
                    buffer_value[i] = buffer_value[i + 1];
                }
         /*gets rid of the last quotations*/
                buffer_value[strlen(buffer_value) - 1] ='\0';
             /*allocates the memory for string in value struct*/
                if ((param_checker->value->str_val =malloc(sizeof(char) * strlen( buffer_value) + 1)) != NULL) {
         /*copies the values from buffer value into string*/
                  strcpy( param_checker->value->str_val, buffer_value);
         /*sets the has value to 1*/
                  param_checker->has_val = 1;
                } else {
         /*parse error*/
                  printf("\nParsing-Registered Parameter Type Error: STRING TYPE ->Not able to Malloc for String\n");
                  return 0;
                }

              } else {
           /*parse error*/
                printf("\nParse ERROR: Invalid Values of %s Read\n", buffer_param);
                return 0;
              }

              break;
           case 4: /*for list type */
             /*checks whether param value has open and close brackets*/
              if ((buffer_value[0] == '{')&& (buffer_value[strlen(buffer_value)- 1] == '}')) {
         /*checks if the list is empty*/
                if (strlen(buffer_value) != 2) {

           /*removes the open and close bracket*/
                  for (i = 0; i < (strlen(buffer_value));i++) {
                    buffer_value[i] = buffer_value[i + 1];
                  }
                  buffer_value[strlen(buffer_value) - 1] = '\0';
           /*copys the buffer value in new list token since strtok is destructive in tokenizing*/
                  strcpy(list_token, buffer_value);
           /*checks if the list was created successfully*/
                  if ((param_checker->value->list_val =param_create()) != NULL) {

                    token = strtok(list_token, ",");
             /*Tokenizes the individual values in the list*/
                    while (token) {
               /*while token lenght move all the character by 1 to remove th quotations*/
                      for (i = 0; i < (strlen(token));i++) {
                        token[i] = token[i + 1];
                      }
               /*removes the last character quotations*/
                      token[strlen(token) - 1] = '\0';
               /*adds the strings tokenized into the list*/
                      if ((addParamList(param_checker->value->list_val,token)) == 1) {
                      } else {
           /*parse error*/
                        printf("\nParse Error ParameterList: Item not added to List\n");
                      }
               /*tokenizes by the null pointer delimited by , */
                      token = strtok(NULL, ",");
                    }
             /*sets the has value to 1 for the list*/
                    param_checker->has_val =1;
                  } else {
             /*parse error*/
                    printf("\nParsing-Registered Parameter Type Error: LIST TYPE->Not able to malloc for List\n");
                    return 0;
                  }
                } else
                {
           /*the list is empty*/ 
           /*removes the open and close bracket*/
                  for (i = 0; i < (strlen(buffer_value));i++) {
                    buffer_value[i] = '\0';
                  }
           /*creates a new list*/
                  if ((param_checker->value->list_val = param_create()) != NULL) {
             /*adds the value into the list*/
                    if ((addParamList(param_checker->value->list_val,buffer_value)) == 1) {
               /*sets the has value to 1*/
                      param_checker->has_val =1;

                    } else {
               /*parse error*/
                      printf("\nParse Error ParameterList: Item not added to List\n");
                    }
                  }

                }

              } else {
         /*parse error*/
                printf("\nParsing-Registered Parameter Type Error: LIST TYPE-> No '}' bracket\n");
                return 0;
              }

              break;
              default:
         /*default case where nothing matches*/
              printf("\nParsing-Registered Parameter Type Error: INVALID TYPE\n");
              return 0;

            }
          }

        }
         /*Resetting the buffer values for Param and Value*/
         /*clear the buffer*/
        memset(buffer_value, '\0', strlen(buffer_value));
        memset(buffer_param, '\0', strlen(buffer_param));
         /*reset the buffer character counter*/
        i = 0;
        j = 0;
         /*reseting the param flag param mode*/
        param = 0;
        equal_count--;

      } else {

         /*the parameter state*/
        if (param == 0) {
           /*add the character to the buffer parameter*/
          buffer_param[i] = character;
           /*increment the counter for buffer parameter*/
          i++;
         } else /*The value state*/
          {
             reading = true;
           /*add the character to the buffer parameter*/
              buffer_value[j] = character;
           /*incrementing the buffer value parameter*/
            j++;
          }
        }
      }
    }

    if(equal_count !=1){
      printf("\nParse Error Equal Sign\n");
      return 0;
    }

         /*checks all the registered required parameters have been assigned a value*/
    if (required(p)) {
     /*all required are parsed*/
    } else {
     /*parse error*/
      printf("\nPARSE error: Not all required functions are parsed\n");
      return 0;
    }
  }
  return 1;
}

/*******************************************************************************************************/


