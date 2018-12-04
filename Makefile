CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		MakeIcons.o

LIBS =

TARGET =	MakeIcons

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
