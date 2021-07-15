#增加一个编译目标，下面的sim_idev即是这个模块要编译的.c文件的文件名
TARGET := sim_e2dev
#obj-m是内核Makefile中将会使用到的，编译的时候这个变量会传入到内核目录中起效果
#这里理解的话先别纠结，照着做先，也就是obj-m = xx.o在编译之后就会生成xx.ko用来加载
obj-m := $(TARGET).o

#保存但前目录的绝对路径，这个变量将会传递给内核Makefile告诉它我要编译的内核的源码路径
PWD := $(shell pwd)

#这里的KDIR就是但前运行的Linux系统里面已经编译好的内核output
#简单理解我们就是要用一个编译好的内核去构建属于这个内核的可加载的模块
#可以在终端里cd /lib/modules/$(uname -r)/build里看看，关注下Module.symvers，
#细节后续有章节再介绍，先把正事搞起来
KDIR := /lib/modules/$(shell uname -r)/build

.PHONY: build clean

build:
	# 加个打印告诉全世界，开始编译了
	@echo "Start $(TARGET) build"
	# -C是指定一个目录，也就是我们内核的output路径，
	# 这时候回去跑到KDIR的路径里面执行Makefile（可以看下，KDIR目录里面有一个Makefile文件）命令，
	# 然后modules就是类似我们上面的build定义类似的，内核定义好了个modules的编译参数
	# 我们只要把要编译的模块代码通过M变量传递过去就可以编译内核模块了
	make -C $(KDIR) M=$(PWD) modules
	cp -rf $(TARGET).ko $(output_dir)/

clean:
	#下面这些是编译内核模块输出的一些中间参数，我没在clean的时候可以把这些删除
	make -C $(KDIR) M=$(PWD) clean


