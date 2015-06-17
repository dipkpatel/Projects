/* YACC file
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
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "linkedlist.h"
	int yyerror(char *s);
	int error_check;
	int yylex();
	int line_co=0;
	char * Vtitle = NULL;
	LinkedList * Vfields = NULL;
	LinkedList * Vbuttons = NULL;
	FILE * error;
	extern int yylineno;
	extern char * yytext;

%}


%union{
	int int_val;
	char *string_val;
}

%token <string_val> TOKEN 
%token TITLE
%token FIELDS
%token BUTTONS
%token QUOATATION
%token LEFTBRACE
%token RIGHTBRACE
%token EQUALS
%token SEMICOLON
%token ERRORMSG
%token COMMA


%%

statements: expression
		  | statements expression
		  ;
expression: title 
		  | fields
		  | buttons
		  | string_value
		  | emptylist
		  | parseerror
		  ;

/*Title allocations*/
title: TITLE EQUALS QUOATATION TOKEN QUOATATION SEMICOLON {
	Vtitle = malloc(sizeof(char *)*strlen($4)*1);
	strcpy(Vtitle, $4);
	printf("The title is set to %s\n", Vtitle);
	free($4);
	

}
/*fields*/
fields: FIELDS EQUALS LEFTBRACE f_values RIGHTBRACE SEMICOLON

f_values: fitem 
		| f_values COMMA fitem
		;

/*Buttons*/
buttons: BUTTONS EQUALS LEFTBRACE b_values RIGHTBRACE SEMICOLON
		
b_values: bitem
		| b_values COMMA bitem
		;
/*Actual string for fields*/
fitem: QUOATATION TOKEN QUOATATION {
	printf("Found for Fields item: %s\n", $2); 
	add_List(Vfields, $2); 
	free($2);

}
/*Actual String for Buttons*/
bitem: QUOATATION TOKEN QUOATATION {
	printf("Found For Buttons item: %s\n", $2);
	add_List(Vbuttons, $2);
	free($2); 
}
/*Strings for Values*/
string_value: TOKEN EQUALS QUOATATION TOKEN QUOATATION SEMICOLON{
	printf("Left side: %s Right Side %s \n",$1,$4);
	node * tempF = Vfields->head;
	node * tempB = Vbuttons->head;
	int check =0;
	
	/*check for fields*/
		while(tempF!=NULL){
			/*Checking the Type of if Values of Field matches*/
			if((strcmp(tempF->string,$1))==0){
				printf("The String -> %s matches the string -> %s \n",tempF->string,$1);
				if(tempF->value==NULL){	
					/****Checking the Value of Field****/
					if((strcmp($4,"string"))==0){
						if ((tempF->value = malloc(sizeof(char) * (strlen($4) + 1)))!=NULL){
							strcpy(tempF->value,$4);
							printf("The value record:-> %s\n",tempF->value);
							free($4);	
						}
					}else if((strcmp($4,"integer"))==0){
						if ((tempF->value = malloc(sizeof(char) * (strlen($4) + 1)))!=NULL){
							strcpy(tempF->value,$4);
							printf("The value record:-> %s\n",tempF->value);
							free($4);	
						}
					}else if ((strcmp($4,"float"))==0){
						if ((tempF->value = malloc(sizeof(char) * (strlen($4) + 1)))!=NULL){
							strcpy(tempF->value,$4);
							printf("The value record:-> %s\n",tempF->value);
							free($4);	
						}
					}else{
					/*The Value did not match either string, float or integer*/
						printf("\nPARSE ERROR: The %s value: %s did not match  either string, float or integer\n",$1,tempF->value);
						return line_co;
					}
				}else{
					printf("\nDuplicate String for %s found at line %d ",tempF->value,line_co);
					return line_co;
				}
				check =1;
			}
		tempF = tempF->next;
		}
	

	/*checking for buttons*/
		if(check == 0){
			while(tempB!=NULL){
				/*comparing the value button with button name*/
				if((strcmp(tempB->string,$1))==0){
					printf("The String -> %s matches the string -> %s \n",tempB->string,$1);
						/*if matched*/
					if((tempB->value = malloc(sizeof(char) * (strlen($4) + 1)))!=NULL){
						strcpy(tempB->value,$4);
						printf("The value record:-> %s\n",tempB->value);
						free($4);
					}
				}
			tempB = tempB->next;
			}
		}
}
/*Error detector*/
parseerror: ERRORMSG{
	
	fprintf(error,"Error Occured On Char: %s on line %d \n",yytext,line_co);
	fprintf(stderr, "Error Occured On Char: %s on line %d \n",yytext,line_co);
	return line_co;

}


