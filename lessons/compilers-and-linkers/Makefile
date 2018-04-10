.phony: archives objects shared help

help:
	@echo "Try One of the Following"
	@echo "  make archives  #statically build using archives/static-libraries"
	@echo "  make objects   #statically build using object files"
	@echo "  make shared    #create a build using shared libraries"
archives:
	${MAKE} -f Makefile.archives
objects:
	${MAKE} -f Makefile.objects
shared:
	${MAKE} -f Makefile.shared
clean:
	rm -fr build
	${MAKE} -C vendor/dep1 clean
	${MAKE} -C vendor/dep2 clean
