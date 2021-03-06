SOURCES = $(wildcard *.cpp)
OBJDIR = objs
OBJECTS = $(addprefix $(OBJDIR)/,$(SOURCES:%.cpp=%.o))
INCLUDE = ../src
LD_LIBRARY = ../src
LIB = -lplacement3d
CXXFLAGS = -Wall -std=c++11 -O2

ifeq ($(shell uname), Linux)
DEL = rm -f
DELDIR = rm -rf
MKDIR = mkdir
DLL = $(LD_LIBRARY)/libplacement3d.so
export LD_LIBRARY_PATH := $(LD_LIBRARY_PATH):$(LD_LIBRARY)
CXXFLAGS += -DLinux
else
DEL = del
DELDIR = rmdir /s /q
MKDIR = mkdir
DLL = $(LD_LIBRARY)/placement3d.dll
export PATH := $(PATH);$(LD_LIBRARY)
endif

all: $(OBJDIR) $(DLL) main debug boxesmaker test

$(DLL):
	cd $(LD_LIBRARY) && make

main: $(OBJDIR)/main.o
	@echo "Now Generating $< ..."
	g++ -I$(INCLUDE) -L$(LD_LIBRARY) $^ -o $@ $(CXXFLAGS) $(LIB)

debug: $(OBJDIR)/debug.o
	@echo "Now Generating $< ..."
	g++ -I$(INCLUDE) -L$(LD_LIBRARY) $^ -o $@ $(CXXFLAGS) $(LIB)

test: $(OBJDIR)/test.o
	@echo "Now Generating $< ..."
	g++ -I$(INCLUDE) -L$(LD_LIBRARY) $^ -o $@ $(CXXFLAGS) $(LIB)

boxesmaker: $(OBJDIR)/boxesmaker.o
	@echo "Now Generating $< ..."
	g++ -I$(INCLUDE) -L$(LD_LIBRARY) $^ -o $@ $(CXXFLAGS) $(LIB)

run-debug:
	./debug

run-test:
	./test

run-boxesmaker:
	./boxesmaker


$(OBJDIR):
	$(MKDIR) $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	@echo "Now Compiling $< ..."
	g++ -I$(INCLUDE) -c $< -o $@ $(CXXFLAGS)

clean:
	$(DEL) main demo debug test *.exe
	$(DELDIR) $(OBJDIR)

explain:
	@echo "User Sources: $(SOURCES)"
	@echo "User Objects: $(OBJECTS)"

run:
	./main
