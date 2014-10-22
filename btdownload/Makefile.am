AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS=btdownload
btdownload_SOURCES=main.c
btdownload_LDADD=$(top_builddir)/debug/libdebug.a
btdownload_CPPFLAGS=-I$(top_builddir)/debug \
					-I$(top_builddir)/torrent
