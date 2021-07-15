#将当前目录的路径保到main_dir变量中，并export扩展成全局变量
export main_dir := $(shell pwd)
#将main_dir也就是当前目录下面的output目录保存到output_dir变量，并export导出为全局变量
#子目录里面的Makefile都可以使用这个变量将编译产物统一输出到这个路径
export output_dir := $(main_dir)/OutPut

#将我们创建的四个子目录文件夹名保存到变量obj_want,如果有哪个子目录不想编译可以直接删除来控制
obj_want := simulate_e2dev simulate_e2drv simulate_i2cdev simulate_i2cdrv

#我们下面将构建三个编译命令也就是shell下会使用到的make all; make build; make install
#.PHONY使用来避免目录下面有文件名给取成all build install导致混淆
.PHONY: all build install clean
#make all就是做make build和make install
all: build install

#查找每个定义的目录，并执行上面定义的do_dirs_worke函数 $(dir)即目录名作为函数的传参
#make build就是遍历obj_want变量里保存的目录名，每个目录一个一个编译过去，每个目录里面待会也会创建一个子的Makefile用来做具体的代码编译
build: $(obj_want)
	@echo "gooohi build..."
	mkdir -p $(output_dir)
	$(foreach dir,$(obj_want), make -C $(dir);)

#install先不写，我们先不安装到系统路径里面，打印个log意思一下吧
install:
	@echo "gooohi install"

clean:
	$(foreach dir,$(obj_want), make -C $(dir) clean;)
	rm -rf $(output_dir)

