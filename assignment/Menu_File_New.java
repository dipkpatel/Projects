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

/* For menu- File */
public class Menu_File_New implements ActionListener {

    Dialogc New;

    public Menu_File_New(Dialogc main) {
        New = main;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        /*new action listener*/
        int x;
        String newName = new String();
        /*checks if the file is new or not*/
        if (New.file_new == true) {
            if (New.text_modified == true) {
                /*checks for the option the user chooses*/
                x = JOptionPane.showOptionDialog(
                        New.option_pane,
                        "Would you like to save the Current Project? \n Please Click Yes to save the Current Project, No to Discard the Current Project or Cancel to return to Current Project . ",
                        "Do you Want to Save the Current Project before Creating a New One?",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE, null,
                        New.options, New.option_pane);
                /*if the user selects yes*/
                if (x == JOptionPane.YES_OPTION) {
                    try {
                        /*save As functions*/
                            Menu_File_SaveAs saveAs_file = new Menu_File_SaveAs(New);
                        saveAs_file.actionPerformed(null);
                    } catch (Exception e3) {
                        JOptionPane.showMessageDialog(New.getContentPane(), "Problem: " + e3,
                                "Error in SaveAS function for: "
                                + New.project_title,
                                JOptionPane.ERROR_MESSAGE, null);
                    }

                } else if (x == JOptionPane.NO_OPTION) {
                    /*if the user says no*/
                    New.file_new = true;
                    New.text_modified = false;
                    /*gets the new title*/
                    newName = JOptionPane.showInputDialog(null,
                            "Please enter a new Project Name: ",
                            "Specify the new name for the Project",
                            JOptionPane.QUESTION_MESSAGE);
                    New.project_title = newName;
                    New.file_title.setTitle(New.project_title + ".config");
                    New.label_status.setText("Current Project: " + New.project_title);
                    New.file_editor.setText("");
                    New.getContentPane().repaint();

                } else {
                }

            } else {
                /*gets the new title for the new project*/
                New.file_new = true;
                New.text_modified = false;

                newName = JOptionPane.showInputDialog(null,
                        "Please enter a new Project Name: ",
                        "Specify the new name for the Project",
                        JOptionPane.QUESTION_MESSAGE);
                /*sets the new information*/
                New.project_title = newName;
                New.file_title.setTitle(New.project_title + ".config");
                New.label_status.setText("Current Project: " + New.project_title);
                New.file_editor.setText("");
                New.getContentPane().repaint();
            }

        } else {
            /*  checks for modifiations*/
            if (New.text_modified == true) {
                x = JOptionPane.showOptionDialog(
                        New.option_pane,
                        "Would you like to save changes made to the Current Project? \n Please Click Yes to save the Current Project, No to Discard the changes or Cancel to return to the Current Project. ",
                        "Do you Want to Save the Changes made to the Current Project before Creating a New One?",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE, null,
                        New.options, New.option_pane);
                    /*gets user info*/
                if (x == JOptionPane.YES_OPTION) {
                    try {
                            Menu_File_Save save_file = new Menu_File_Save(New);
                        save_file.actionPerformed(null);
                    } catch (Exception e2) {
                        JOptionPane.showMessageDialog(New.getContentPane(), e2,
                                "Error in New function for: "
                                + New.project_title,
                                JOptionPane.ERROR_MESSAGE, null);
                    }
                    /*if they say no*/
                } else if (x == JOptionPane.NO_OPTION) {
                    New.file_new = true;
                    New.text_modified = false;
                    /*gets new title*/
                    newName = JOptionPane.showInputDialog(null,
                            "Please enter a new Project Name: ",
                            "Specify the new name for the Project",
                            JOptionPane.QUESTION_MESSAGE);
                    New.project_title = newName;
                    New.file_title.setTitle(New.project_title + ".config");
                    New.label_status.setText("Current Project: "
                            + New.project_title);
                    New.file_editor.setText("");
                    New.getContentPane().repaint();

                }
            } else {
                try {
                    /*call the save file action listener*/
                    Menu_File_Save save_file = new Menu_File_Save(New);
                    save_file.actionPerformed(null);

                    New.file_new = true;
                    New.text_modified = false;
                    /*get new title*/
                    newName = JOptionPane.showInputDialog(null,
                            "Please enter a new Project Name: ",
                            "Specify the new name for the Project",
                            JOptionPane.QUESTION_MESSAGE);
                    New.project_title = newName;
                    New.file_title.setTitle(New.project_title + ".config");
                    New.label_status.setText("Current Project: " + New.project_title);
                    New.file_editor.setText("");
                    New.getContentPane().repaint();

                } catch (Exception e4) {
                    JOptionPane.showMessageDialog(New.getContentPane(), e4,
                            "Error in SaveAS function for: "
                            + New.project_title,
                            JOptionPane.ERROR_MESSAGE, null);
                }
            }
        }

    }
}
