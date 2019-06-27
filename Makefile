CFLAGS = -g
LDLIBS = -ldb

sources = setNodeExample.c setNode.c getNode.c listNodes.c delNode.c getNodeExample.c
headers = networkNode.h
programs = $(basename $(sources))

.PHONY: all
all: $(programs)

%: %.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

$(programs): $(headers)

.PHONY: clean
clean:
	$(RM) $(programs) *.db
