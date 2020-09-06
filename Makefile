bitwisemenu : major1.o clz.o endian.o rotate.o parity.o
	gcc -o bitwisemenu major1.o clz.o endian.o rotate.o parity.o

major1.o : src/major1.c
	gcc -c src/major1.c -Wall

clz.o : src/clz.c
	gcc -c src/clz.c -Wall

endian.o : src/endian.c
	gcc -c src/endian.c -Wall

rotate.o : src/rotate.c
	gcc -c src/rotate.c -Wall

parity.o : src/parity.c
	gcc -c src/parity.c -Wall

.PHONY : clean

clean :
	rm bitwisemenu major1.o clz.o endian.o rotate.o parity.o