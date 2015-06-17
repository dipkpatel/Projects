import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;
import java.util.Scanner;
import javax.swing.border.*;
import java.util.ArrayList;
import java.lang.*;

public class testP1 extends JFrame implements testP1FieldEdit {


	/*GUI STuff*/

 	JPanel buttons_GUI = new JPanel();
	 JPanel compile_panel_text = new JPanel();
	 JPanel compile_panel = new JPanel();
	 JPanel split = new JPanel();
	 JTextArea message_GUI = new JTextArea();
	 JScrollPane message_GUI_scroll = new JScrollPane(message_GUI);

	 /*Layout stuff*/

	 Box left = Box.createVerticalBox();
 	 Box right = Box.createVerticalBox();
 	 Box horizontal = Box.createHorizontalBox();
 	 TitledBorder status_GUI = new TitledBorder(BorderFactory.createEmptyBorder());


	JTextField text_field0 = new JTextField();

	JLabel field_label0 = new JLabel();


	JTextField text_field1 = new JTextField();

	JLabel field_label1 = new JLabel();


	JTextField text_field2 = new JTextField();

	JLabel field_label2 = new JLabel();


	JTextField text_field3 = new JTextField();

	JLabel field_label3 = new JLabel();


	JTextField text_field4 = new JTextField();

	JLabel field_label4 = new JLabel();


	JTextField text_field5 = new JTextField();

	JLabel field_label5 = new JLabel();

	JButton button0 =  new JButton("Add");
	JButton button1 =  new JButton("Update");
	JButton button2 =  new JButton("Delete");
	JButton button3 =  new JButton("Query");
	JButton button4 =  new JButton("Print");

	public testP1 (){

	super();

	split.setLayout(new BorderLayout());
 	this.setTitle("testP1");
 	 this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
 	 this.setSize(600,600);
 	 this.setLocationRelativeTo(null);
 	 this.setLayout(new BorderLayout());
 	 message_GUI.setEditable(false);
 	 status_GUI.setTitle("----Status----");
 	 message_GUI_scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
 	 message_GUI_scroll.setBorder(BorderFactory.createEtchedBorder());
 	 message_GUI_scroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
 	 message_GUI_scroll.setBorder(status_GUI);
 	 buttons_GUI.setLayout(new BoxLayout(buttons_GUI,BoxLayout.LINE_AXIS));


	field_label0.setBorder(BorderFactory.createEtchedBorder());
	field_label0.setFont(new Font("Times", Font.BOLD, 16));
	field_label0.setSize(text_field0.getPreferredSize());
	field_label0.setText("MemberNumber");
	left.add(field_label0);
	 right.add(text_field0);


	field_label1.setBorder(BorderFactory.createEtchedBorder());
	field_label1.setFont(new Font("Times", Font.BOLD, 16));
	field_label1.setSize(text_field1.getPreferredSize());
	field_label1.setText("LastName");
	left.add(field_label1);
	 right.add(text_field1);


	field_label2.setBorder(BorderFactory.createEtchedBorder());
	field_label2.setFont(new Font("Times", Font.BOLD, 16));
	field_label2.setSize(text_field2.getPreferredSize());
	field_label2.setText("FirstName");
	left.add(field_label2);
	 right.add(text_field2);


	field_label3.setBorder(BorderFactory.createEtchedBorder());
	field_label3.setFont(new Font("Times", Font.BOLD, 16));
	field_label3.setSize(text_field3.getPreferredSize());
	field_label3.setText("Address");
	left.add(field_label3);
	 right.add(text_field3);


	field_label4.setBorder(BorderFactory.createEtchedBorder());
	field_label4.setFont(new Font("Times", Font.BOLD, 16));
	field_label4.setSize(text_field4.getPreferredSize());
	field_label4.setText("TotalRentals");
	left.add(field_label4);
	 right.add(text_field4);


	field_label5.setBorder(BorderFactory.createEtchedBorder());
	field_label5.setFont(new Font("Times", Font.BOLD, 16));
	field_label5.setSize(text_field5.getPreferredSize());
	field_label5.setText("Account_balance");
	left.add(field_label5);
	 right.add(text_field5);

	 button0.addActionListener(new A2Listener_P1(this) );
	buttons_GUI.add(button0);

	 button1.addActionListener(new A2Listener_P1(this) );
	buttons_GUI.add(button1);

	 button2.addActionListener(new A2Listener_P1(this) );
	buttons_GUI.add(button2);

	 button3.addActionListener(new A2Listener_P1(this) );
	buttons_GUI.add(button3);

	 button4.addActionListener(new A2Listener_P1(this) );
	buttons_GUI.add(button4);
	horizontal.add(left);
	horizontal.add(right);
	add(horizontal,BorderLayout.NORTH);
	split.add(buttons_GUI,BorderLayout.NORTH);
	split.add(message_GUI_scroll,BorderLayout.CENTER);
	add(split,BorderLayout.CENTER);
	}

