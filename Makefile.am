## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

mikordocdir = ${prefix}/doc/mikor
mikordoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(mikordoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(mikordocdir)
