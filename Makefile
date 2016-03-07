CC = gcc
CCFLAGS = -O2 -pipe -std=c11

SRCDIR = ./src
PROGDIR = ./prog
# $(patsubst pattern,replacement,text)
SRCS = $(shell find  $(SRCDIR) -name "*.c")
PROGR = $(patsubst $(SRCDIR)%.c, $(PROGDIR)%, $(SRCS)) 

.PHONY: all

all : $(PROGDIR) $(PROGR) 

$(PROGDIR)/% : $(SRCDIR)/%.c
	$(CC) $(CCFLAGS) -o $@ $<

$(PROGDIR):
	mkdir -p $(PROGDIR)



