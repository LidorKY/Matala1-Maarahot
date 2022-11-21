all: libclassloops.a libclassrec.a libclassloops.so libclassrec.so maindloop maindrec mains

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so	

loopd: libclassloops.so

mains: main.o libclassrec.a
	gcc -Wall -g -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	gcc -Wall -g main.o -L. -lclassloops -o maindloop

maindrec: main.o libclassrec.so
	gcc -Wall -g main.o -L. -lclassrec -o maindrec 

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a

libclassrec.a: 	basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
	ranlib libclassrec.a

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -Wall -g -c -fPIC basicClassification.c advancedClassificationRecursion.c
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o


libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -Wall -g -c -fPIC basicClassification.c advancedClassificationLoop.c
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o


advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -Wall -g -c advancedClassificationLoop.c NumClass.h

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -Wall -g -c advancedClassificationRecursion.c

basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -g -c basicClassification.c

main.o: main.c NumClass.h
	gcc -Wall -g -c main.c

clean:
	rm -f *.o *.a *.so 