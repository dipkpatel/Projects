/* Lex file
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


%{
	#include "y.tab.h"
	 extern int line_co;
%}

%%
"title"										return TITLE;
"fields"									return FIELDS;
"buttons"									return BUTTONS;
\{											return LEFTBRACE;
\}											return RIGHTBRACE;
= 											return EQUALS;
;											return SEMICOLON;
, 											return COMMA;
"\""										return QUOATATION;
[a-zA-Z0-9_\-]+								yylval.string_val = strdup(yytext); return TOKEN;
#!# 										; /*Ignoring delimitor for 2nd parse*/
[ \t]										;
[\n]										line_co++;/*Ignoring whitespace, tabs and new lines*/
#[a-zA-Z0-9_\- ().-{}]+					    ;									
%%

int yywrap(void){
	return 1;
}