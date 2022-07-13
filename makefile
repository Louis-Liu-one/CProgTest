
CProgTest: CProgTest.o base.o magic-method.o
	gcc CProgTest.o base.o magic-method.o -o CProgTest

CProgTest.o: CProgTest.c totaller.h
	gcc -c CProgTest.c

base.o: base.c totaller.h
	gcc -c base.c

magic-method.o: magic-method.c totaller.h
	gcc -c magic-method.c

clean:
	rm *.o
