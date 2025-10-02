exec.out : game.o wordholder.o main.o
	g++ -g main.o game.o wordholder.o -o exec.out

wordholder.o: wordholder.cpp wordholder.h
	g++ -g -c wordholder.cpp -o wordholder.o

game.o: game.cpp game.h
	g++ -g -c game.cpp -o game.o

main.o: main.cpp game.h wordholder.h
	g++ -g -c main.cpp -o main.o

main2.o: main2.cpp wordholder.h algo1.h
	g++ -g -c main2.cpp -o main2.o

algo1.o: algo1.cpp algo1.h
	g++ -g -c algo1.cpp -o algo1.o

exec2.out: main2.o algo1.o wordholder.o
	g++ -g main2.o algo1.o wordholder.o -o exec2.out

main3.o: main3.cpp algo1.h game.h
	g++ -g -c main3.cpp -o main3.o

exec3.out: main3.o algo1.o game.o wordholder.o
	g++ -g main3.o algo1.o wordholder.o game.o -o exec3.out

clean:
	rm -f *.o exec.out exec2.out
