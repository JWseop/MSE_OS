CC=gcc
TARGET=oshw1_32184140
OBJS= oshw1_32184140.o func.o
CFLAGS=-Wall -g
LDFLAGS=-lc

all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm -f $(OBJS) $(TARGET)
