# Cross-platform Makefile
#
# Targets
#   all      – build in default mode (same as ‘release’ unless overridden)
#   debug    – build with debug symbols and no optimisation
#   release  – build with optimisation
#   clean    – remove all generated artefacts
#   help     – print this help
#
# Usage examples
#   make              # release build with auto-detected compiler
#   make debug        # debug build
#   CXX=clang++ make  # force a particular compiler
#   make clean
#

# project layout
SRC_DIR  := src
SRCS     := $(SRC_DIR)/Calculator.cpp $(SRC_DIR)/Operation.cpp

# basic OS detection
UNAME_S  := $(shell uname -s 2>/dev/null)
ifeq ($(OS),Windows_NT)                 # native Windows (cmd / powershell)
    EXE_EXT := .exe
else                                    # POSIX (macOS / Linux / WSL / MSYS / etc.)
    EXE_EXT :=
endif

BIN := Calculator$(EXE_EXT)

# pick a compiler if the user did not provide one
ifndef CXX
    CXX := $(firstword                                                   \
            $(shell command -v g++      2>/dev/null)                     \
            $(shell command -v clang++  2>/dev/null)                     \
            $(if $(filter Windows_NT,$(OS)),                             \
                  $(shell where cl 2>NUL | head -n 1)))
endif

# compiler-specific flags and patterns
ifeq ($(notdir $(CXX)),cl)             # Microsoft MSVC
    COMPILER  := MSVC
    OBJ_EXT   := obj
    CXXFLAGS += /EHsc /std:c++17 /nologo /I$(SRC_DIR) /W4
    LDFLAGS  :=
    COMPILE   = $(CXX) $(CXXFLAGS) /c $< /Fo$@
    LINK      = $(CXX) $(CXXFLAGS) $^ /Fe$@
else                                    # g++ / clang++
    COMPILER  := GNU/LLVM
    OBJ_EXT   := o
    CXXFLAGS += -std=c++17 -Wall -Wextra -I$(SRC_DIR)
    ifeq ($(UNAME_S),Darwin)
        CXXFLAGS += -stdlib=libc++
    endif
    LDFLAGS  :=
    COMPILE   = $(CXX) $(CXXFLAGS) -c $< -o $@
    LINK      = $(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
endif

OBJS := $(SRCS:.cpp=.$(OBJ_EXT))

# build modes
DEBUG_FLAGS   = -g -O0
RELEASE_FLAGS = -O3 -DNDEBUG

# Default to release unless the user explicitly asked for ‘debug’
BUILD ?= release
ifeq ($(BUILD),debug)
    CXXFLAGS += $(DEBUG_FLAGS)
else
    CXXFLAGS += $(RELEASE_FLAGS)
endif

# primary rules
.PHONY: all debug release clean help

all: $(BIN)

debug:
	$(MAKE) BUILD=debug

release:
	$(MAKE) BUILD=release

$(BIN): $(OBJS)
	@echo "Linking $(BIN) with $(COMPILER)…"
	@$(LINK)

# Pattern rule for object files
$(SRC_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.cpp
	@echo "Compiling $< with $(COMPILER)…"
	@$(COMPILE)

clean:
ifeq ($(COMPILER),MSVC)
	-del /Q $(subst /,\,$(OBJS)) $(subst /,\,$(BIN)) 2>NUL || exit 0
else
	$(RM) -f $(OBJS) $(BIN)
endif

help:
	@grep -E '^[^#[:space:]].*?:.*?## .*$$' -n Makefile | \
		sed 's/^[^:]*:\([^#]*\)##[[:space:]]*//g' | \
		column -t -s ':' | \
		sed -e 's/^/ /'

# Self-documentation (targets with comments picked up by ‘help’)
all      : ## Build (default target)
debug    : ## Build with debug symbols (BUILD=debug)
release  : ## Build with optimisation  (BUILD=release)
clean    : ## Remove all generated files
help     : ## Show this help message
