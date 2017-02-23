# CMPSC473 - Assignment 1
# Makefile

CC = gcc
CFLAGS = -g -Wall

default: thread

thread: myscheduler.o Project1.o scheduler.o
	$(CC) $(CFLAGS) -o thread myscheduler.o Project1.o scheduler.o

myscheduler.o: myscheduler.cpp myscheduler.h
	$(CC) $(CFLAGS) -c myscheduler.cpp

Project1.o: Project1.cpp
	$(CC) $(CFLAGS) -c Project1.cpp

scheduler.o: scheduler.cpp
	$(CC) $(CFLAGS)-c scheduler.cpp

Clean:
	$(RM) thread *.o *~
