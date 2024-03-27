FILE = min_template

build: $(FILE).s
	# next line compiles with all warnings on, debug info, and links math lib
	gcc -Wall -g $(FILE).s -o $(FILE) -lm -fno-pie -no-pie


.PHONY: db

db:
	gdb -tui $(FILE)

run:
	./$(FILE)