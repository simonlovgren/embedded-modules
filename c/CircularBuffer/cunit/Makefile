# Flags
CC        :=  gcc
DEBUG     :=  -ggdb
WARNINGS  :=  -Wall -Werror #-Wextra	# Set all warnings to errors.
TEST      :=  -lcunit

CFLAGS    += $(DEBUG) $(WARNINGS) -std=c99

LDFLAGS   += # Libraries

# Directories
TESTDIR  := .
SRCDIR   :=  ..
OBJDIR   :=  out/obj
BINDIR   :=  out/bin

# Files
_FILES      := CircularBuffer
TESTFILE    := CircularBufferTest


## Add paths and suffixes
FILES     := $(patsubst %,$(SRCDIR)/%,$(addsuffix .c, $(_FILES)))
OBJFILES  := $(patsubst %,$(OBJDIR)/%,$(addsuffix .o, $(_FILES)))

###################################################################
# OS Detection in Makefile, taken from stackoverflow:
# http://stackoverflow.com/questions/714100/os-detecting-makefile
#
# Modded to work with target systems
###################################################################
ifeq ($(OS),Windows_NT)
		# OS specific commands
		MKDIR_P := New-Item -Type Directory -Path
else
	# Get OS
	UNAME_S := $(shell uname -s)
	# Get architecture
	UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_S),Linux)
		ifeq ($(UNAME_P),x86_64)
			CFLAGS += -D LINUX_64
		endif
		ifeq ($(UNAME_P),sparc)
			CFLAGS += -D LINUX_SPARC
		endif
		ifneq ($(filter %86,$(UNAME_P)),)
			CFLAGS += -D LINUX_32
		endif
		# OS specific commands
		MKDIR_P := mkdir -p
	endif
	ifeq ($(UNAME_S), SunOS)
		ifeq ($(UNAME_P),sparc)
			CFLAGS += -D SPARC
		endif
		ifneq ($(filter %86,$(UNAME_P)),)
			CFLAGS += -D SOLARIS_32
		endif
		# OS specific commands
		MKDIR_P := mkdir -p
	endif
	ifeq ($(UNAME_S),Darwin) # OS X
		CFLAGS += -D LINUX_64
		# OS specific commands
		MKDIR_P := mkdir -p
	endif
endif

# Text formatting for Linux & OSX
# skip on SunOS
ifeq ($(UNAME_S), SunOS)
	TEXT_RED	 :=
	TEXT_GREEN   :=
	TEXT_YELLOW  :=
	TEXT_BLUE    :=
	TEXT_BOLD    :=
	TEXT_RESET   :=
else
	TEXT_RED     := $$(tput setaf 1)
	TEXT_GREEN   := $$(tput setaf 2)
	TEXT_YELLOW  := $$(tput setaf 3)
	TEXT_BLUE    := $$(tput setaf 4)
	TEXT_BOLD    := $$(tput bold)
	TEXT_RESET   := $$(tput sgr0)
endif

# PHONY
.PHONY: all automated directories obj test clean

# default entrypoint
all automated: directories test

# automated entrypoint
automated: CFLAGS += -DAUTOMATED_TEST


# Create output directories
directories:
	@$(MKDIR_P) $(OBJDIR)
	@$(MKDIR_P) $(BINDIR)

# OBJECT COMPILATION
obj: $(OBJFILES)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	@echo "Compiling $(TEXT_BOLD)$@$(TEXT_RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(TEXT_GREEN)[OK]$(TEXT_RESET)"

# Test compilation
$(TESTFILE): $(TESTFILE).c $(OBJFILES)
	@echo "Compiling $(TEXT_BOLD)$@$(TEXT_RESET)"
	@$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^ -I $(SRCDIR) $(TEST)
	@echo "$(TEXT_GREEN)[OK]$(TEXT_RESET)"

# TEST
test: $(TESTFILE)
	@$(BINDIR)/$(TESTFILE)

# Cleaning rules
clean:
	@rm -rf $(OBJDIR)/*.o
	@find $(BINDIR) -type f -not -name '.gitignore' | xargs rm -rf