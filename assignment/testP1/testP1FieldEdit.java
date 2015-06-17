import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;
import java.util.Scanner;
import javax.swing.border.*;
import java.util.ArrayList;
import java.lang.*;

public interface testP1FieldEdit {


/*Getter methods*/


	public String getDCMemberNumber ();
	public String getDCLastName ();
	public String getDCFirstName ();
	public String getDCAddress ();
	public String getDCTotalRentals ();
	public String getDCAccount_balance ();

/*Setter methods*/


	public void setDCMemberNumber (String text);
	public void setDCLastName (String text);
	public void setDCFirstName (String text);
	public void setDCAddress (String text);
	public void setDCTotalRentals (String text);
	public void setDCAccount_balance (String text);

	public void appendToStatusArea(String message);


}