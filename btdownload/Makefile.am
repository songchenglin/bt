AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS=btdownload
btdownload_SOURCES=main.c
btdownload_LDADD=$(top_builddir)/debug/libdebug.a \
				 $(top_builddir)/torrent/libtorrent.a
btdownload_CPPFLAGS=-I$(top_builddir)/debug \
					-I$(top_builddir)/torrent
