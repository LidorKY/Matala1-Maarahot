all: libclassloops.a libclassrec.a libclassloops.so libclassrec.so maindloop maindrec mains

loops: advancedClassificationLoop.o basicClassification.o
	ar rcu libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: advancedClassificationRecursion.o basicClassification.o
	ar rcu libclassrec.a advancedClassificationRecursion.o basicClassification.o

recursived: advancedClassificationRecursion.o basicClassification.o
	ar rcu libclassrec.so advancedClassificationRecursion.o basicClassification.o

loopd: advancedClassificationLoop.o basicClassification.o
	ar rcu libclassloops.so advancedClassificationLoop.o basicClassification.o

mains: main.o libclassrec.a
	gcc -Wall -g -o mains main.o libclassrec.a

maindloop: main.o advancedClassificationLoop.o
	gcc -Wall -g -o maindloop main.o advancedClassificationLoop.o ./libclassloops.so

maindrec: main.o advancedClassificationRecursion.o
	gcc -Wall -g -o maindrec main.o advancedClassificationRecursion.o ./libclassrec.so

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassrec.a: 	basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

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