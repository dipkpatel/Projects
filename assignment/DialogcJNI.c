/*******************************************************************************************************************/
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
/**************************************************************************
******  *  ******  *  *  *    *   **    **        **      ******
*    *  *  *    *  * *   *    *   * *  * *       *  *     *    *
*    *  *  ******  **    *    *   *  *   *      *    *    *    *
*    *  *  *       **    *    *   *      *     ********   * **
*    *  *  *       * *   *    *   *      *    *        *  *  *
******  *  *       *  *  ******   *      *   *          * *   *
************************************************************************/
/*Library Declaration*/
#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "DialogcJNI.h"
#include "ParameterManager.h"

/*Global Parameter Manager*/
ParameterManager * pm = NULL;
/*
* Class:     DialogcJNI
* Method:    PM_create
* Signature: (I)I
* Function: Create a Parameter Manager Object
*/
JNIEXPORT jint JNICALL Java_DialogcJNI_PM_1create
(JNIEnv * env, jobject obj, jint param)
{
  jint tester =0;

  /*creation of the parameter manager and checking if it was successful*/
  pm = PM_create(param);

  if (pm!=NULL){
   printf("\nCreate nicely\n");
    tester = 1;
  }
  return tester;
}
/*
* Class:     DialogcJNI
* Method:    PM_destroy
* Signature: ()I
* Function: Destroy and Free Parameter Manager Object
*/

JNIEXPORT jint JNICALL Java_DialogcJNI_PM_1destroy
(JNIEnv * env, jobject obj){
  jint result=0;

  /*Destroying parameter manager and checking if it was successful*/
  if ((result = PM_destroy(pm)) ==1){
    printf("\nFreed Correctly\n");
    result =1;
  }else{
    printf("\nError in Freeing\n");
  }

  return result;
}

/*
* Class:     DialogcJNI
* Method:    PM_manage
* Signature: (Ljava/lang/String;II)I
* Function: Manages parameters in the Parameter Manager
*/
JNIEXPORT jint JNICALL Java_DialogcJNI_PM_1manage
(JNIEnv * enve, jobject obje, jstring para_name, jint ptype, jint required) {
  jint test =0,jptype = ptype,jrequired = required;
  const char * paramName;

  /*Get and converts the string from JAVA to C */
  if((paramName = (*enve)->GetStringUTFChars(enve, para_name, 0))== NULL){
    printf("\nERROR\n");
    return 0;
  }
  /*Checking if the parameter is managed, and is successful*/
  if((test =PM_manage(pm,(char*)paramName,jptype,jrequired))==1){
    printf("\nmanage worked for %s\n",(char*)paramName);
    return 1;
  }else{
    printf("\nmanage failed for %s\n",(char*)paramName);
    return 0;
  }
  /*Releasing the allocated memory back to java*/
  (*enve)->ReleaseStringUTFChars(enve,para_name,paramName);

  return 0;
}

/*
* Class:     DialogcJNI
* Method:    PM_parseFrom
* Signature: (Ljava/lang/String;C)I
* Function: Parses the file for Parameters
*/
JNIEXPORT jint JNICALL Java_DialogcJNI_PM_1parseFrom
(JNIEnv * env, jobject obj, jstring filename, jchar comment)
{
  jint testP =0;
  FILE * fp;
  const char *file_name;
  /*Retrives the filename from JAVA*/
  if((file_name = (*env)->GetStringUTFChars(env, filename, 0))== NULL){
    printf("\nERROR\n");
    return 0;
  }

  /*Trys to create a file stream from the filename and if successful, parses the file*/
  if((fp = fopen((char*)file_name,"r"))!=NULL){

    if((testP = PM_parseFrom(pm,fp,comment))==1){
      printf("\nParse worked\n");
      return 1;
    }else{
      printf("\nParse failed\n");
      return 0;
    }
  }
  /*closing the file and releasing the allocated memory back to java*/
fclose(fp);
(*env)->ReleaseStringUTFChars(env, filename, file_name);
return testP;
}

/*
* Class:     DialogcJNI
* Method:    PM_hasValue
* Signature: (Ljava/lang/String;)I
* Function: checks whether the given parameter, exists in the Parameter Managera and if it has been assigned a value.
*/
JNIEXPORT jint JNICALL Java_DialogcJNI_PM_1hasValue
(JNIEnv * env, jobject obj, jstring pname)
{
  jint testV = 0;
  const char * para_name;
  /*Retrives the STring from java*/
  if((para_name = (*env)->GetStringUTFChars(env, pname, 0))== NULL){
    printf("\nERROR\n");
    return 0;
  }

  /*Checks if the parameter has values and checks for whether it was successful or not*/
  if((testV = PM_hasValue(pm,(char*)para_name))==1){
    printf("\nHas Value worked\n");
    testV =1;
  }else{
    printf("\nHas value failed\n");
    return 0;
  }
  /*Releasing the allocated memory back to JAVA*/
  (*env)->ReleaseStringUTFChars(env, pname, para_name);

  return testV;
}


