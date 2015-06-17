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
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;

public class code_generator implements ActionListener {

    Dialogc code_gn;

    public code_generator(Dialogc main) {

        code_gn = main;
    }
    /*Code generator class to print the code and create a java file interface*/

    @Override
    public void actionPerformed(ActionEvent e) {
        String class_name = code_gn.project_title.substring(0, code_gn.project_title.lastIndexOf('.'));
        PrintStream w;
        File file = null;
        File directory;
        File inter = null;
        int i, j;
        boolean new_dir;
        try {
            /*gets the current directory*/
            if ((code_gn.default_W_dir.equals("."))==true) {
                File dir = new File(class_name);
                dir.mkdir();
                file = new File(System.getProperty("user.dir") +"/"+(code_gn.project_title.substring(0, code_gn.project_title.lastIndexOf('.'))) +"/"+class_name+ ".java");
                inter = new File(System.getProperty("user.dir") +"/"+(code_gn.project_title.substring(0, code_gn.project_title.lastIndexOf('.')))+"/"+class_name+ "FieldEdit.java");
                code_gn.gen_path = class_name + ".java";
                code_gn.default_W_dir =System.getProperty("user.dir") +"/"+(code_gn.project_title.substring(0, code_gn.project_title.lastIndexOf('.')));
            } else {
                /*Not default DIR*/
                System.out.println("HERER");
                file = new File(code_gn.default_W_dir +"/"+ class_name + ".java");
                inter = new File(code_gn.default_W_dir +"/"+ class_name + "FieldEdit.java");
                code_gn.gen_path =  class_name + ".java";
                code_gn.default_W_dir = code_gn.default_W_dir;
            }
            /*check where it gets outputed*/
            System.out.println("Files generated at:->" +file.getAbsolutePath());
            System.out.println("Files generated at:->" +inter.getAbsolutePath());

        } catch (Exception WD) {
            JOptionPane.showMessageDialog(code_gn.getContentPane(), WD,
                    "Error in Compile-Code Code_Generator directory: " + code_gn.project_title,
                    JOptionPane.ERROR_MESSAGE, null);
        }

        try {
            /*creates the stream and prints the code required to create the interface.*/
            w = new PrintStream(file);
            /*imports*/
            w.print("import java.awt.*;\n"
                    + "import java.awt.event.*;\n"
                    + "import javax.swing.*;\n"
                    + "import java.io.*;\n"
                    + "import java.util.Scanner;\n"
                    + "import javax.swing.border.*;\n"
                    + "import java.util.ArrayList;\n"
                    + "import java.lang.*;");

            w.print("\n\npublic class " + class_name + " extends JFrame implements " + class_name + "FieldEdit" + " {\n");

            /*the variables*/
            w.print("\n\n\t/*GUI STuff*/\n\n"
                    + " \tJPanel buttons_GUI = new JPanel();\n"
                    + "\t JPanel compile_panel_text = new JPanel();\n"
                    + "\t JPanel compile_panel = new JPanel();\n"
                    + "\t JPanel split = new JPanel();\n"
                    + "\t JTextArea message_GUI = new JTextArea();\n"
                    + "\t JScrollPane message_GUI_scroll = new JScrollPane(message_GUI);\n\n"
                    + "\t /*Layout stuff*/\n\n"
                    + "\t Box left = Box.createVerticalBox();\n"
                    + " \t Box right = Box.createVerticalBox();\n"
                    + " \t Box horizontal = Box.createHorizontalBox();\n"
                    + " \t TitledBorder status_GUI = new TitledBorder(BorderFactory.createEmptyBorder());\n");

            /*creates the text from the fields*/
            for (i = 0; i < code_gn.field_size; i++) {
                String fieldname = code_gn.compile_GUI_fields.get(i);

                w.print("\n\n\tJTextField text_field" + i + " = new JTextField();\n" + "\n\tJLabel field_label" + i + " = new JLabel();\n");
            }
            /*creating buttons*/
            for (j = 0; j < code_gn.buttons_size; j++) {
                String buttonname = code_gn.compile_GUI_buttons.get(j);
                w.print("\n\tJButton button" + j + " =  new JButton(" + "\"" + buttonname + "\"" + ");");

            }
            /*Actual class*/
            w.print("\n\n\tpublic " + class_name + " (){\n\n\tsuper();");

            /*frame setting*/
            w.print("\n\n\tsplit.setLayout(new BorderLayout());\n"
                    + " \tthis.setTitle(" + "\"" + class_name + "\"" + ");\n"
                    + " \t this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);\n"
                    + " \t this.setSize(600,600);\n"
                    + " \t this.setLocationRelativeTo(null);\n"
                    + " \t this.setLayout(new BorderLayout());\n"
                    + " \t message_GUI.setEditable(false);\n"
                    + " \t status_GUI.setTitle(" + "\"" + "----Status----" + "\"" + ");\n"
                    + " \t message_GUI_scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);\n"
                    + " \t message_GUI_scroll.setBorder(BorderFactory.createEtchedBorder());\n"
                    + " \t message_GUI_scroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);\n"
                    + " \t message_GUI_scroll.setBorder(status_GUI);\n"
                    + " \t buttons_GUI.setLayout(new BoxLayout(buttons_GUI,BoxLayout.LINE_AXIS));\n");
              /*sets the field info*/
            for (i = 0; i < code_gn.field_size; i++) {
                String fieldname = code_gn.compile_GUI_fields.get(i);

                w.print("\n\n\tfield_label" + i + ".setBorder(BorderFactory.createEtchedBorder());\n"
                        + "\tfield_label" + i + ".setFont(new Font(" + "\"" + "Times" + "\"" + ", Font.BOLD, 16));\n"
                        + "\tfield_label" + i + ".setSize(text_field" + i + ".getPreferredSize());\n");

                w.print("\tfield_label" + i + ".setText(" + "\"" + fieldname + "\"" + ");\n"
                        + "\tleft.add(field_label" + i + ");\n"
                        + "\t right.add(text_field" + i + ");\n");
            }
            /*adding action listener for buttons*/
            for (j = 0; j < code_gn.buttons_size; j++) {
                w.print("\n\t button"+j+".addActionListener(new "+code_gn.compile_GUI_buttons_listen.get(j)+"(this) );");
                w.print("\n\tbuttons_GUI.add(button" + j + ");\n");
            }
            
            /*putting everything in place*/
            w.print("\thorizontal.add(left);\n\thorizontal.add(right);\n\tadd(horizontal,BorderLayout.NORTH);"
                    + "\n\tsplit.add(buttons_GUI,BorderLayout.NORTH);\n"
                    + "\tsplit.add(message_GUI_scroll,BorderLayout.CENTER);\n"
                    + "\tadd(split,BorderLayout.CENTER);");
            w.print("\n\t}");

            /*getter and setter methods*/
            for (i = 0; i < code_gn.field_size; i++) {
                String fieldname = code_gn.compile_GUI_fields.get(i);
                w.print("\n\n\tpublic void setDC" + fieldname + " (String text){\n\n");
                w.print("\n\t\t text_field" + i + ".setText(text);");
                w.print("\n\n\t}");
            }
            /*sets and creates setters*/
            for (j = 0; j < code_gn.field_size; j++) {
                String fieldname = code_gn.compile_GUI_fields.get(j);
                String field_type = code_gn.compile_GUI_field_types.get(j);
                w.print("\n\n\tpublic String getDC" + fieldname + " (){\n\n");
                w.print("\n\t\tString " + fieldname + " = null;");
                w.print("\n\t\tint int_" + fieldname + " = 0;");
                w.print("\n\t\tfloat float_" + fieldname + " = 0.0f;");
                
                if (field_type.equalsIgnoreCase("float")) {
                  /*checks for the parse field types */
                    w.print("\n\n\t\tif((text_field" + j + ".getText())!= null && (text_field" + j + ".getText().isEmpty())!=true){");
                    w.print("\n\n\t\t\ttry{");
                    w.print("\n\n\t\t\tfloat_" + fieldname + " =  Float.parseFloat(text_field" + j + ".getText());");
                    w.print("\n\t\t}catch(Exception ef){");
                    w.print("\n\t\t\tthrow new IllegalFieldValueException(text_field"+j+".getText());\n\t\t}");
                    w.print("\n\n\t\t\treturn Float.toString(float_" + fieldname + ");\n\n\t\t\t}");
                } else if (field_type.equalsIgnoreCase("integer")) {

                    w.print("\n\n\t\tif((text_field" + j + ".getText())!= null && (text_field" + j + ".getText().isEmpty())!=true){");
                    w.print("\n\n\t\t\ttry{");
                    w.print("\n\n\t\t\tint_" + fieldname + " = Integer.parseInt(text_field" + j + ".getText());");
                    w.print("\n\t\t}catch(Exception ef){");
                   w.print("\n\t\t\tthrow new IllegalFieldValueException(text_field"+j+".getText());\n\t\t}");
                    w.print("\n\n\t\t\treturn (text_field" + j + ".getText());\n\n\t\t\t}");
                } else {
                    w.print("\n\n\t\tif ((text_field" + j + ".getText())!= null && (text_field" + j + ".getText().isEmpty())!=true){");
                    w.print("\n\t\t\t " + fieldname + " = text_field" + j + ".getText();");
                    w.print("\n\n\t\treturn (text_field" + j + ".getText() );");
                    w.print("\n\n\t\t}");

                }

                w.print("\n\n\t\treturn null;");
                w.print("\n\n\t}");/*for the function*/

            }
            /*creats the append method*/
            w.print("\n\n\tpublic void appendToStatusArea(String message){\n");
            w.print("\n\t\t message_GUI.append(message+\" \\n \");");
            w.print("\n\n\t}");
            /*main function*/
            w.print("\n\n\n\tpublic static void main(String[] args) {\n");
            w.print("\n\t\t" + class_name + " " + class_name + "instance" + " = new " + class_name + "();");
            w.print("\n\t\t" + class_name + "instance.setVisible(true);\n\n");
            /*end file brackets*/
            w.print("\n\t}\n\n}");
            w.close();
        } catch (Exception CG) {

            JOptionPane.showMessageDialog(code_gn.getContentPane(), CG,
                    "Error in Compile-Code Code_Generator: " + code_gn.project_title,
                    JOptionPane.ERROR_MESSAGE, null);
        }

        try {
          /*creates the interface */
            w = new PrintStream(inter);

            /*imports*/
            w.print("import java.awt.*;\n"
                    + "import java.awt.event.*;\n"
                    + "import javax.swing.*;\n"
                    + "import java.io.*;\n"
                    + "import java.util.Scanner;\n"
                    + "import javax.swing.border.*;\n"
                    + "import java.util.ArrayList;\n"
                    + "import java.lang.*;");
            /*class for interface*/
            w.print("\n\npublic interface " + class_name + "FieldEdit" + " {\n");
            w.print("\n\n/*Getter methods*/\n\n");
            /*gettters headers*/
            for (j = 0; j < code_gn.field_size; j++) {
                String field_name = code_gn.compile_GUI_fields.get(j);
                w.print("\n\tpublic String getDC" + field_name + " ();");

            }
            /*setter headers*/
            w.print("\n\n/*Setter methods*/\n\n");
            for (j = 0; j < code_gn.field_size; j++) {
                String field_name2 = code_gn.compile_GUI_fields.get(j);
                w.print("\n\tpublic void setDC" + field_name2 + " (String text);");
            }
            w.print("\n\n\tpublic void appendToStatusArea(String message);\n");
            w.print("\n\n}");
            w.close();

        } catch (Exception CI) {
           
            JOptionPane.showMessageDialog(code_gn.getContentPane(), CI,
                    "Error in Compile-Code Code_Generator interface: " + code_gn.project_title,
                    JOptionPane.ERROR_MESSAGE, null);
        }

        try{
            /*Generating the illegal field exception file*/
            File illegal = new File(System.getProperty("user.dir") +"/"+(code_gn.project_title.substring(0, code_gn.project_title.lastIndexOf('.')))+"/"+"IllegalFieldValueException.java");
            w = new PrintStream(illegal);
            
            System.out.println("Files generated at:->" +illegal.getAbsolutePath());
            
            w.print("import java.lang.*;");
            w.print("\n\npublic class IllegalFieldValueException extends RuntimeException  {\n");
            w.print("\n\n\tpublic IllegalFieldValueException(String ef){\n\n");
            w.print("\n\n\t\tsuper(ef);\n\n\t}\n}");
            w.close();
        }catch(Exception II){
             JOptionPane.showMessageDialog(code_gn.getContentPane(), II,
                    "Error in Compile-Code Code_Generator IllegalFieldValueException: " + code_gn.project_title,
                    JOptionPane.ERROR_MESSAGE, null);
        }
    
    JOptionPane.showMessageDialog(code_gn.getContentPane(),"Code Generation Successful", "Successful Code Generation ", JOptionPane.INFORMATION_MESSAGE);
    
    }

}
