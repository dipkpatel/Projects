   Dialogc Lex/Yacc External Parser
   Course : CIS 2750 
   Prof. David McCaughan
   Assignment 3: System Tools/Visualization
   Created on: March 7, 2015
   Last Modified: March 13, 2015
   Author: Dipkumar Patel
   Student ID: 0763246
   Email: dipkumar@mail.uoguelph.ca


Purpose : To use system tools to available for parsing and generation of the java code. 
          A more efficient and easier way to use a high level parser Lex/Yacc. 
          It provides the same functionality as the Parameter Manager, however, 
          Lex/Yacc executable called yadc can be used externally without the dependancy of Dialogc GUI. 



Limitations: 1).Due to my limited knowledge of Lex and Yacc, the token for title 
                string cannot contain space inside of the string. However, for 
                user convinence they can use underscore "_" or dash "-" to seperate 
                words. This also applies to String values inside of the field and 
                buttons list.

             2).Due lack of skill and time, the interface using lex/yacc was not throughly tested.
               If config file has duplicate value assignment, it will result in parse error.

             3).The path and arguements for the external yadc executable must be provided correctly
               and must be appropiate formatted. 

             4).The working directory may not work when if switched for external parse but works for parameter
                manager.]

             5).Parse the .config file appropriately and have the mandatory field, title, and buttons, along with their 			respective 
                values, list are should not empty.


Assumptions: 1).All the Get method as specified by Assignment Two return strings. 
               Therefore, even int and for float values will be returned as string 
               and must be Parsed in order to get the actual data type of the string 
               correctly.

            2).The User know how to operate a basic GUI interface. If error occurs, 
               given line number can detect the error they made and fix it before compiling.

            3).User provides an appropiate action listener to the Interface created.

            4).Before Compiling checking if all the Config options are corect and valid.

            5).If User changes path for the working directory then they should also edit 
               Java compile flags and Java run time flags 

            6).The program checks and validates the text fields inputs and checks to see 
               if they match the required type.

            7).Program has functionality for action listeners for the buttons, so feel free 
               to attach actions listners.

            8).Parse the .config file appropriately and have the mandatory field, title, 
               and buttons, along with their respective values.
	

Compilation: In order to compile the library, simple "make" or "make all" would suffice to produce the Dialogc GUI. 
             For Only Generating the yadc executable, Simple "make yadc" command would suffice.
             The command line argument for yadc are: "./yadc [Absolute path for inputfile.config file] [Absolute path for 		     outputfile.java file]" 
             All error msg are prinited to a error.txt file. However, if no error is generated then error.txt is empty.

References: The theology and methodoloy for derivation and structural of the GUI was generated with the help
            from the Professor McCaughan who gave various information regarding the implementation of the GUI.
            Lex/Yacc parsing and generation was derived from slide notes provided by the TA and Professor McCaughan.

Comments by User: This GUI was created from long hours of staring competion betwen the computer monitor and 
                  myself. Please be gentle when using this fragile and delicate GUI. Do not Abuse or harass this program!!

