all:
	gcc -o extractCGAfont extract.c
	gcc -o createCGAfont create.c

dos:
	tcc -D__DOS -eEXTRACT.EXE extract.c
	tcc -D__DOS -eCREATE.EXE create.c

clean:
	rm -f createCGAfont extractCGAfont

cleandos:
	del create.exe 
	del extract.exe

