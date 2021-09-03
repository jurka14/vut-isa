clean:
	rm  objects.o objects.so

proj:
	gcc -I. `net-snmp-config --cflags` -fPIC -shared -c -o objects.o objects.c
	gcc -I. `net-snmp-config --cflags` -fPIC -shared -o objects.so objects.o
