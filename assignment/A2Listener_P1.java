import java.awt.event.*;

public class A2Listener_P1 implements ActionListener
{

	testP1FieldEdit d;

	public A2Listener_P1(testP1FieldEdit d)
	{
		this.d = d;
	}
	
	public void actionPerformed(ActionEvent e)
	{
		try
		{
			

			String name = d.getDCLastName();
			d.appendToStatusArea(name);
			int a2 = Integer.parseInt(d.getDCMemberNumber());
			d.appendToStatusArea(String.valueOf(a2));
		}
    
		catch(Exception tr)
		{
			d.appendToStatusArea("ERROR");
		}

	}

}
