PROC=hexrays_deepcompile
__CFLAGS=-std=c++11

include ../plugin.mak

# MAKEDEP dependency list ------------------
$(F)hexrays_deepcompile$(O): $(I)bitrange.hpp $(I)bytes.hpp $(I)config.hpp $(I)fpro.h  \
	          $(I)funcs.hpp $(I)ida.hpp $(I)idp.hpp $(I)kernwin.hpp     \
	          $(I)lines.hpp $(I)llong.hpp $(I)loader.hpp $(I)nalt.hpp   \
	          $(I)netnode.hpp $(I)pro.h $(I)range.hpp $(I)segment.hpp   \
	          $(I)ua.hpp $(I)xref.hpp hexrays_deepcompile.cpp
