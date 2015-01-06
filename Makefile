myprog: mobydick.c
	gcc -Wall mobydick.c main.c -o mobydick

run:
	@./mobydick < moby-dic.txt

clean:
	rm mobydick