/*empty list detector, but error mangages empty list*/
emptylist: BUTTONS|FIELDS EQUALS LEFTBRACE RIGHTBRACE SEMICOLON{
	fprintf(error, "\nEmpty List\n");
	fprintf(stderr,"\nEmpty List\n");
	return line_co;
}
%%
/*exter variable*/

extern FILE *yyin;
extern FILE * yyout;
extern FILE * error;
extern int yyparse();
extern int line_co;
/*Main function*/
int main(int argc, const char *argv[])
{	
	/*Variable Declaration*/
	
	char * filename;
	int eCheck = 0;
	error = fopen("error.txt","w");
	/* create the field and buttons list that will be used for parsing */
	Vfields = list_create();
	Vbuttons = list_create();

	/*check for if list got created properly*/
	if ((Vfields==NULL)&&(Vbuttons==NULL)) {
		fprintf(error,"\nFields list and Buttons List creation Error\n");
		fclose(yyin);
		exit(-1);
	}
	/*checking command line arguments*/
	if (argc < 2){
		fprintf(error,"\nNeed Proper Command Line Arguments\n");
		fprintf(error,"./yadc [input file name] [output file name]\n");
		printf("\nNeed Proper Command Line Arguments\n");
		printf("./yadc [input file name] [output file name]\n");
		fclose(yyin);
		
		exit(-1);
	}else{
		/*valid arguement*/
		printf("The Input file : %s\n",argv[1]);
		yyin = fopen(argv[1],"r");
		filename = malloc(sizeof(char)*strlen(argv[1])+1);
		filename = strtok((char*)argv[1],".");
	}
	
	/*check for open and close streams*/
	if (yyin==NULL){
		fprintf(error,"\nFile Stream Parameters not Set.\nPlease check command line arguements\n");
		printf("\nFile Stream Parameters not Set.\nPlease check command line arguements\n");
	
		exit(-1);
	}

	/*Parsing the Lex info*/
	 while (!feof(yyin)){
	 	eCheck =  yyparse();
	 }
	 /*check to see parse was successful*/
	 if (eCheck==0){
	 		printf("\n\nARG 2 IS %s\n",argv[2]);
			yyout = fopen(argv[2],"w");
			/*checking if output stream is empty or not*/
			if(yyout==NULL){
				fprintf(error,"\nerror in opening and creating write file\n\n");
				
				exit(-1);
			}

	 }else{
	 	/*parse error occured*/
	 	fprintf(error,"Error Occured Parsing .Config File on Line %d\n",line_co);
	 	
	 	return line_co;
	 }
	/*pointers to head of lists*/
	 node * temp_F = Vfields->head;
	 node * temp_B = Vbuttons->head;
	 /*checking for whether all field and buttons have been asssigned a value*/
	  /*checking fields*/
	  if(temp_F!=NULL){

		 while(temp_F!=NULL){
			if (temp_F->string!=NULL){
				if(temp_F->value == NULL){
					eCheck = 1;
				}
			}
			temp_F = temp_F->next;
			}
		}else{
			fprintf(error,"\n\n\nNULL TEMP Field\n\n\n");
			eCheck =1;
		}
		/*checking buttons*/
		if(temp_B!=NULL){
			while(temp_B!=NULL){
				if (temp_B->string!=NULL){
					if(temp_B->value == NULL){
						eCheck = 1;
					}
				}
				temp_B = temp_B->next;
			}
		}else{
			fprintf(error,"\n\n\nNULL TEMP Buttons\n\n\n");
			eCheck =1;
		}

	 /*if successful parse, generate file*/
	 if(eCheck == 0){

	 	/*variable declaration*/
		 int count=0;
		 /*Writing to main file */
		 fprintf(yyout,"import java.awt.*;\nimport java.awt.event.*;\nimport javax.swing.*;\nimport java.io.*;\nimport java.util.Scanner;\nimport javax.swing.border.*;\nimport java.util.ArrayList;\nimport java.lang.*;");
		 fprintf(yyout, "\n\npublic class %s extends JFrame implements %sFieldEdit {\n",filename,filename);
		 fprintf(yyout,"\n\n\t/*GUI STuff*/\n\n");
		 fprintf(yyout,"\tJPanel buttons_GUI = new JPanel();\n");
		 fprintf(yyout,"\t JPanel compile_panel_text = new JPanel();\n");
		 fprintf(yyout,"\t JPanel compile_panel = new JPanel();\n");
		 fprintf(yyout,"\t JPanel split = new JPanel();\n");
		 fprintf(yyout,"\t JTextArea message_GUI = new JTextArea();\n");
		 fprintf(yyout,"\t JScrollPane message_GUI_scroll = new JScrollPane(message_GUI);\n\n");
		 fprintf(yyout,"\t /*Layout stuff*/\n\n");
		 fprintf(yyout,"\t Box left = Box.createVerticalBox();\n");
		 fprintf(yyout,"\t Box right = Box.createVerticalBox();\n");
		 fprintf(yyout,"\t Box horizontal = Box.createHorizontalBox();\n");
		 fprintf(yyout,"\t TitledBorder status_GUI = new TitledBorder(BorderFactory.createEmptyBorder());\n");
			 /*writing generic textfields*/
			 temp_F = Vfields->head;
			 if(temp_F!=NULL){

				 while(temp_F!=NULL){
					fprintf(yyout, "\n\tJTextField text_field%d = new JTextField();\n",count);
					fprintf(yyout, "\tJLabel field_label%d = new JLabel();\n",count);
					count++;
					temp_F = temp_F->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field\n\n\n");
			}
			/*writing generic buttons*/
			temp_B = Vbuttons->head;
			 if(temp_B!=NULL){
			 	count=0;
				 while(temp_B!=NULL){
					fprintf(yyout, "\n\tJButton button%d =  new JButton(\"%s\");",count,temp_B->string);
					count++;
					temp_B = temp_B->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field\n\n\n");
			}
		/*constructor*/
		fprintf(yyout, "\n\n\tpublic %s (){\n\n\tsuper();",filename);	 
		fprintf(yyout, "\n\n\tsplit.setLayout(new BorderLayout());\n");
		fprintf(yyout," \tthis.setTitle(\"%s\");\n",Vtitle);
		fprintf(yyout," \t this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);\n");
		fprintf(yyout," \t this.setSize(600,600);\n");
		fprintf(yyout," \t this.setLocationRelativeTo(null);\n");
		fprintf(yyout," \t this.setLayout(new BorderLayout());\n");
		fprintf(yyout," \t message_GUI.setEditable(false);\n");
		fprintf(yyout," \t status_GUI.setTitle(\"----Status----\");\n");
		fprintf(yyout," \t message_GUI_scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);\n");
		fprintf(yyout," \t message_GUI_scroll.setBorder(BorderFactory.createEtchedBorder());\n");
		fprintf(yyout," \t message_GUI_scroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);\n");
		fprintf(yyout," \t message_GUI_scroll.setBorder(status_GUI);\n");
		fprintf(yyout," \t buttons_GUI.setLayout(new BoxLayout(buttons_GUI,BoxLayout.LINE_AXIS));\n");
			/*Setting Field Values*/
			temp_F = Vfields->head;
			if(temp_F!=NULL){
				count=0;
				 while(temp_F!=NULL){
					fprintf(yyout, "\n\n\tfield_label%d.setBorder(BorderFactory.createEtchedBorder());\n",count);
					fprintf(yyout,"\tfield_label%d.setFont(new Font(\"Times\", Font.BOLD, 16));\n",count);
					fprintf(yyout,"\tfield_label%d.setSize(text_field%d.getPreferredSize());\n",count,count);
					fprintf(yyout,"\tfield_label%d.setText(\"%s\");\n",count,temp_F->string);
					fprintf(yyout,"\tleft.add(field_label%d);\n",count);
					fprintf(yyout,"\t right.add(text_field%d);\n",count);
					count++;
					temp_F = temp_F->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field setting\n\n\n");
			}

			/*Setting buttons values*/
			temp_B = Vbuttons->head;
			 if(temp_B!=NULL){
			 	count=0;
				 while(temp_B!=NULL){
					fprintf(yyout, "\n\t button%d.addActionListener(new %s (this) );",count,temp_B->value);
					fprintf(yyout, "\n\tbuttons_GUI.add(button%d);\n",count);
					count++;
					temp_B = temp_B->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field\n\n\n");
			}
		/*setting things in place*/
		fprintf(yyout,"\thorizontal.add(left);\n\thorizontal.add(right);\n\tadd(horizontal,BorderLayout.NORTH);");
		fprintf(yyout,"\n\tsplit.add(buttons_GUI,BorderLayout.NORTH);\n");
		fprintf(yyout, "\tsplit.add(message_GUI_scroll,BorderLayout.CENTER);\n");
		fprintf(yyout,"\tadd(split,BorderLayout.CENTER);");
		fprintf(yyout,"\n\t}");
		
			/*Setters for field*/
			temp_F = Vfields->head;
			if(temp_F!=NULL){
				count=0;
				 while(temp_F!=NULL){
					fprintf(yyout, "\n\n\tpublic void setDC%s (String text){\n",temp_F->string);
					fprintf(yyout,"\n\t\t text_field%d.setText(text);",count);
					fprintf(yyout,"\n\t}");
					count++;
					temp_F = temp_F->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field setter\n\n\n");
			}

			/*Getters for Field*/
			temp_F = Vfields->head;
			if(temp_F!=NULL){
				count=0;
				 while(temp_F!=NULL){
					fprintf(yyout, "\n\n\tpublic String getDC%s (){\n\n",temp_F->string);
					fprintf(yyout,"\n\t\tString %s= null;",temp_F->string);
					fprintf(yyout,"\n\t\tint int_%s = 0;",temp_F->string);
					fprintf(yyout,"\n\t\tfloat float_%s = 0.0f;",temp_F->string);
					/*Trying to figure out which type values it is and setting appropiate generic functionality*/
					if((strcmp(temp_F->value,"float"))==0) { /*float*/
						fprintf(yyout,"\n\n\t\tif((text_field%d.getText())!= null && (text_field%d.getText().isEmpty())!=true){",count,count);
						fprintf(yyout,"\n\n\t\t\ttry{");
						fprintf(yyout,"\n\n\t\t\tfloat_%s =  Float.parseFloat(text_field%d.getText());",temp_F->string,count);
						fprintf(yyout,"\n\t\t}catch(Exception ef){");
						fprintf(yyout,"\n\t\t\tthrow new IllegalFieldValueException(text_field%d.getText());",count);
						fprintf(yyout,"\n\t\t}");
						fprintf(yyout,"\n\n\t\t\treturn text_field%d.getText();\n\n\t\t\t}",count);

					}else if((strcmp(temp_F->value,"integer"))==0){ /*Integers*/

						fprintf(yyout,"\n\n\t\tif((text_field%d.getText())!= null && (text_field%d.getText().isEmpty())!=true){",count,count);
						fprintf(yyout,"\n\n\t\t\ttry{");
						fprintf(yyout,"\n\n\t\t\tint_%s =  Integer.parseInt(text_field%d.getText());",temp_F->string,count);
						fprintf(yyout,"\n\t\t}catch(Exception ef){");
						fprintf(yyout,"\n\t\t\tthrow new IllegalFieldValueException(text_field%d.getText());",count);
						fprintf(yyout,"\n\t\t\t}");
						fprintf(yyout,"\n\n\t\t\treturn text_field%d.getText();\n\n\t\t\t}",count);
					}else{ /*string*/
						fprintf(yyout, "\n\n\t\tif ((text_field%d.getText())!= null && (text_field%d.getText().isEmpty())!=true){",count,count);
						fprintf(yyout, "\n\t\t\t %s = text_field%d.getText();",temp_F->string,count);
						fprintf(yyout, "\n\n\t\treturn %s;",temp_F->string);
						fprintf(yyout, "\n\n\t\t}");
					}
					/*finish the get methods*/
					fprintf(yyout,"\n\n\t\treturn null;");
					fprintf(yyout,"\n\n\t}");
					count++;
					temp_F = temp_F->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field for getters\n\n\n");
			}
		/*append to status message*/
		fprintf(yyout, "\n\n\tpublic void appendToStatusArea(String message){\n");
		fprintf(yyout,"\n\t\t message_GUI.append(message+\" \\n \");"); 
		fprintf(yyout, "\n\n\t}");
		/*main function*/
		fprintf(yyout, "\n\n\n\tpublic static void main(String[] args) {\n");
		fprintf(yyout, "\n\t\t %s  %sinstance = new %s ();",filename,filename,filename);
		fprintf(yyout, "\n\t\t %sinstance.setVisible(true);\n\n",filename);
		fprintf(yyout, "\n\t}\n\n}");
		/***********Writing the interface, fieldEdit file************/
		/*variable declaration*/
		char inter[50], dest[50],dirname[50];
		/*getting exact output and destination for file*/
		strcpy(inter,filename);
		strcpy(dest,"FieldEdit");
		strcpy(dirname,"/");
		strcat(dirname,filename);
		strcat(inter,dirname);
		strcat(inter,dest);
		strcat(inter,".java");
		printf("The inter %s\n",inter );

			/*creating the interface*/
			if((yyout = fopen(inter,"w"))!=NULL){
					/*writing to the file*/
				fprintf(yyout, "import java.awt.*;\n");
				fprintf(yyout, "import java.awt.event.*;\n");
				fprintf(yyout, "import javax.swing.*;\n");
				fprintf(yyout, "import java.io.*;\n");
				fprintf(yyout, "import java.util.Scanner;\n");
				fprintf(yyout, "import javax.swing.border.*;\n");
				fprintf(yyout, "import java.util.ArrayList;\n");
				fprintf(yyout,"import java.lang.*;");
				fprintf(yyout,"\n\npublic interface %sFieldEdit  {\n",filename);
				fprintf(yyout,"\n\n/*Getter methods*/\n\n");
				
				/*Setters for field*/
				temp_F = Vfields->head;
				if(temp_F!=NULL){
					 while(temp_F!=NULL){
						fprintf(yyout, "\n\tpublic String getDC%s ();",temp_F->string);
						temp_F = temp_F->next;
						}
				}else{
					fprintf(error,"\n\n\nNULL TEMP Field setter\n\n\n");
				}
				fprintf(yyout,"\n\n/*Setter methods*/\n\n");
				
				/*Setters for field*/
				temp_F = Vfields->head;
				if(temp_F!=NULL){
					 while(temp_F!=NULL){
						fprintf(yyout, "\n\tpublic void setDC%s (String text);",temp_F->string);
						temp_F = temp_F->next;
						}
				}else{
					fprintf(error,"\n\n\nNULL TEMP Field setter\n\n\n");
				}

				fprintf(yyout,"\n\n\tpublic void appendToStatusArea(String message);\n");
				fprintf(yyout,"\n\n}");
			}/*closing the streams*/
		/**********Writing Illegal Field Exception class file*************************/
		
		char inter1[50], dest1[50],name1[50];
		strcpy(inter1,filename);
		strcpy(dest1,"/");
		strcpy(name1,"IllegalFieldValueException.java");
		strcat(inter1,dest1);
		strcat(inter1,name1);
		
		/*printing the exception handler*/
		if((yyout = fopen(inter1,"w"))!=NULL){
				
				fprintf(yyout,"import java.lang.*;");
				fprintf(yyout,"\n\npublic class IllegalFieldValueException extends RuntimeException  {\n");
				fprintf(yyout,"\n\n\tpublic IllegalFieldValueException(String ef){\n\n");
				fprintf(yyout, "\n\n\t\tsuper(ef);\n\n\t}\n}");
		}

		 fclose(yyin);
		 fclose(yyout);
	}else{
		fprintf(error,"Value of error_check%d\n",eCheck );
	
		return line_co;
	}
	destroyList(Vfields);
	destroyList(Vbuttons);
return 0;
}
/*Error function used by yacc*/
int yyerror(char *s) { 
	fprintf(stderr,"Error Occured On Char: %s on line %d \n",yytext,line_co); 
	fprintf(error,"Error Occured On Char: %s on line %d \n",yytext,line_co); 
	return line_co;
}






