/**
 * ****************************************************************************************************************
 */
/*  Dialogc Java Native Interface Wrapper C file
 *  Course : CIS 2750 
 *  Prof. David McCaughan
 *  Assignment 2: Graphical User Interfaces
 *  Created on: Jan 26, 2015
 *  Last Modified: Feb 13, 2015
 *  Author: Dipkumar Patel
 *  Student ID: 0763246
 *  Email: dipkumar@mail.uoguelph.ca
 */
/*******************************************************************************************************************
******  *  ******  *  *  *    *   **    **        **      ******
*    *  *  *    *  * *   *    *   * *  * *       *  *     *    *
*    *  *  ******  **    *    *   *  *   *      *    *    *    *
*    *  *  *       **    *    *   *      *     ********   * **
*    *  *  *       * *   *    *   *      *    *        *  *  *
******  *  *       *  *  ******   *      *   *          * *   *
*******************************************************************************************************************/
/*Library imports*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;
import javax.swing.*;
import javax.swing.border.BevelBorder;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

/* Compile Listerner */
public class Menu_Compile_C implements ActionListener {

    Dialogc comp;

    public Menu_Compile_C(Dialogc main) {
        comp = main;
    }
    /*compiler listener*/
    @Override
    public void actionPerformed(ActionEvent e) {
        int test_pass=0;
        int a,save=0;
        /*checks if the editor textarea is empty and if  compile is true and whether the text is modified or not*/
        if((comp.file_editor.getText().isEmpty())==false) {
                if (comp.file_new == true) {
                    if (comp.text_modified == true) {
                        /*Trys to saveAs*/
                        try {
                            /*checks for modification before conpiling file*/
                            Menu_File_SaveAs saveAs_file = new Menu_File_SaveAs(comp);
                            saveAs_file.actionPerformed(null);
                             JOptionPane.showMessageDialog(comp.getContentPane(), "Project Saved","Ready to Compile",JOptionPane.INFORMATION_MESSAGE, null);
                             save =1;
                        } catch (Exception ex) {

                            JOptionPane.showMessageDialog(comp.getContentPane(), ex,
                                    "Error in SaveAs: " + comp.project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                        }
                    } else {
                        a = JOptionPane.showOptionDialog(comp.option_pane,
                            "Would you like to save " + comp.project_title
                            + " document?", "Before You compile the Project: "
                            + comp.project_title,
                            JOptionPane.YES_NO_CANCEL_OPTION,
                            JOptionPane.QUESTION_MESSAGE, null, comp.options,
                            comp.option_pane);
                        if (a==0){
                            /*agains checks if the file is not new */
                            if (comp.text_modified == true) {
                                try {
                                    save =1;
                                    Menu_File_Save save_file = new Menu_File_Save(comp);
                                    save_file.actionPerformed(null);
                                    JOptionPane.showMessageDialog(comp.getContentPane(), "Project Saved","Ready to Compile",JOptionPane.INFORMATION_MESSAGE, null);
                                } catch (Exception ex) {

                                    JOptionPane.showMessageDialog(comp.getContentPane(), ex,
                                            "Error in SaveAs: " + comp.project_title,
                                            JOptionPane.ERROR_MESSAGE, null);
                                }
                            }else{
                                 save =1;
                                JOptionPane.showMessageDialog(comp.getContentPane(), "Project Saved","Ready to Compile",JOptionPane.INFORMATION_MESSAGE, null); 
                            }
                        }else{
                            save =0;
                        }
                    }

                } else {
                     if (comp.text_modified == true) {
                        a = JOptionPane.showOptionDialog(comp.option_pane,
                                "Would you like to save " + comp.project_title
                                + " document?", "Before You compile the Project: "
                                + comp.project_title,
                                JOptionPane.YES_NO_CANCEL_OPTION,
                                JOptionPane.QUESTION_MESSAGE, null, comp.options,
                                comp.option_pane);
                        if (a==0){
                            /*agains checks if the file is not new */
                           
                                try {
                                    save =1;
                                    Menu_File_Save save_file = new Menu_File_Save(comp);
                                    save_file.actionPerformed(null);
                                    JOptionPane.showMessageDialog(comp.getContentPane(), "Project Saved","Ready to Compile",JOptionPane.INFORMATION_MESSAGE, null);
                                } catch (Exception ex) {

                                    JOptionPane.showMessageDialog(comp.getContentPane(), ex,
                                            "Error in SaveAs: " + comp.project_title,
                                            JOptionPane.ERROR_MESSAGE, null);
                                }
                            
                        }else{
                            save =0;
                        }

                   }else{
                        save =1;
                        JOptionPane.showMessageDialog(comp.getContentPane(), "Project Saved","Ready to Compile",JOptionPane.INFORMATION_MESSAGE, null); 
                    } 
                }
            if(save==1){
             /*compiles the code, checks which mode it set for compiler */
               if((comp.compiled_mode_lex)==false){
                    if (comp.compiled_code == false) {
                        /*IF Lex mode is not selected, uses parameter manager*/
                        try {
                            /* Creating a Parameter Manager */
                            if ((comp.JNI.PM_create(3)) == 1) {
                                System.out.println("\n  Parameter Manager Manage Passes\n");
                            } else {
                                test_pass =1;
                                System.out.println("\n Parameter Manager manage FAILED\n");
                            }

                            /* Managing the required default fields */
                            /**
                             * *************************
                             */
                            int test_manage = 0;

                            if ((comp.JNI.PM_manage("title", 3, 1)) == 1) {
                                test_manage = test_manage + 1;
                            } else {
                                test_pass =1;
                                System.out.println("\n Parameter Manager manage FAILED for title\n");
                            }

                            if ((comp.JNI.PM_manage("fields", 4, 1)) == 1) {
                                test_manage = test_manage + 1;
                            } else {
                                test_pass =1;
                                System.out.println("\n Parameter Manager manage FAILED for fields\n");
                            }

                            if ((comp.JNI.PM_manage("buttons", 4, 1)) == 1) {
                                test_manage = test_manage + 1;
                            } else {
                                test_pass =1;
                                System.out.println("\n Parameter manage FAILED for buttons\n");
                            }

                            if (test_manage == 3) {
                                System.out.println("\n  Parameter Manager Manage Passes count " + test_manage + "\n");
                            } else {
                                test_pass =1;
                                System.out.println("\n Parameter Manager manage FAILED count: " + test_manage + "\n");
                            }

                            /**
                             * **************************
                             */
                            /* Parsing values. */
                            String P_filename = comp.file_title.getTitle();

                            if ((comp.JNI.PM_parseFrom(P_filename, '#')) == 1) {
                                System.out.println("\n  Parameter Manager PARSE Passes\n");
                            } else {
                                test_pass =1;
                                System.out.println("\n Parameter Manager PARSE FAILED\n");
                            }

                            int test_has;
                            int test_has2;
                            int test_has3;
                            /**
                             * **********************************************
                             */
                            if ((test_has = comp.JNI.PM_hasValue("title")) == 1) {
                                comp.compile_GUI_title = comp.JNI.PM_getValue_String("title");
                                System.out.println("The title has assigned " + comp.compile_GUI_title);

                            } else {
                                test_pass =1;
                                System.out.println("The Title has not been assigned value");
                            }
                            /**
                             * *************************************************
                             */
                            if ((test_has2 = comp.JNI.PM_hasValue("fields")) == 1) {
                                int x = 0;
                                String fields_val;

                                while ((fields_val = comp.JNI.PM_getValue_List_string("fields")) != null) {
                                    comp.compile_GUI_fields.add(x, fields_val);
                                    System.out.println("The fields vlaue 1-- " + x + " has assigned " + comp.compile_GUI_fields.get(x));
                                    x = x + 1;
                                }
                                comp.field_size = x;

                            } else {
                                test_pass =1;
                                System.out.println("The Title has not been assigned value");
                            }
                            /**
                             * *************************************************
                             */
                            if ((test_has3 = comp.JNI.PM_hasValue("buttons")) == 1) {
                                int y = 0;
                                String button_val;

                                while ((button_val = comp.JNI.PM_getValue_List_string("buttons")) != null) {
                                    comp.compile_GUI_buttons.add(y, button_val);
                                    System.out.println("The button " + y + " has assigned " + comp.compile_GUI_buttons.get(y));
                                    y = y + 1;
                                }
                                comp.buttons_size = y;

                            } else {
                                test_pass =1;
                                System.out.println("The Title has not been assigned value");
                            }
                            /**
                             * ********
                             */
                            comp.JNI.PM_destroy();

                        } catch (Exception C) {
                            test_pass =1;
                            JOptionPane.showMessageDialog(comp.getContentPane(), C,
                                    "Error in Compile parse 1: " + comp.project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                        }
                        /**
                        * *************************************************
                        */
                        /*Seconds Parse*/
                        try {
                             String pare2 = comp.file_title.getTitle();
                            int count2 = 0;
                            String fields_val;
                            int count3 = 0;
                            String buttons_val;

                            /*create 2*/
                            if ((comp.JNI.PM_create(comp.field_size + 1)) == 1) {
                                System.out.println("\n  Parameter Manager Created 2 Passes\n");
                            } else {
                                test_pass =1;
                                System.out.println("\n Parameter Manager Created 2 FAILED\n");
                            }
                            /*manage for fields*/
                            for (int t = 0; t < comp.compile_GUI_fields.size(); t++) {
                                try {

                                    if ((comp.JNI.PM_manage(comp.compile_GUI_fields.get(t), 3, 0)) == 1) {
                                           System.out.println("\n  Parameter Manager manage 2 Passes\n");
                                    } else {
                                          test_pass =1;
                                          System.out.println("\n Parameter Manager manage 2 FAILED\n");
                                    }

                                    

                                } catch (Exception P) {
                                    test_pass =1;
                                    JOptionPane.showMessageDialog(comp.getContentPane(), P,
                                            "Error in Compile Parse 2: " + comp.project_title,
                                            JOptionPane.ERROR_MESSAGE, null);
                                }
                            }
                            /*Manages the buttons*/
                             for (int b = 0; b < comp.compile_GUI_buttons.size(); b++) {
                                    if ((comp.JNI.PM_manage(comp.compile_GUI_buttons.get(b), 3, 0)) == 1) {
                                        System.out.println("\n  Parameter Manager manage 2 Passes\n");
                                    } else {
                                        test_pass =1;
                                        System.out.println("\n Parameter Manager manage 2 FAILED\n");
                                    }

                                }
                            /*Parse 2*/

                            if ((comp.JNI.PM_parseFrom(pare2, '#')) == 1) {
                                System.out.println("\n  Parameter Manager PARSE 2 Passes\n");
                            } else {
                                test_pass =1;
                                System.out.println("\n Parameter Manager PARSE 2 FAILED\n");
                            }

                            /*getting required values and saving it to the array*/
                            for (String pnameVal : comp.compile_GUI_fields) {

                                if ((comp.JNI.PM_hasValue(pnameVal)) == 1) {
                                    fields_val = comp.JNI.PM_getValue_String(pnameVal);
                                    comp.compile_GUI_field_types.add(count2, fields_val);
                                    System.out.println("The types for: " + pnameVal + " is-> " + comp.compile_GUI_field_types.get(count2));
                                }
                                count2++;
                            }

                             /*getting required values and saving it to the array*/
                            for (String list : comp.compile_GUI_buttons) {

                                if ((comp.JNI.PM_hasValue(list)) == 1) {
                                    buttons_val = comp.JNI.PM_getValue_String(list);
                                    comp.compile_GUI_buttons_listen.add(count3, buttons_val);
                                    System.out.println("The types for: " + list + " is-> " + comp.compile_GUI_buttons_listen.get(count3));
                                }
                                count3++;
                            }

                        } catch (Exception M2) {
                            test_pass =1;
                            JOptionPane.showMessageDialog(comp.getContentPane(), M2,
                                    "Error in Compile Parse 2: " + comp.project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                        }
                        /*if successfull */
                        if(test_pass==0){
                            comp.compiled_code = true;
                             
                        code_generator make = new code_generator(comp);
                        make.actionPerformed(null);
                        }else{
                            JOptionPane.showMessageDialog(comp.getContentPane(), "The config file Not Compiled",
                                    "Error in Compile invalid Parse: " + comp.project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                        }
                    }
            }else{
                /*Using Lex to compile .config file*/
                 if (comp.compiled_code == false) {
                	 int exit=0;
                     /*Try to execute process */
                    try{
                        /*checking directory, making folder for output file to be sent to, executing process of yadc*/
                    	if((comp.default_W_dir.equals("."))) {
                            File dir = new File((comp.project_title.substring(0, comp.project_title.lastIndexOf('.'))));
                            dir.mkdir();
                            /*setting dir*/
                             comp.default_W_dir =System.getProperty("user.dir") +"/"+(comp.project_title.substring(0, comp.project_title.lastIndexOf('.')));
                            /*useful prints*/
                             System.out.println("WORKING DIR AT COMPILE LEX: "+comp.default_W_dir);
                             System.out.println("./yadc "+ comp.project_title+" "+(comp.project_title.substring(0, comp.project_title.lastIndexOf('.')))+"/" + (comp.project_title.substring(0, comp.project_title.lastIndexOf('.')))+".java"); 
                             
                             Process run_process = Runtime.getRuntime().exec("./yadc "+ comp.project_title+" "+(comp.project_title.substring(0, comp.project_title.lastIndexOf('.')))+"/" + (comp.project_title.substring(0, comp.project_title.lastIndexOf('.')))+".java") ;
                            exit = run_process.waitFor();
                        }else{
                            /*Not default DIr*/
                            System.out.println("\n\nWORK DIR NOT . \n\n");
                             File dir = new File(comp.default_W_dir+ (comp.project_title.substring(0, comp.project_title.lastIndexOf('.'))));
                            dir.mkdir();
                            /*setting dir*/
                             comp.default_W_dir = comp.default_W_dir+"/" +(comp.project_title.substring(0, comp.project_title.lastIndexOf('.')))+"/";
                            /*useful prints*/
                             System.out.println("WORKING DIR AT COMPILE LEX: "+comp.default_W_dir);
                             System.out.println("./yadc "+ comp.project_title+" "+comp.default_W_dir+ (comp.project_title.substring(0, comp.project_title.lastIndexOf('.')))+".java") ;
                             
                             Process run_process = Runtime.getRuntime().exec("./yadc "+ comp.project_title+" "+comp.default_W_dir+ (comp.project_title.substring(0, comp.project_title.lastIndexOf('.')))+".java") ;
                            exit = run_process.waitFor();
                        }
                        /*Checking the exit value of the process*/
                        if (exit == 0) {
                            /*succesful*/
                             System.out.println("Code Compiled correctly, and error code: " + exit);
                             comp.gen_path =  comp.project_title.substring(0, comp.project_title.lastIndexOf('.')) + ".java";
                             System.out.println(comp.gen_path);

                             JOptionPane.showMessageDialog(comp.getContentPane(), "Code Compiled correctly","Code Compiled",
                                    JOptionPane.INFORMATION_MESSAGE, null);
                         }else{
                            /*Failed*/
                              System.out.println("Code Compilation failed: error occured on Line Number: "+exit);
                              JOptionPane.showMessageDialog(comp.getContentPane(), "The config file Not Compiled "+ "\nError Occured on Line number: "+exit,
                                    "Error in Config File " + comp.project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                         }
                     }catch(Exception lex){
                        JOptionPane.showMessageDialog(comp.getContentPane(), "The config file Not Compiled" + "\nError Occured on Line number: "+exit,
                                    "Error in Compile invalid Parse LEX: " + comp.project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                    }
                  
                }
            }
         }
        }else{
                /*empty .config file*/
                JOptionPane.showMessageDialog(comp.getContentPane(), "The config file is Empty",
                                "Error in Compile invalid Input: " + comp.project_title,
                                JOptionPane.ERROR_MESSAGE, null);
            }
    }
}
