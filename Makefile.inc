.PRECIOUS: %.cpp %.o

ARCH := $(shell getconf LONG_BIT)
MAKE := make
CC := clang
CPP := clang++
CFLAGS :=
CPP_FLAGS_32 := -m32 -D_SQ32
CPP_FLAGS_64 := -m64 -D_SQ64
CPP_FLAGS_OP := -O2 -fno-exceptions -fno-rtti -fno-strict-aliasing -Wall
CPP_FLAGS := $(CPP_FLAGS_$(ARCH)) $(CPP_FLAGS_OP)
LD := gcc
LDFLAGS	:=
AR := ar
ARFLAGS := rc

TOPDIR = $(dir $(lastword $(MAKEFILE_LIST)))
BINDIR = $(TOPDIR)/bin
LIBDIR = $(TOPDIR)/lib
SRCDIR = $(TOPDIR)/src

ifdef SUBDIRS
all: $(SUBDIRS:=-subdir)
clean: clean-recursive
install: install-recursive
endif

ifdef PROGRAM
PROGRAM_OBJECTS ?= $(PROGRAM_SOURCES:.cpp=.o)
all: $(PROGRAM)
clean: .clean-program

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) $(PROGRAM_CPPFLAGS) $(PROGRAM_INCLUDES) -c $< -o $@

$(PROGRAM): $(PROGRAM_OBJECTS)
	$(CPP) $(PROGRAM_OBJECTS) -o $(PROGRAM) $(PROGRAM_CFLAGS) $(PROGRAM_LDFLAGS) $(PROGRAM_LIBS)
endif

ifdef LIBRARY
LIBRARY_OBJECTS ?= $(LIBRARY_SOURCES:.cpp=.o)
all: $(LIBRARY)
clean: .clean-library
%.o: %.cpp
	$(CPP) $(CPP_FLAGS) $(LIBRARY_CPPFLAGS) $(LIBRARY_INCLUDES) -c $< -o $@
endif

%-subdir:
	$(MAKE) -C $*

%-recursive:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $*; \
	done

%.a: $(LIBRARY_OBJECTS)
	$(AR) $(ARFLAGS) $@ $?

.clean-program:
	rm -f $(PROGRAM_OBJECTS)
	rm -f $(PROGRAM)

.clean-library:
	rm -f $(LIBRARY_OBJECTS)
	rm -f $(LIBRARY)

.PHONY: all clean install $(SUBDIRS)
