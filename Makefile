CMP = gcc
MAIN = tronGame
FUNC = gfx3
EXEC = tronGame
FLAGS = -lm -lX11

$(EXEC): $(MAIN).o $(FUNC).o
		$(CMP) $(MAIN).o $(FUNC).o $(FLAGS) -o $(EXEC) 

$(MAIN).o: $(MAIN).c $(FUNC).h
		$(CMP) -c $(MAIN).c 

$(FUNC).o: $(FUNC).c
		$(CMP) -c $(FUNC).c 

clean:
		rm *.o $(EXEC)


