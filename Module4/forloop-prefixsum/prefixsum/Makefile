CFLAGS=-O3 -std=c11 -fPIC -g
CXXFLAGS=-O3 -std=c++17 -fPIC -g
ARCHIVES=../libgen.a
LD=g++


all: prefixsum

prefixsum: prefixsum.o
	$(LD) $(LDFLAGS) prefixsum.o $(ARCHIVES) -o prefixsum

test: prefixsum
	./test.sh

bench: prefixsum
	./queue.sh

plot: 
	./plot.sh

clean:
	-rm *.o
	-rm prefixsum

distclean:
	-rm *.sh.*

.PHONY: prefixsum 
