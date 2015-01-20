# ���Ŀ�ִ���ļ�
PROGRAM := thread_pool
LDFLAGS := -lpthread
CFLAGS  := -O -W
INCLUDE :=
CC		:= gcc
#ͨ�䵱ǰĿ¼��˵�е�.c�ļ�
SOURCES := $(wildcard *.c)   
#��$(SOURCES)�еı������Ϻ�׺��.c��ȫ���滻��.o��
OBJS    := $(patsubst %.c,%.o,$(SOURCES))  

.PHONY: clean 

$(PROGRAM): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o: %.c
	$(CC) -c $^ $(CFLAGS) $(INCLUDE)    

clean:
	rm *.o $(PROGRAM) -f

# $@:��ǰ�����Ŀ���ļ����� $<:�����б��еĵ� һ�������ļ����� $^:�����������б����������������ظ����ļ�������