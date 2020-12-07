# supported: GCC, ICC
COMPILER = GCC

# Define the color of the likwid-pin output
# Can be NONE, BLACK, RED, GREEN, YELLOW, BLUE,
# MAGENTA, CYAN or WHITE
COLOR = BLUE#NO SPACE

# Path were to install likwid
PREFIX =  /root/Desktop/High-performance-computing/lab10_prodiling/likwid-2.3.0/likwid-2.3#NO SPACE
MANPREFIX = $(PREFIX)/man#NO SPACE

# For the daemon based secure msr access configure
# the absolute path to the msr daemon executable.
# $(PREFIX)/bin/likwid-msrD
MSRDAEMON = NO#NO SPACE
#MSRDAEMON = $(PREFIX)/bin/likwid-msrD#NO SPACE

# Change to YES to a build shared library instead of a static one
SHARED_LIBRARY = NO#NO SPACE

# Optional Fortran90 interface module
# Uncomment line below to enable
# Please refer to the WIKI documentation for details on usage
# Notice: For gfortran at least version 4.2 is required!
#FORTRAN_INTERFACE = likwid.mod

MAX_NUM_THREADS = 128
MAX_NUM_NODES = 8
HASH_TABLE_SIZE = 20

# Versioning Information
VERSION = 2
RELEASE = 3
DATE    = 9.2.2012

LIBLIKWIDPIN = $(abspath $(PREFIX)/lib/liblikwidpin.so)
LIKWIDFILTERPATH = $(abspath $(PREFIX)/share/likwid)

