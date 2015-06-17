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

/*main GUI*/
/**
 * Dialogc Class Creating the GUI Window and its functionality author-Dip-Patel
 */
public class Dialogc extends JFrame {

    /**
     * **************************************************************************
     */
    /* The JNI */
    DialogcJNI JNI = new DialogcJNI();

    /*For the compiled GUI infomation storager*/
    ArrayList<String> compile_GUI_fields = new ArrayList<String>();
    ArrayList<String> compile_GUI_buttons = new ArrayList<String>();
    ArrayList<String> compile_GUI_field_types = new ArrayList<String>();
    ArrayList<String> compile_GUI_buttons_listen = new ArrayList<String>();

    String compile_GUI_title;

    /*Flags for the compiled GUI*/
    int field_size = 0, buttons_size = 0;
    boolean compiled_code = false;

    /* File chooser and Options */
    Object options[] = {"Save", "Discard", "Cancel"};
    Object error[] = {"Close"};
    JOptionPane option_pane = new JOptionPane();
    File fileobject = null;

    /*compiler vars*/
    String default_compile = "/usr/bin/javac";
    String default_compiled_run = "/usr/bin/java";
    String default_compile_option = " -g -cp ";
    String default_run_time_option = " -cp ";
    String default_W_dir = ".";
    String gen_path = "";
    boolean compiled_mode_lex = true; 

    /* Project Trackers */
    String project_title = "default";
    boolean text_modified = false;
    boolean file_new = true;
    int x; /*iterator*/

    /* Menu Bar and menu's */
    JMenuBar command = new JMenuBar();
    JMenu Mfile = new JMenu("File");
    JMenu Mcompile = new JMenu("Compile");
    JMenu Mconfig = new JMenu("Config");
    JMenu Mhelp = new JMenu("Help");
    JMenu Mmode = new JMenu("Compiled Mode"); 

    /* File menu items */
    JMenuItem newI = new JMenuItem("New");
    JMenuItem openI = new JMenuItem("Open");
    JMenuItem saveI = new JMenuItem("Save");
    JMenuItem saveAsI = new JMenuItem("SaveAs");
    JMenuItem quitI = new JMenuItem("Quit");

    /* Compile menu items */
    JMenuItem compileI = new JMenuItem("Compile");
    JMenuItem compile_runI = new JMenuItem("Compile & Run");

    /* Config menu items */
    JMenuItem java_compilerI = new JMenuItem("Java Compiler: Current-> " + default_compile);
    JMenuItem compile_optionI = new JMenuItem("Compile Options: Current-> " + default_compile_option);
    JMenuItem java_run_timeI = new JMenuItem("Java Run-Time: Current-> " + default_compiled_run);
    JMenuItem run_timeI = new JMenuItem("Run-Time Options: none");
    JMenuItem working_dirI = new JMenuItem("Working Directory: " + default_W_dir);
    JMenuItem param_mode = new JRadioButtonMenuItem("External Mode: Parameter Manager");
    JMenuItem lex_mode = new JRadioButtonMenuItem("Default mode: LEX/YACC Parser");
    /* Help menu items */
    JMenuItem helpI = new JMenuItem("Help");
    JMenuItem aboutI = new JMenuItem("About");
    /**
     * **************************************************************************
     */
    /*
     * The functionality of ImageIcon was derived from
     * http://www3.ntu.edu.sg/home/ehchua/programming/java/J4a_GUI_2.html#zz-1.1
     */

    /* image icons for the buttons */
    ImageIcon new_icon = new ImageIcon(Dialogc.class.getResource("ImageIcon/New24.gif"));
    ImageIcon open_icon = new ImageIcon(Dialogc.class.getResource("ImageIcon/Open24.gif"));
    ImageIcon save_icon = new ImageIcon(Dialogc.class.getResource("ImageIcon/Save24.gif"));
    ImageIcon saveAs_icon = new ImageIcon(Dialogc.class.getResource("ImageIcon/SaveAs24.gif"));
    ImageIcon compile_icon = new ImageIcon(Dialogc.class.getResource("ImageIcon/History24.gif"));
    ImageIcon run_icon = new ImageIcon(Dialogc.class.getResource("ImageIcon/Play24.gif"));
    
