CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -O3
.DEFAULT_GOAL := all

# Installation directories
PREFIX = /usr/local
LIBDIR = $(PREFIX)/lib
INCLUDEDIR = $(PREFIX)/include

# Source files
SOURCES = cgi-lib.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADER = cgi-lib.h

LIBNAME = cjacobcgi
TARGET = lib$(LIBNAME).a

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install: all
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 $(TARGET) $(DESTDIR)$(LIBDIR)
	install -d $(DESTDIR)$(INCLUDEDIR)
	install -m 644 $(HEADER) $(DESTDIR)$(INCLUDEDIR)

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/$(TARGET)
	rm -f $(DESTDIR)$(INCLUDEDIR)/$(HEADER)

clean:
	rm -f $(OBJECTS) $(TARGET)
