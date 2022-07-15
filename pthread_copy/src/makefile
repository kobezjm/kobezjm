.PHONY:clean install disclean                                               



INCLUDE_PATH=../include
CC=gcc
CFLAGS=-I$(INCLUDE_PATH) -Wall -c -o
CPPFLAGS=
LDFLAGS=-lpthread -lssl -lcrypto
LIBRARY_PATH=../library
TARIGET=PTHREAD_COPY
RM=sudo rm -rf
CP=sudo cp
SFILE=$(wildcard *.c)
DFILE=$(patsubst %.c,%.o,$(SFILE))

$(TARIGET):$(DFILE)#编译主目标
	$(CC) $^ -o $@

%.0:%.c#次目标
	$(CC) $(CFLAGS) $<
clean:
	$(RM) $(DFILE) $(TARIGET)

disclean:
	 #卸载程序和删除配置文件
 
install:
	  #拷贝安装到指定位置  
