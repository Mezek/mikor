## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

mikordocdir = ${prefix}/doc/mikor
mikordoc_DATA = \
	README.md\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(mikordoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(mikordocdir)
	
clean:
	rm -f src/Mikor src/Test1 src/Test2 src/Test3
	rm -f src/CheckOptimalA src/CheckOptimalC src/DebugOptimalA
	rm -f src/FindOptimalA src/FindOptimalC

