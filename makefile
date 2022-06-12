
CProgTest: CProgTest.o base.o
	gcc -g CProgTest.o base.o -o CProgTest

CProgTest.o: CProgTest.c totaller.h
	gcc -g -c CProgTest.c

base.o: base.c totaller.h
	gcc -g -c base.c

clean:
	rm *.o