	public void setDCMemberNumber (String text){


		 text_field0.setText(text);

	}

	public void setDCLastName (String text){


		 text_field1.setText(text);

	}

	public void setDCFirstName (String text){


		 text_field2.setText(text);

	}

	public void setDCAddress (String text){


		 text_field3.setText(text);

	}

	public void setDCTotalRentals (String text){


		 text_field4.setText(text);

	}

	public void setDCAccount_balance (String text){


		 text_field5.setText(text);

	}

	public String getDCMemberNumber (){


		String MemberNumber = null;
		int int_MemberNumber = 0;
		float float_MemberNumber = 0.0f;

		if((text_field0.getText())!= null && (text_field0.getText().isEmpty())!=true){

			try{

			int_MemberNumber = Integer.parseInt(text_field0.getText());
		}catch(Exception ef){
			throw new IllegalFieldValueException(text_field0.getText());
		}

			return (text_field0.getText());

			}

		return null;

	}

	public String getDCLastName (){


		String LastName = null;
		int int_LastName = 0;
		float float_LastName = 0.0f;

		if ((text_field1.getText())!= null && (text_field1.getText().isEmpty())!=true){
			 LastName = text_field1.getText();

		return (text_field1.getText() );

		}

		return null;

	}

	public String getDCFirstName (){


		String FirstName = null;
		int int_FirstName = 0;
		float float_FirstName = 0.0f;

		if ((text_field2.getText())!= null && (text_field2.getText().isEmpty())!=true){
			 FirstName = text_field2.getText();

		return (text_field2.getText() );

		}

		return null;

	}

	public String getDCAddress (){


		String Address = null;
		int int_Address = 0;
		float float_Address = 0.0f;

		if ((text_field3.getText())!= null && (text_field3.getText().isEmpty())!=true){
			 Address = text_field3.getText();

		return (text_field3.getText() );

		}

		return null;

	}

	public String getDCTotalRentals (){


		String TotalRentals = null;
		int int_TotalRentals = 0;
		float float_TotalRentals = 0.0f;

		if((text_field4.getText())!= null && (text_field4.getText().isEmpty())!=true){

			try{

			int_TotalRentals = Integer.parseInt(text_field4.getText());
		}catch(Exception ef){
			throw new IllegalFieldValueException(text_field4.getText());
		}

			return (text_field4.getText());

			}

		return null;

	}

	public String getDCAccount_balance (){


		String Account_balance = null;
		int int_Account_balance = 0;
		float float_Account_balance = 0.0f;

		if((text_field5.getText())!= null && (text_field5.getText().isEmpty())!=true){

			try{

			float_Account_balance =  Float.parseFloat(text_field5.getText());
		}catch(Exception ef){
			throw new IllegalFieldValueException(text_field5.getText());
		}

			return Float.toString(float_Account_balance);

			}

		return null;

	}

	public void appendToStatusArea(String message){

		 message_GUI.append(message+" \n ");

	}


	public static void main(String[] args) {

		testP1 testP1instance = new testP1();
		testP1instance.setVisible(true);


	}

}