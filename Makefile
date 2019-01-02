SUBDIRS = src chap01 chap01_2 chap02 chap03

.PHONY: all everything debug clean

all: everything

everything:
	@for dir in $(SUBDIRS); do \
		$(MAKE) $(T) --directory=$$dir || exit 1; \
	done

debug: T := debug
debug: all

profile: T := profile
profile: all

clean:	T := clean
clean: everything



