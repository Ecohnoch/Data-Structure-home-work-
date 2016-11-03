src=$(wildcard *.cpp)
obj=$(patsubst %.cpp, %.o, $(src))
target=skip_list_test

$(target):$(obj)
	g++ -o $(target) $(obj)

.PHONY:clean tag
clean:
	-rm -f $(target) $(obj)
tag:
	ctags -R *
