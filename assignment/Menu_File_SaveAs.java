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
/*SAve as action listener*/
public class Menu_File_SaveAs implements ActionListener {

    Dialogc SaveAs;

    public Menu_File_SaveAs (Dialogc main) {

        SaveAs = main;
    }
    /*action listener*/
    @Override
    public void actionPerformed(ActionEvent e) {

        int value2;
        JFileChooser saver = new JFileChooser();
        saver.setAcceptAllFileFilterUsed(false);
        saver.setFileFilter(new FileNameExtensionFilter("configuration", ".config"));
        /*checks if the object is null*/
        if (SaveAs.fileobject == null) {
            try {
                SaveAs.fileobject = new File(new File(".").getCanonicalPath());
            } catch (IOException e1) {
                // TODO Auto-generated catch block
                JOptionPane.showMessageDialog(SaveAs.getContentPane(), e1,"Error in SaveAS function for: " + SaveAs.project_title,JOptionPane.ERROR_MESSAGE, null);
            }
        }
        /*gets the current directory*/
        File temp2Dir = new File(System.getProperty("user.dir"));
        saver.setCurrentDirectory(temp2Dir);
        value2 = saver.showSaveDialog(saver);
        /*checks for the user input*/
        if (value2 == JFileChooser.APPROVE_OPTION) {
            SaveAs.fileobject = saver.getSelectedFile();
            /*gets the config file*/
            if ((SaveAs.fileobject.getName().toLowerCase().endsWith(".config")) == false) {
                SaveAs.fileobject = new File(saver.getSelectedFile() + ".config");
                /*checcks if there already exits and other file with same name*/
                if (SaveAs.fileobject != null && SaveAs.fileobject.exists()) {
                    value2 = JOptionPane.showConfirmDialog(null,"There already exist "+ SaveAs.fileobject.getName()+ " Would you like to replace the existing file?",
                            "File Already Exits with the Same Name!",JOptionPane.YES_NO_OPTION,JOptionPane.WARNING_MESSAGE);
                    /*if the useer said yes*/
                    if (value2 == JOptionPane.YES_OPTION) {
                        try {
                            /*creates the print stream and prints the information*/
                            PrintStream printerSaveAs = new PrintStream(SaveAs.fileobject);
                            printerSaveAs.print(SaveAs.file_editor.getText());
                            SaveAs.file_new = false;
                            SaveAs.text_modified = false;
                            SaveAs.project_title = SaveAs.fileobject.getName();
                            SaveAs.file_title.setTitle(SaveAs.project_title);
                            SaveAs.label_status.setText("Current Project: " + SaveAs.project_title.substring(0, SaveAs.project_title.lastIndexOf('.')));
                            SaveAs.getContentPane().repaint();
                            printerSaveAs.close();

                        } catch (FileNotFoundException e1) {
                            // TODO Auto-generated catch block
                            JOptionPane.showMessageDialog(SaveAs.getContentPane(), e1,"Error in SaveAS function for: "+ SaveAs.project_title,JOptionPane.ERROR_MESSAGE, null);
                        }

                    } else {
                        /*checks for the user input and if they didnt enter .config, automatically assigned .config ext*/
                        if ((SaveAs.fileobject.getName().toLowerCase().endsWith(".config")) == false) {
                            SaveAs.fileobject = new File(saver.getSelectedFile()+ "1" + ".config");
                        }
                        try {
                            /*creates a print stream and writes to the file*/
                            PrintStream printerSaveAs = new PrintStream(SaveAs.fileobject);
                            printerSaveAs.print(SaveAs.file_editor.getText());
                            SaveAs.file_new = false;
                            SaveAs.text_modified = false;
                            SaveAs.project_title = SaveAs.fileobject.getName();
                            SaveAs.file_title.setTitle(SaveAs.project_title);
                            SaveAs.label_status.setText("Current Project: " + SaveAs.project_title.substring(0, SaveAs.project_title.lastIndexOf('.')));
                            SaveAs.getContentPane().repaint();
                            printerSaveAs.close();

                        } catch (FileNotFoundException e1) {
                            
                            JOptionPane.showMessageDialog(SaveAs.getContentPane(), e1,"Error in SaveAS function for: "+ SaveAs.project_title,JOptionPane.ERROR_MESSAGE, null);
                        }
                    }
                } else {
                    /* save the file */
                    try {
                        /*creates print stream and saves to file*/
                        PrintStream printerSaveAs = new PrintStream(SaveAs.fileobject);
                        printerSaveAs.println(SaveAs.file_editor.getText());
                        SaveAs.file_new = false;
                        SaveAs.text_modified = false;
                        SaveAs.project_title = SaveAs.fileobject.getName();
                        SaveAs.file_title.setTitle(SaveAs.project_title);
                        SaveAs.label_status.setText("Current Project: " + SaveAs.project_title.substring(0, SaveAs.project_title.lastIndexOf('.')));
                        SaveAs.getContentPane().repaint();
                        printerSaveAs.close();

                    } catch (FileNotFoundException e1) {
                      
                        JOptionPane.showMessageDialog(SaveAs.getContentPane(), e1,"Error in SaveAS for writing to file: "+ SaveAs.project_title,JOptionPane.ERROR_MESSAGE, null);
                    }
                }

            }
        }

    }
}
