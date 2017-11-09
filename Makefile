CC=gcc
COFLAGS=
CWFLAGS=
CIFLAGS=
CMFLAGS=
TARGET=beautify
OBJDIR=build
CFLAGS= $(CWFLAGS) $(COFLAGS) $(CIFLAGS) $(CMFLAGS)
objects=$(addprefix $(OBJDIR)/, beautify.o symbol.o)

$(TARGET): $(objects)
	$(CC) $(CFLAGS) -o beautify $(objects)

$(OBJDIR)/%.o: %.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

beautify.c:	beautify.l
	flex -o beautify.c beautify.l

clean:
	$(RM) -r $(objects) $(TARGET) $(OBJDIR)
