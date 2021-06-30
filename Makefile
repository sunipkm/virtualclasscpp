CXX=g++

CPPOBJS=myclass.o \
		main.o

all: test.out

valgrind: test.out
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose \
	--log-file=valgrind-out.txt \
	./test.out

test.out: $(CPPOBJS)
	$(CXX) $(CPPOBJS) -o $@

%.o: %.cpp
	$(CXX) -o $@ -c $<

.PHONY: clean

clean:
	rm -vf $(CPPOBJS)
	rm -vf *.out
	rm -vf valgrind-out.txt