########################################################################
## Author: Sumanish <sumanish.cse.jgec@gmail.com>                     ##
## Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                ##
##                                                                    ##  
## This source code can be downloaded, use, modify, distribute        ##
## freely with this headed intact. Please don't delete this header.   ##
######################################################################## 

CC=g++
IPATHS=-I. -I../../Boost_1.68/boost_1_68_0
CFLAGS=-g -w
LPATHS=-L../../Boost_1.68/boost_1_68_0
LFLAGS=
DEPS=tokens.hpp grammar.hpp langreader.hpp functors.hpp 
OBJS=langreader.o main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(IPATHS) 

LangParse: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LPATHS) $(LFLAGS)

clean:
	rm -f *.o *.log LangParse 
