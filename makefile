# CMPSC473 - Assignment 1
# Makefile

CC = g++
CFLAGS = -g -Wall

default: thread

thread: myscheduler.o Project1.o 
	$(CC) $(CFLAGS) -o thread myscheduler.o Project1.o

myscheduler.o: myscheduler.cpp myscheduler.h
	$(CC) $(CFLAGS) -c myscheduler.cpp

Project1.o: Project1.cpp
	$(CC) $(CFLAGS) -c Project1.cpp

clean:
	$(RM) thread *.h.gch *.o *~
