include_HEADERS = \
    libsuwiz/include/suwiz.h \
    libsuwiz/include/common.h

lib_LIBRARIES = libsuwiz.a
libsuwiz_a_SOURCES = \
    libsuwiz/src/suwiz.c \
    libsuwiz/src/convert.h \
    libsuwiz/src/convert.c \
    libsuwiz/src/constraints.h \
    libsuwiz/src/constraints.c \
    libsuwiz/src/solve_recursive.c
libsuwiz_a_CPPFLAGS = \
    -I$(top_srcdir)/libsuwiz/include \
    -I$(top_srcdir)/libsuwiz/src

bin_PROGRAMS = suwiz
suwiz_SOURCES = \
    suwiz-cli/src/main.c \
    suwiz-cli/src/app.h \
    suwiz-cli/src/argp.h \
    suwiz-cli/src/argp.c
suwiz_CPPFLAGS = \
    -I$(top_srcdir)/libsuwiz/include \
    -I$(top_srcdir)/suwiz-cli/src
suwiz_LDADD = libsuwiz.a

check_PROGRAMS = test/driver
test_driver_SOURCES = \
    libsuwiz/test/driver.c \
    libsuwiz/test/test_suwiz.h \
    libsuwiz/test/test_suwiz.c \
    libsuwiz/test/test_constraints.h \
    libsuwiz/test/test_constraints.c \
    libsuwiz/test/test_convert.h \
    libsuwiz/test/test_convert.c \
    libsuwiz/test/test_solve.h \
    libsuwiz/test/test_solve.c
test_driver_CPPFLAGS = \
    -I$(top_srcdir)/libsuwiz/include \
    -I$(top_srcdir)/libsuwiz/src \
    -I$(top_srcdir)/libsuwiz/test
test_driver_LDADD = libsuwiz.a -lbcunit

TESTS = test/driver
LOG_DRIVER = test/driver