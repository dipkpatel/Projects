/*******************************************************************************************************************/
/*  Dialogc Java Native Interface Wrapper Java file
 *  Course : CIS 2750 
 *  Prof. David McCaughan
 *  Assignment 2: Graphical User Interfaces
 *  Created on: Jan 26, 2015
 *  Last Modified: Feb 13, 2015
 *  Author: Dipkumar Patel
 *  Student ID: 0763246
 *  Email: dipkumar@mail.uoguelph.ca
 */
/**************************************************************************
******  *  ******  *  *  *    *   **    **        **      ******
*    *  *  *    *  * *   *    *   * *  * *       *  *     *    *
*    *  *  ******  **    *    *   *  *   *      *    *    *    *
*    *  *  *       **    *    *   *      *     ********   * **
*    *  *  *       * *   *    *   *      *    *        *  *  *
******  *  *       *  *  ******   *      *   *          * *   *
************************************************************************/

import java.io.*;

/**
 * Dialogc JNI Wrapper Class 
 * Declaring Native functions names to be used for .C file
 * Dip-Patel
 */
public class DialogcJNI {
	
	static {System.loadLibrary("JNIpm");}
	public native int PM_create(int size);
	public native int PM_destroy();
	public native int PM_manage(String pname, int ptype, int required);
	public native int PM_parseFrom(String filename, char comment);
	public native int PM_hasValue(String pname);
	public native String PM_getValue_String(String pname);
	public native int PM_getValue_Int(String pname);
	public native float PM_getValue_Float(String pname);
	public native boolean PM_getValue_Boolean(String pname);
	public native String PM_getValue_List_string(String pname);
	
}
