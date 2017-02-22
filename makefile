SOURCE= scheduler.h myscheduler.cpp Project1.cpp

MYPROGRAM=project1

CC=g++

#------------------------------------------------------------------------------



all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) $(SOURCE) -o$(MYPROGRAM) 

clean:

	rm -f $(MYPROGRAM)

