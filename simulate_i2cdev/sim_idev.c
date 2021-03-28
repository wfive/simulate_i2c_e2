/*************************************************************************
	> File Name: sim_idev.c
	> Author: gohi
	> Mail: 
	> Created Time: 
 ************************************************************************/
#include <linux/init.h> 
#include <linux/module.h>
/* 错误码定义头文件 */
#include <linux/errno.h>
/* 平台设备头文件，包含平台设备注册注销等操作接口定义 */
#include <linux/platform_device.h>

/* static是静态的意思，在这里的作用是函数定义的作用于仅在本文件中生效，避免多个.c函数名一样导致冲突
 * 返回的类型是int，这个是内核框架定义好的，接口返回为int，
 * __init告诉编译器这个接口的属性，和__exit相同作用，这样这个接口编译输出的代码和数据会在制定的空间中，详细的可以先不纠结，照做
 * 函数名sim_idev_init，(void)表示函数无传入参数。
 * return 0; 返回0代表成功非0为失败 */
static int __init sim_idev_init(void)
{
    /* 内核里面打印用的是printk和我们平常写的用户台app不一样
     * 我们写app的时候开头就是include <stdio.h>,printf就定义在那里面，
     * 内核不一样，没有stdio.h这些标准C库的，但是内核有自己实现的一些常用接口，比如打印就是printk */
    printk(KERN_ALERT "Start sim_idev_init\n");
    return 0;
}

/* 整体和init的类似，函数返回的是void，没有返回值，函数return不带任何东西表示返回void */
static void __exit sim_idev_exit(void)
{
    return;
}
/* 内核定义好的接口，直接调用，我们模块加载和卸载时候就会调用传入的接口
 * 也就是我们模块加载的时候就会执行sim_idev_init函数 */
module_init(sim_idev_init);
module_exit(sim_idev_exit);

MODULE_DESCRIPTION("Simulate the creation of I2C controller devices");
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("wfivenx@163.com");