/*
 * Class:     DialogcJNI
 * Method:    PM_getValue_String
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 * Function: retrives the String value from the parameter manager for the given parameter
 */
 JNIEXPORT jstring JNICALL Java_DialogcJNI_PM_1getValue_1String
 (JNIEnv * env, jobject obj, jstring pname)
 {
  int check =0;
  const char * VString;
  char * ReValue;
  /*retrvies the parameter name from JAVA*/
  if((VString = (*env)->GetStringUTFChars(env, pname, 0))== NULL){
    printf("\nERROR\n");
    return NULL;
  }

  /*A check to see if the given parameter has been assigned a value or not*/
  if((check = PM_hasValue(pm,(char*)VString))==1){
   
    /*IF the parameter has been assigned a value, then returns the String value*/
    ReValue = PM_getValue(pm, (char*)VString).str_val;
    (*env)->ReleaseStringUTFChars(env, pname, VString);

    return (*env)->NewStringUTF(env,ReValue);

  }else{

    printf("\n The %s Does NOT have a Value\n",(char*)VString);
    (*env)->ReleaseStringUTFChars(env, pname, VString);
    return NULL;
  }

  return NULL;
}

/*
 * Class:     DialogcJNI
 * Method:    PM_getValue_Int
 * Signature: (Ljava/lang/String;)I
 * Function: Retrives the Integer Value from the Parameter Manager
 */
 JNIEXPORT jint JNICALL Java_DialogcJNI_PM_1getValue_1Int
 (JNIEnv * env, jobject obj, jstring pname)
 {
  int check_int;
  const char * IString;
  jint ReValue = -1;
    /*Retrives the parameter name from Java*/
  if((IString = (*env)->GetStringUTFChars(env, pname, 0))== NULL){
    printf("\nERROR\n");
    return ReValue;
  }

  /*Checks for whether the given parameter has been assigned a value */
  if((check_int = PM_hasValue(pm,(char*)IString))==1){

    /*retrives the value and returns the integer value*/
    ReValue = PM_getValue(pm, (char*)IString).int_val;
    (*env)->ReleaseStringUTFChars(env, pname, IString);

    return ReValue;

  }else{

    printf("\n The %s Does NOT have a Value\n",(char*)IString);
    (*env)->ReleaseStringUTFChars(env, pname, IString);
    return ReValue;
  }

  return ReValue;
}

/*
 * Class:     DialogcJNI
 * Method:    PM_getValue_Float
 * Signature: (Ljava/lang/String;)F
 * Function:  Retrives the Float Value from the Parameter Manager
 */
 JNIEXPORT jfloat JNICALL Java_DialogcJNI_PM_1getValue_1Float
 (JNIEnv * env, jobject obj, jstring pname)
 { 
  jfloat ReValue = -1.0;
  const char * FString;
  int check_real;
   /*Retrives the parameter name from Java*/
  if((FString = (*env)->GetStringUTFChars(env, pname, 0))== NULL){
    printf("\nERROR\n");
    return ReValue;
  }
  
  /*Checks for whether the given parameter has been assigned a value */
  if((check_real = PM_hasValue(pm,(char*)FString))==1){

  /*retrives the value and returns the float value*/
    ReValue = PM_getValue(pm, (char*)FString).real_val;
    (*env)->ReleaseStringUTFChars(env, pname, FString);

    return ReValue;

  }else{

    printf("\n The %s Does NOT have a Value\n",(char*)FString);
    (*env)->ReleaseStringUTFChars(env, pname, FString);
    return ReValue;
  }

  return ReValue;
}

/*
 * Class:     DialogcJNI
 * Method:    PM_getValue_Boolean
 * Signature: (Ljava/lang/String;)Z
 * Function: Retrives the boolean Value from the Parameter Manager
 */
 JNIEXPORT jboolean JNICALL Java_DialogcJNI_PM_1getValue_1Boolean
 (JNIEnv * env, jobject obj, jstring pname)
 {
  jboolean ReValue = false;
  const char * BString;
  int check_bool;
  
  /*Retrives the parameter name from Java*/
  if((BString = (*env)->GetStringUTFChars(env, pname, 0))== NULL){
    printf("\nERROR\n");
    return ReValue;
  }

   /*Checks for whether the given parameter has been assigned a value */
  if((check_bool = PM_hasValue(pm,(char*)BString))==1){

    /*retrives the value and returns the float value*/
    ReValue = PM_getValue(pm, (char*)BString).bool_val;
    (*env)->ReleaseStringUTFChars(env, pname, BString);

    return ReValue;

  }else{

    printf("\n The %s Does NOT have a Value\n",(char*)BString);
    (*env)->ReleaseStringUTFChars(env, pname, BString);
    return ReValue;
  }

  return ReValue;
}
/*
 * Class:     DialogcJNI
 * Method:    PM_getValue_List_string
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 * Function: Retrives the List Value from the Parameter Manager for STring
 */
 JNIEXPORT jstring JNICALL Java_DialogcJNI_PM_1getValue_1List_1string
 (JNIEnv * env, jobject obj, jstring pname)
 {
  int check_list =0;
  const char * LString;
  char * ReValue;
  /*Checks for whether the given parameter has been assigned a value */
  if((LString = (*env)->GetStringUTFChars(env, pname, 0))== NULL){
    printf("\nERROR\n");
    return NULL;
  }

  /*Checks for whether the given parameter has been assigned a value */
  if(( check_list = PM_hasValue(pm,(char*)LString))==1){

  /*retrives the value and returns the list  value->>String*/
    ReValue = PL_next(PM_getValue(pm, (char*)LString).list_val);
    (*env)->ReleaseStringUTFChars(env, pname, LString);

    return (*env)->NewStringUTF(env,ReValue);

  }else{

    printf("\n The %s Does NOT have a Value, Empty List or no more Value in List\n",(char*)LString);
    (*env)->ReleaseStringUTFChars(env, pname, LString);
    return NULL;
  }

  return NULL;
}