#==========================================================#
#===============    Makefile v1.0    ======================#
#==========================================================#

#==========================================================
#  Commands
CC		= gcc
CPP		= g++
AR		= ar
RANLIB	= ranlib

#  Flags
ifeq ($(BUILD),DEBUG)
D = d
C_LFLAGS		= -g -Wall -D_DEBUG -DLINUX -fpermissive
CXX_FLAGS 		= -g -Wall -Woverloaded-virtual -D_DEBUG -DLINUX -m64 -std=c++11
else
D = 
C_LFLAGS		= -g -Wall -DNDEBUG -DLINUX -fpermissive
CXX_FLAGS 		= -g -Wall -Woverloaded-virtual -DNDEBUG -DLINUX -m64 -std=c++11 
endif

ARFLAGS			= -rc
#==========================================================

#==========================================================
#  Commands
CODE_DIR = luahttpd/ask luahttpd/crypto luahttpd/framework luahttpd/http luahttpd/net luahttpd/session luahttpd/script luahttpd/lib3rd/lua/lua luahttpd/lib3rd/lua/tolua/lib
INCLUDE_DIR = luahttpd luahttpd/framework luahttpd/lib3rd/fxlib/include luahttpd/lib3rd/lua/include luahttpd/lib3rd/jsoncpp luahttpd/lib3rd/leveldb/include luahttpd/lib3rd/lua/include
LIB_FILE = -lpthread -lz -lrt -ldl -Lluahttpd/lib3rd/fxlib/lib -lfxhttp -lfxnet -lfxhelper -lfxdb -lfxlogger -lcurl -lmysqlclient -Lluahttpd/lib3rd/leveldb/lib -lleveldb -Lluahttpd/lib3rd/jsoncpp/json -ljson
OUTPUT_DIR =bin
OUTPUT = luahttpd$(D)
#==========================================================

OBJS = $(foreach i, $(CODE_DIR), $(shell find $(i) -name "*.cpp"))
OBJS2 = $(foreach i, $(CODE_DIR), $(shell find $(i) -name "*.c"))
INCLUDE_FLAG = $(foreach i, $(INCLUDE_DIR), -I$(i))
#OBJS += ../../dependencies/common/exelogger.cpp ../../dependencies/common/markupstl.cpp

all:$(OUTPUT)

OBJFILE = $(OBJS:.cpp=.o) $(OBJS2:.c=.o)
#OBJFILE = $(OBJS:.cpp=.o)

$(OUTPUT):$(OBJFILE)
	@echo Build.. $@
	@$(CPP) $^ $(CXX_FLAGS) -o $(OUTPUT_DIR)/$(OUTPUT) $(LIB_FILE)
	#@$(AR) $(ARFLAGS) $(OUTPUT_DIR)/$(OUTPUT) $(OBJS:.cpp=.o)
	#@$(RANLIB) $(OUTPUT_DIR)/$(OUTPUT)

%.o: %.cpp
	@echo Compile.. $@
	@$(CPP) $(CXX_FLAGS) $(INCLUDE_FLAG) -c $< -o $@ 

%.o: %.cc
	@echo Compile.. $@
	@$(CC) $(C_FLAGS) $(INCLUDE_FLAG) -c $< -o $@ 

%.o: %.c
	@echo Compile.. $@
	@$(CC) $(C_FLAGS) $(INCLUDE_FLAG) -c $< -o $@ 
	
clean:
	rm -f $(OUTPUT_DIR)/$(OUTPUT)
	rm -f $(OBJFILE)
	
	@echo Clean ...done!
