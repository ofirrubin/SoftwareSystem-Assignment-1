CC=gcc
AR=ar
FLAGS= -Wall -g


all: mains maindrec maindloop  recursives recursived loopd loops # loops isn't used by main thus we compile it seperatly.

# Make files commands
recursives: libclassrec.a
recursived: libclassrec.so
loops: libclassloops.a
loopd: libclassloops.so

mains: main.o libclassrec.a # Main with static library with recursive lib linked (default).
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm
maindrec: main.o libclassrec.so # Main with dynamic library with recursive lib linked.
	$(CC) $(FLAGS) -o maindrec main.o libclassrec.so -lm
maindloop: main.o libclassloops.so # Main with dynamic library with loop lib linked.
	$(CC) $(FLAGS) -o maindloop main.o libclassloops.so -lm


# Recursive numClass
libclassrec.a: basicClassification.o advancedClassificationRecursion.o # Static
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
libclassrec.so: basicClassification.o advancedClassificationRecursion.o # Dynamic
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

# Loop numClass
libclassloops.a: basicClassification.o advancedClassificationLoop.o # Static
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
libclassloops.so: basicClassification.o advancedClassificationLoop.o # Dynamic
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

# Object compiling:
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

.PHONY: clean all

clean: # Remove any file that might created.
	rm -f *.o *.a *.so *.gch maindrec maindloop mains
