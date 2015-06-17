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
/*save as action listener class*/
public class Menu_File_Save implements ActionListener {

    Dialogc save;

    public Menu_File_Save(Dialogc main) {
        save = main;
    }
    /*action listener*/
    @Override
    public void actionPerformed(ActionEvent e) {
        /*checks if the file is new */
        if (save.file_new == true) {
            try {
                /*save As option*/
                Menu_File_SaveAs saveAs_file = new Menu_File_SaveAs(save);
                saveAs_file.actionPerformed(null);
            } catch (Exception S) {
                JOptionPane.showMessageDialog(save.getContentPane(), S,
                        "Error in SaveAs: " + save.project_title,
                        JOptionPane.ERROR_MESSAGE, null);
            }
        } else {
            try {
                /*create a print stream and save the file*/
                PrintStream printer = new PrintStream(save.fileobject);
                printer.print(save.file_editor.getText());
                save.file_new = false;
                save.text_modified = false;
                save.project_title = save.fileobject.getName();
                save.file_title.setTitle(save.project_title);
                save.label_status.setText("Current Project: "
                        + save.project_title.substring(0, save.project_title.lastIndexOf('.')) + "--File Saved.");
                save.getContentPane().repaint();
                printer.close();

            } catch (FileNotFoundException e1) {
                // TODO Auto-generated catch block
                JOptionPane.showMessageDialog(save.getContentPane(), e1,
                        "Error in Saving writing to file: " + save.project_title,
                        JOptionPane.ERROR_MESSAGE, null);
            }
        }
    }
}