    /* creating button bar and buttons */
    JToolBar button_toolbar = new JToolBar();
    JButton new_buttons = new JButton(new_icon);
    JButton open_buttons = new JButton(open_icon);
    JButton save_buttons = new JButton(save_icon);
    JButton saveAs_buttons = new JButton(saveAs_icon);
    JButton compile_buttons = new JButton(compile_icon);
    JButton run_buttons = new JButton(run_icon);


    /* Editor text area */
    JTextArea file_editor = new JTextArea();
    JScrollPane Edit_scroll = new JScrollPane(file_editor);

    /* Status Bar and labels */
    JLabel label_status = new JLabel();
    JPanel Pstatus = new JPanel();
    TitledBorder file_title = new TitledBorder(BorderFactory.createBevelBorder(BevelBorder.LOWERED));

    /* File Objects */
    /**
     * **************************************************************************
     */
    /* constructor */
    public Dialogc() {
        /* setting up frame */
        super("Dialogc");
        setSize(800, 800);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());
        setTitle("Dialogc Dipkumar Patel");

        /* Menu bar */
        menubar();

        /* Buttons Tools */
        button_tool();

        /* Editor */
        editor();

        /* Status bar */
        Pstatus.setBorder(BorderFactory.createEtchedBorder());
        Pstatus.setPreferredSize(new Dimension(WIDTH, 25));
        label_status.setText("Current Project: " + project_title);
        Pstatus.add(label_status);
        add(Pstatus, BorderLayout.SOUTH);

    }

    /* EDITOR */
    public void editor() {

        /* text area */
        file_title.setTitle(project_title + ".config");
        file_editor.setEditable(true);
        file_editor.setFont(new Font("Times", Font.PLAIN, 16));
        file_editor.setBackground(Color.WHITE);
        file_editor.setBorder(BorderFactory.createEtchedBorder());
        file_editor.getDocument().addDocumentListener(new edit_listen());

        /* Scroll */
        Edit_scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        Edit_scroll.setBorder(BorderFactory.createEtchedBorder());
        Edit_scroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        Edit_scroll.setBorder(file_title);

        /* adding the scroll to the panel */
        add(Edit_scroll, BorderLayout.CENTER);

    }

    /* BUTTONS TOOLBAR */
    public void button_tool() {

        /* adding buttons to the action listeners */
        new_buttons.addActionListener(new Menu_File_New(this));
        open_buttons.addActionListener(new Menu_File_Open(this));
        save_buttons.addActionListener(new Menu_File_Save(this));
        saveAs_buttons.addActionListener(new Menu_File_SaveAs(this));
        compile_buttons.addActionListener(new Menu_Compile_C(this));
        run_buttons.addActionListener(new Menu_Compile_R(this));

        new_buttons.setToolTipText("Create New File Button");
        open_buttons.setToolTipText("Open Button");
        save_buttons.setToolTipText("Save Button");
        saveAs_buttons.setToolTipText("Save As Button");
        compile_buttons.setToolTipText("Compile Button");
        run_buttons.setToolTipText("Compile and Run Button");

        /* Buttons */
        button_toolbar.add(new_buttons);
        button_toolbar.add(open_buttons);
        button_toolbar.add(save_buttons);
        button_toolbar.add(saveAs_buttons);
        button_toolbar.add(compile_buttons);
        button_toolbar.add(run_buttons);
        button_toolbar.setAlignmentX(0);
        /*add to main frame*/
        add(button_toolbar, BorderLayout.NORTH);

    }

    /* MENU BAR */
    public void menubar() {

        /* Menu bar align */
        Mfile.setHorizontalTextPosition(SwingConstants.CENTER);
        Mcompile.setHorizontalTextPosition(SwingConstants.CENTER);
        Mconfig.setHorizontalTextPosition(SwingConstants.CENTER);
        Mhelp.setHorizontalTextPosition(SwingConstants.CENTER);

        /**
         * * Short Keys *
         */
        Mfile.setMnemonic(KeyEvent.VK_F);
        newI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N, Event.CTRL_MASK));
        openI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O, Event.CTRL_MASK));
        saveI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, Event.CTRL_MASK));
        saveAsI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_A, Event.CTRL_MASK));
        quitI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_Q, Event.CTRL_MASK));

        /* compile */
        Mcompile.setMnemonic(KeyEvent.VK_C);
        compileI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C, Event.CTRL_MASK));
        compile_runI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_R, Event.CTRL_MASK));

        /* config */
        Mconfig.setMnemonic(KeyEvent.VK_G);
        java_compilerI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_J, Event.ALT_MASK));
        compile_optionI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_I, Event.ALT_MASK));
        java_run_timeI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_T, Event.ALT_MASK));
        run_timeI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F, Event.CTRL_MASK));
        working_dirI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_W, Event.ALT_MASK));
        param_mode.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_M, Event.ALT_MASK));
        lex_mode.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_L, Event.ALT_MASK));
        /* help */
        Mhelp.setMnemonic(KeyEvent.VK_H);
        aboutI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_B, Event.CTRL_MASK));
        helpI.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_H, Event.CTRL_MASK));

        /**
         * ******
         */

        /* Action Listener Adding */
        /* File */
        newI.addActionListener(new Menu_File_New(this));
        openI.addActionListener(new Menu_File_Open(this));
        saveI.addActionListener(new Menu_File_Save(this));
        saveAsI.addActionListener(new Menu_File_SaveAs(this));
        quitI.addActionListener(new Menu_File_Quit(this));
        addWindowListener(new Menu_File_Quit(this));

        /* Compile */
        compileI.addActionListener(new Menu_Compile_C(this));
        compile_runI.addActionListener(new Menu_Compile_R(this));

        /* Config */
        java_compilerI.addActionListener(new Menu_Config_JC());
        compile_optionI.addActionListener(new Menu_Config_CO());
        java_run_timeI.addActionListener(new Menu_Config_JR());
        run_timeI.addActionListener(new Menu_Config_RT());
        working_dirI.addActionListener(new Menu_Config_WD());
        lex_mode.addActionListener(new Compile_mode_lex ());
        param_mode.addActionListener(new Compile_mode_param ());
        /* HELP */
        aboutI.addActionListener(new Menu_Help_About());
        helpI.addActionListener(new Menu_Help_Help());

        /* setting items in menu */
        /* file */
        Mfile.add(newI);
        Mfile.addSeparator();
        Mfile.add(openI);
        Mfile.addSeparator();
        Mfile.add(saveI);
        Mfile.addSeparator();
        Mfile.add(saveAsI);
        Mfile.addSeparator();
        Mfile.add(quitI);

        /* compile */
        Mcompile.add(compileI);
        Mcompile.addSeparator();
        Mcompile.add(compile_runI);

        /* config */
        Mconfig.add(java_compilerI);
        Mconfig.addSeparator();
        Mconfig.add(compile_optionI);
        Mconfig.addSeparator();
        Mconfig.add(java_run_timeI);
        Mconfig.addSeparator();
        Mconfig.add(run_timeI);
        Mconfig.addSeparator();
        Mconfig.add(working_dirI);
        Mconfig.addSeparator();
        lex_mode.setSelected(true);
        Mmode.add(lex_mode);
        Mmode.addSeparator();
        Mmode.add(param_mode);
        Mconfig.add(Mmode);
        /* help */
        Mhelp.add(aboutI);
        Mhelp.addSeparator();
        Mhelp.add(helpI);
        /**
         * *******************
         */
        setJMenuBar(command);
        /**
         * *******************
         */
        /* setting top command tabbed line */
        command.add(Mfile);
        command.add(Mcompile);
        command.add(Mconfig);
        command.add(Mhelp);
    }
    /**
     * ****************************************
     */
    /* Action Listener CLasses */
    /**
     * *******
     */
    /*Open menu command and buttons*/
    public class Menu_File_Open implements ActionListener {
        /*instance of GUI class*/
        Dialogc open;
        /*constructor*/
        public Menu_File_Open(Dialogc main) {
            open = main;
        }
        /*action listener for open button*/
        @Override
        public void actionPerformed(ActionEvent eve) {
            JFileChooser file_chooser = new JFileChooser();
            Scanner file_scan;
            int value;
            File tempDir;
            /*checks for different cases and executes accordingly*/
            if (text_modified == true) {
                x = JOptionPane.showOptionDialog(option_pane,
                        "Would you like to save " + project_title
                        + " document?", "Before You Close Project: "
                        + project_title + " Would you:",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE, null, options,
                        option_pane);
                /*checks what option user choose*/
                if (x == 0) {
                    /*checks for new files and perfroms based on outcome*/
                    if (file_new == true) {

                        try {
                            Menu_File_SaveAs saveAs_file = new Menu_File_SaveAs(open);
                            saveAs_file.actionPerformed(null);
                        } catch (Exception O) {
                            JOptionPane.showMessageDialog(rootPane, O,
                                    "Error in SaveAs: " + project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                        }
                    } else {
                        /*if it is not new then tries to saves the contents*/
                        try {
                            Menu_File_Save save_file = new Menu_File_Save(open);
                            save_file.actionPerformed(null);
                        } catch (Exception O) {
                            JOptionPane.showMessageDialog(rootPane, O,
                                    "Error in Save: " + project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                        }
                    }
                }
            }
            /*opening and reading file operations*/
            tempDir = new File(System.getProperty("user.dir"));
            file_chooser.setCurrentDirectory(tempDir);
            file_chooser.setFileFilter(new FileNameExtensionFilter(
                    "Configuration", "config"));
            file_chooser.setMultiSelectionEnabled(false);
            value = file_chooser.showOpenDialog(rootPane);
            /*file opening options*/
            if (value == JFileChooser.APPROVE_OPTION) {
                fileobject = file_chooser.getSelectedFile();
                /*checking if file exists*/
                if (fileobject.exists()) {
                    try {
                        file_scan = new Scanner(new FileInputStream(fileobject));
                        file_editor.setText("");

                        while (file_scan.hasNext()) {
                            file_editor.append(file_scan.nextLine() + "\n");
                        }
                        /*resetting values*/
                        file_new = false;
                        text_modified = false;
                        project_title = fileobject.getName();
                        file_title.setTitle(project_title);
                        label_status.setText("Current Project: "
                                + project_title.substring(0, project_title.lastIndexOf('.')));
                        getContentPane().repaint();
                    } catch (Exception e) {
                        JOptionPane.showMessageDialog(rootPane, e,
                                "Error in Opening file: " + project_title,
                                JOptionPane.ERROR_MESSAGE, null);
                    }
                }
            }
        }
    }
    /* Quit Action Listener and Window Listener
     * Checks for different cases and executes accordingly
     *
     */
    public class Menu_File_Quit implements ActionListener, WindowListener {
        Dialogc quit;
        public Menu_File_Quit(Dialogc main) {
            quit = main;
        }
        /*checks for modifications and asks to save or discard them*/
        @Override
        public void actionPerformed(ActionEvent e) {
            /*Checks for different cases and executes accordingly*/
            int val1;
            if (text_modified == true) {
                val1 = JOptionPane.showOptionDialog(option_pane,
                        "Would you like to save " + project_title
                        + " document?", "Before You Close Project: "
                        + project_title + " Would you:",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE, null, options,
                        option_pane);
                /*if user chooses to save the changes*/
                if (val1 == 0) {
                    if (file_new == true) {
                        /*save a new file*/
                        try {
                            Menu_File_SaveAs saveAs_file = new Menu_File_SaveAs(quit);
                            saveAs_file.actionPerformed(e);
                        } catch (Exception Q) {
                            JOptionPane.showMessageDialog(rootPane, Q,
                                    "Error in Quit: " + project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                        }
                    } else {
                        /*just normal save*/
                        try {
                            Menu_File_Save save_file = new Menu_File_Save(quit);
                            save_file.actionPerformed(e);
                        } catch (Exception Q) {
                            JOptionPane.showMessageDialog(rootPane, Q,
                                    "Error in Quit: " + project_title,
                                    JOptionPane.ERROR_MESSAGE, null);
                        }
                    }
                } else if (val1 == 1) {
                    System.exit(0);
                }
            } else {
                System.exit(0);
            }
        }
        @Override
        public void windowOpened(WindowEvent e) {
            // TODO Auto-generated method stub
        }
        @Override
        public void windowClosing(WindowEvent e) {
            /*same functions as quit action listener for the window listener*/
            int val1;
            if (text_modified == true) {
                /*checks user option*/
                val1 = JOptionPane.showOptionDialog(option_pane,
                        "Would you like to save " + project_title
                        + " document?", "Before You Close Project: "
                        + project_title + " Would you:",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE, null, options,
                        option_pane);
                if (val1 == 0) {
                    if (file_new == true) {
                        Menu_File_SaveAs saveAs_file = new Menu_File_SaveAs(quit);
                        saveAs_file.actionPerformed(null);
                    } else {
                        Menu_File_Save save_file = new Menu_File_Save(quit);
                        save_file.actionPerformed(null);
                    }
                } else if (val1 == 1) {
                    System.exit(0);
                }
            } else {
                System.exit(0);
            }
        }
        @Override
        public void windowClosed(WindowEvent e) {
            // TODO Auto-generated method stub
        }
        @Override
        public void windowIconified(WindowEvent e) {
            // TODO Auto-generated method stub
        }
        @Override
        public void windowDeiconified(WindowEvent e) {
            // TODO Auto-generated method stub
        }
        @Override
        public void windowActivated(WindowEvent e) {
            // TODO Auto-generated method stub
        }
        @Override
        public void windowDeactivated(WindowEvent e) {
            // TODO Auto-generated method stub
        }
    }
    /**
     * config action listener
     */
    private class Menu_Config_JC implements ActionListener {
        /*ask if they wish to browse or  manually enter path */
        @Override
        public void actionPerformed(ActionEvent e) {
            // TODO Auto-generated method stub
            Object[] comp_MORB = {"Manually", "Browse"};
            int check;
            check = JOptionPane.showOptionDialog(option_pane, "Would you like to enter a complete path to the compiler or Browse for the application?", "Please Select one Option for Entering Compiler:",
                    JOptionPane.YES_NO_OPTION,
                    JOptionPane.QUESTION_MESSAGE, null, comp_MORB,
                    option_pane);
            try {
                /*checks for user input and perfroms accordingly*/
                if (check == 1) {
                    /*brows*/
                    JFileChooser brows = new JFileChooser(default_W_dir);
                    int val;
                    File directory;
                    String filename;
                    val = brows.showOpenDialog(brows);
                    /*file chooser yes option*/
                    if (val == JFileChooser.APPROVE_OPTION) {
                        directory = brows.getCurrentDirectory();
                        filename = brows.getSelectedFile().getName();
                        default_compile = directory.getAbsoluteFile() + "/" + filename;
                        System.out.println("Path and file selected:-> " + default_compile);
                        java_compilerI.setText("Java Compiler: Current-> " + default_compile);
                        getContentPane().repaint();
                    }
                } else {
                    /*manually enter path*/
                    String path = JOptionPane.showInputDialog("Please enter full path->");
                    default_compile = path;
                    java_compilerI.setText("Java Compiler: Current-> " + default_compile);
                    getContentPane().repaint();
                    System.out.println("two selected-> " + path);
                }
            } catch (Exception JC) {
                JOptionPane.showMessageDialog(rootPane, JC,
                        "Error in Setting Java Compile: " + project_title,
                        JOptionPane.ERROR_MESSAGE, null);
            }
        }
    }
    /*File config option action listener*/
    private class Menu_Config_CO implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            /*checks for if the strign is empty or not*/
            try {
                String comp_option = JOptionPane.showInputDialog("Please enter the compile Options ->");
                if (!comp_option.isEmpty()) {
                    try {
                        /*access information from what user inputed in the textfield*/
                        default_compile_option = " " + comp_option + " ";
                        compile_optionI.setText("Java Compile Options: Current-> " + default_compile_option);
                        getContentPane().repaint();
                        System.out.println("compile options selected-> " + default_compile_option);
                        /*checks for cp*/
                        if (comp_option.contains("-cp")) {
                            working_dirI.setText("Working Directory:-> " + default_W_dir);
                            default_W_dir = "";
                            default_run_time_option = "";
                        } else {
                            default_compile_option = default_compile_option + " -cp ";
                        }
                    } catch (Exception CO) {
                        JOptionPane.showMessageDialog(rootPane, CO,
                                "Error in Setting Java Compile OPTIONS: " + project_title,
                                JOptionPane.ERROR_MESSAGE, null);
                    }
                }
            } catch (Exception CO) {
                    JOptionPane.showMessageDialog(rootPane, CO,
                            "Error in Setting Java Compile OPTIONS: " + project_title,
                            JOptionPane.ERROR_MESSAGE, null);
            }
        }
    }
    /*run time options action listener*/
    private class Menu_Config_RT implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try{
            /*checks for user entering manually runtime options*/
                String run_comp_option = JOptionPane.showInputDialog("Please enter the Run-Time Options ->");
                if (!run_comp_option.isEmpty()) {
                    try {
                        /*getting the runtime optiosn*/
                        default_run_time_option = " " + run_comp_option + " ";
                        run_timeI.setText("Java Runtime Options: Current-> " + default_run_time_option);
                        getContentPane().repaint();
                        System.out.println("compile options selected-> " + default_run_time_option);
                        /*checking for cp*/
                        if (run_comp_option.contains("-cp")) {
                            working_dirI.setText("Working Directory:-> " + default_W_dir);
                            default_W_dir = "";
                            default_run_time_option = "";
                        } else {
                            default_run_time_option = default_run_time_option + " -cp ";
                        }
                    } catch (Exception CO) {
                        JOptionPane.showMessageDialog(rootPane, CO,
                                "Error in Setting Java Compile OPTIONS: " + project_title,
                                JOptionPane.ERROR_MESSAGE, null);
                    }
                }
            }catch (Exception CO) {
                        JOptionPane.showMessageDialog(rootPane, CO,
                                "Error in Setting Java Compile OPTIONS: " + project_title,
                                JOptionPane.ERROR_MESSAGE, null);
                    }
        }
    }
    /*Working Directory action listener*/
    private class Menu_Config_WD implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            /* opens a input dialog to enter a path */
            try {
                String work_dir_new = JOptionPane.showInputDialog(rootPane, "Please enter the new Working Directory path ->", System.getProperty("user.dir"));
                System.out.println("the new DIR is :->" + work_dir_new);
                if ((work_dir_new.isEmpty())==false) {
                    try {
                        System.out.println("HERE-> " + default_W_dir);
                        /*checks if the class path ends with / or not*/
                        if (!work_dir_new.endsWith("/")) {
                            work_dir_new = work_dir_new + "/";
                        }
                        work_dir_new = work_dir_new;
                        /*checking if the directory exists or not*/
                        File directory = new File(work_dir_new);
                        if (directory.exists() == true) {
                            default_W_dir = work_dir_new;
                            working_dirI.setText("Working Directory: Current-> " + default_W_dir);
                        } else {
                            /*creates*/
                            boolean new_dir = new File(work_dir_new).mkdirs();
                            if (new_dir == true) {
                                default_W_dir = work_dir_new;
                                working_dirI.setText("Working Directory: Current-> " + default_W_dir);
                                System.out.println("final Working DIR selected-> " + default_W_dir);
                            } else {
                                System.out.println("\nERROR: Directory Doesnt exist and FAiled to create DIR\n");
                            }
                        }
                        /*updates the screen*/
                        getContentPane().repaint();
                    } catch (Exception CO) {
                        JOptionPane.showMessageDialog(rootPane, CO,
                                "Error in Setting Java Compile OPTIONS: " + project_title,
                                JOptionPane.ERROR_MESSAGE, null);
                    }
                }
            } catch (Exception w) {
                JOptionPane.showMessageDialog(rootPane, w,
                        "Error in Setting Java Compile OPTIONS: " + project_title,
                        JOptionPane.ERROR_MESSAGE, null);
            }
        }
    }
    /*java run time application finder*/
    private class Menu_Config_JR implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            /*gives option to choose manually or browse*/
            Object[] comp_MORB_run = {"Manually", "Browse"};
            int check;
            check = JOptionPane.showOptionDialog(option_pane, "Would you like to enter a complete path to the compiler or Browse for the application?", "Please Select one Option for Entering Compiler:",
                    JOptionPane.YES_NO_OPTION,
                    JOptionPane.QUESTION_MESSAGE, null, comp_MORB_run,
                    option_pane);
            /*checks for the options and perfroms on that*/
            try {
                if (check == 1) {
                    /*brows*/
                    JFileChooser brows = new JFileChooser(default_W_dir);
                    int val;
                    File directory;
                    String filename;
                    val = brows.showOpenDialog(brows);
                    if (val == JFileChooser.APPROVE_OPTION) {
                        /*sets the path for java run */
                        directory = brows.getCurrentDirectory();
                        filename = brows.getSelectedFile().getName();
                        default_compiled_run = directory.getAbsoluteFile() + "/" + filename;
                        System.out.println("Path and file selected:-> " + default_compiled_run);
                        java_run_timeI.setText("Java Run-Time: Current-> " + default_compiled_run);
                        getContentPane().repaint();
                    }
                } else {
                    /*manually enter the path*/
                    String path = JOptionPane.showInputDialog("Please enter full path->");
                    default_compiled_run = path;
                    java_run_timeI.setText("Java Run-Time: Current-> " + default_compiled_run);
                    getContentPane().repaint();
                    System.out.println("two selected-> " + path);
                }
            } catch (Exception JCR) {
                JOptionPane.showMessageDialog(rootPane, JCR,
                        "Error in Setting Java Compile: " + project_title,
                        JOptionPane.ERROR_MESSAGE, null);
            }
        }
    }
    /*Compiled modes Action Listener*/
    private class Compile_mode_lex implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            /*Sets lex mode true and parameter false*/
            if ((lex_mode.isSelected())==true){
            	if((param_mode.isSelected())==true){
                    param_mode.setSelected(false);
                }
                compiled_mode_lex = true;
            }        
        }
    }
    /*Sets the Compile mode to the Parameter Manager*/
    private class Compile_mode_param implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
           /*sets parameter mode to true and lex to false*/
            if ((param_mode.isSelected())==true){
                if((lex_mode.isSelected())==true){
                    lex_mode.setSelected(false);
                }
                compiled_mode_lex = false;
            }
        }
    }
    /**
     * the help action listener
     */
    private class Menu_Help_About implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            /*displays the information*/
            JOptionPane about = new JOptionPane();
            Object aboutO[] = {"Close"};
            JOptionPane.showOptionDialog(about, "Dialogc Java GUI Compiler [Lex/Yacc and Parameter Manager]\nCourse : CIS 2750\nProf. David McCaughan\nAssignment 2: "
                    + "System Tools/Visualization\nCreated on: March 7, 2015\n Last Modified: March 13, 2015\nAuthor: Dipkumar Patel\n"
                    + "Student ID: 0763246\nEmail: dipkumar@mail.uoguelph.ca\n", "About Message",
                    JOptionPane.CANCEL_OPTION,
                    JOptionPane.INFORMATION_MESSAGE, null, aboutO,
                    about);
        }
    }
    /*Help readme action listener*/
    private class Menu_Help_Help implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            /*creates frame and opens the readme and displays the information*/
            JFrame help_GUI = new JFrame("Help-> Readme");
            help_GUI.setSize(1000,1000);
            help_GUI.setDefaultCloseOperation(help_GUI.DISPOSE_ON_CLOSE);
            help_GUI.setLocationRelativeTo(null);
            help_GUI.setLayout(new BorderLayout());
            JPanel help_panel = new JPanel();
            JTextArea help_area = new JTextArea();
            help_area.setEditable(false);
            String line;
           
           try{
            JScrollPane help_scroll =  new JScrollPane(help_area);
            Scanner file_scan = new Scanner(new FileReader("README.txt"));
            /*reads file*/             
            while (file_scan.hasNext()) {
               help_area.append(file_scan.nextLine() + "\n");
             }
             /*setting for scroll and displaying the info*/
            help_scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
            help_scroll.setBorder(BorderFactory.createEtchedBorder());
            help_scroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
            help_GUI.add(help_scroll,BorderLayout.CENTER);
            help_GUI.setVisible(true);
            }catch(Exception he){
                JOptionPane.showMessageDialog(rootPane, he,
                    "Error in HELP: " + project_title,
                    JOptionPane.ERROR_MESSAGE, null);
            }
        }
    }

    /**
     * checks for the edits in the editor GUI
     */
    private class edit_listen implements DocumentListener {

        @Override
        public void insertUpdate(DocumentEvent e) {
            // TODO Auto-generated method stub
            text_modified = true;

            label_status.setText("Current Project: " + project_title
                    + " --Modified");
        }

        @Override
        public void removeUpdate(DocumentEvent e) {
            // TODO Auto-generated method stub
            if (file_new = !true) {

                label_status.setText("Current Project: " + project_title);
            }
        }

        @Override
        public void changedUpdate(DocumentEvent e) {
            // TODO Auto-generated method stub
            text_modified = true;

            label_status.setText("Current Project: " + project_title
                    + " --Modified");
        }
    }

    /**
     * Compile and Run actions Listener checks whether the config file is
     * compiled or not and then runs the compiled file.
     */
    public class Menu_Compile_R implements ActionListener {

        Dialogc run;

        public Menu_Compile_R(Dialogc main) {
            run = main;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            /*checks ifthe code is compiled or not*/
            if (compiled_code == false) {
                try {
                    /*compile code*/
                    Menu_Compile_C compile_the_code = new Menu_Compile_C(run);
                    compile_the_code.actionPerformed(null);
                    compiled_code = false;
                } catch (Exception R) {

                    JOptionPane.showMessageDialog(rootPane, R,
                            "Error in Compile RUN: " + project_title,
                            JOptionPane.ERROR_MESSAGE, null);
                }
            }
            /*if compiled is true then compile the codes*/
            if (compiled_code = !false) {
                try {
                    /*compile first and then run*/
                    System.out.println(default_compile + default_compile_option + default_W_dir+"/" + " -d " + default_W_dir+"/" + " " + default_W_dir+"/"+ gen_path);

                    Process run_process = Runtime.getRuntime().exec(default_compile + default_compile_option +default_W_dir+"/"+ " -d " + default_W_dir+"/" + " " +default_W_dir+"/"+ gen_path);
                    int exit = run_process.waitFor();
                    System.out.println("Val 1 Exit Status: " + exit);

                    if (exit == 0) {
                        int val2;
                        /*if compiled properly, run the code*/
                        System.out.println(default_compiled_run + default_run_time_option +default_W_dir +  " " + gen_path.replace(".java", ""));

                        Process run_process2 = Runtime.getRuntime().exec(default_compiled_run + default_run_time_option + default_W_dir + " " + gen_path.replace(".java", ""));
                        val2 = run_process2.waitFor();
                        System.out.println("Vale 2 Exit Status " + val2);
                    }
                } catch (Exception R) {

                    JOptionPane.showMessageDialog(rootPane, R,
                            "Error in Compile RUN: " + compile_GUI_title,
                            JOptionPane.ERROR_MESSAGE, null);
                }
                compiled_code = false;
            }
        }
    }

    /* main class for GUI */
    public static void main(String[] args) {
        Dialogc create = new Dialogc();
        create.setVisible(true);

    }
}
