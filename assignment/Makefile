CC = gcc

JAV = javac

JAVH = javah

CFLAGS = -c -Wall -fPIC

INCLD = -I/usr/lib/jvm/java-1.6.0-openjdk/include -I/usr/lib/jvm/java-1.6.0-openjdk/include/linux

MACINCLD = -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers

MACINCLD2 = -I/usr/bin/java/include -I/usr/bin/java/include/linux

EXPORT = export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.

all: yadc JNI

JNI: Class DialogcJNI.h JNIpm.dylib
	export LD_LIBRARY_PATH=. && java Dialogc -v

Class: DialogcJNI.java Dialogc.java Menu_Compile_C.java Menu_File_New.java Menu_File_Save.java Menu_File_SaveAs.java code_generator.java  
	$(JAV) -g DialogcJNI.java Dialogc.java Menu_Compile_C.java Menu_File_New.java Menu_File_Save.java Menu_File_SaveAs.java code_generator.java  

DialogcJNI.h: DialogcJNI.class
	$(JAVH) DialogcJNI

DialogcJNI.o: DialogcJNI.c
	$(CC) $(CFLAGS) DialogcJNI.c  $(MACINCLD) 

JNIpm.dylib: DialogcJNI.o ParameterManager.o
	$(CC) -shared $(MACINCLD2) -o libJNIpm.dylib DialogcJNI.o ParameterManager.o


ParameterManager: ParameterManager.o 
	ar rcc libpm.a ParameterManager.o

ParameterManager.o: ParameterManager.c ParameterManager.h
	$(CC) $(CFLAGS) ParameterManager.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) -c -Wall linkedlist.c

lex.yy.c: scan_lex.l
	lex scan_lex.l

y.tab.h: scan_yac.y 
	yacc -d -y scan_yac.y

y.tab.c: scan_yac.y 
	yacc -d -y scan_yac.y

yadc: linkedlist.o y.tab.c y.tab.h lex.yy.c 
	gcc lex.yy.c y.tab.c linkedlist.o -o yadc



clean:
	rm -f *o *so *.class *.dylib libpm.a *.log yadc tester