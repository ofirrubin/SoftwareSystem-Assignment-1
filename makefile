CC=gcc
AR=ar
FLAGS= -Wall -g

all: mains maindrec maindloop loops # loops isn't used by main thus we compile it seperatly.

mains: main.o recursives # Main with static library with recursive lib linked (default).
	$(CC) $(FLAGS) -o mains main.o libclassrec.a
maindrec: main.o recursived # Main with dynamic library with recursive lib linked.
	$(CC) $(FLAGS) -o maindrec main.o libclassrec.so
maindloop: main.o loopd # Main with dynamic library with loop lib linked.
	$(CC) $(FLAGS) -o maindloop main.o libclassloops.so

# Recursive numClass
recursives: basicClassification.o advancedClassificationRecursion.o # Static
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
recursived: basicClassification.o advancedClassificationRecursion.o # Dynamic
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

# Loop numClass
loops: basicClassification.o advancedClassificationLoop.o # Static
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
loopd: basicClassification.o advancedClassificationLoop.o # Dynamic
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

# Object compiling:
main.o: main.c numClass.h
	$(CC) $(FLAGS) -c main.c
basicClassification.o: basicClassification.c numClass.h
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c numClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c numClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

.PHONY: all clean

clean: # Remove any file that might created.
	rm -f *.o *.a *.so *.gch maindrec maindloop mains
