
# CXX is the name of the compiler we are using (clang++)

CXX = clang++

# CXXFLAGS are the flags we will be passing each compile

CXXFLAGS = -g -std=c++11 -Wall -Wextra -pedantic 

# TARGETS is the list of all programs created when we do "make all"
#   (and which should be deleted when we do "make clean")

TARGETS = monopoly

###############################################################################
# "PHONY" (BUT USEFUL) MAKEFILE TARGETS
###############################################################################


# "make all" brings all programs up-to-date (recursively)
#     and then runs no commands.

all:	$(TARGETS)

# "make clean" brings nothing up to date, but always
#      runs commands to delete all created files

clean:
	rm -f $(TARGETS)
	rm -rf *.o
###############################################################################
# CREATING PROGRAMS
###############################################################################

# "make stringhash-test" brings the relevant .o files up-to-date (recursively)
#      and then links them.

# In a command run by the makefile, $^ stands for the things the target
#      depends on (in this case, the list stringhash-test.o stringhash.o")
#      This is useful so that we don't have to duplicate this list
#      both in the dependency list and in the linking command, and we
#      don't have to define a STRINGHASH_TEST_OBJS variable that is
#      used only for these two lines.

monopoly:	monopoly.o
	$(CXX) $(CXXFLAGS) -o monopoly $^


# "make hashset-cow-test" brings the relevant .o files up-to-date (recursively)
#      and then links them.


# Rules for your own test program would go here (you don't have to
#      add a comment that says what it does, if it follows the
#      standard pattern.)

###############################################################################
# GENERATING OBJECT FILES
###############################################################################

# The .o files depend on the corresponding .cpp file and the .hpp
#      files that C++ code includes.
#      In each case, the command to generate the .o file uses
#      our C++ compiler to compile the .cpp file, with the -c flag.

monopoly.o: monopoly.hpp monopoly.cpp
	$(CXX) $(CXXFLAGS) -c monopoly.cpp

# When/if you need more .o files, their dependencies and the
#    compilation commands would go here.