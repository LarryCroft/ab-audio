BUILDDIR := build

CXXFLAGS += -std=c++0x -Wall -Werror
LDLIBS += -lpulse-simple

CXXFLAGS += -g -O0

SRC := $(wildcard src/*.cc)
OBJ := $(SRC:src/%.cc=$(BUILDDIR)/%.o)

BIN := $(BUILDDIR)/ab

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $@ $+ $(LDLIBS)

$(BUILDDIR)/%.o: src/%.cc
	mkdir -p $(dir $@)
	$(CXX) -o $@ -c $(CXXFLAGS) $<

clean:
	rm -rf $(BUILDDIR)
