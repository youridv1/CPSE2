#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := ball.cpp

# header files in this project
HEADERS += ball.hpp
HEADERS += drawable.hpp
HEADERS += wall.hpp
HEADERS += action.hpp


# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../../v2cpse2-examples/
include $(RELATIVE)Makefile.native

schoon:
	make clean
	rm -f main
