.PHONY: clean all loops loopd recursives recursived

all: libclassloops.a libclassloops.so libclassrec.a libclassrec.so mains maindloop maindrec

loops: libclassloops.a

loopd: libclassloops.so

recursives: libclassrec.a

recursived: libclassrec.so

basicClassifigication.o: basicClassification.c NumClass.h
	gcc -g -Wall -fPIC -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -g -Wall -fPIC -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -g -Wall -fPIC -c advancedClassificationRecursion.c

main.o: main.c NumClass.h
	gcc -g -Wall -c main.c

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o 

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

mains: main.o libclassrec.a
	gcc -g -Wall -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	gcc -g -Wall -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	gcc -g -Wall -o maindrec main.o ./libclassrec.so -lm

clean:
	rm -f *.o *.a *.so mains maindloop maindrec