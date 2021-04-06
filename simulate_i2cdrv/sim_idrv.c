/*************************************************************************
	> File Name: sim_idev.c
	> Author: gohi
	> Mail: 
	> Created Time: 
 ************************************************************************/
#include <linux/init.h> 
#include <linux/module.h>
/* 平台设备头文件，包含平台设备注册注销等操作接口定义 */
#include <linux/platform_device.h>

/* probe函数的如参就是和之匹配的目标device的机构体指针，
 * 即上文有写到的g_sim_ipdev，在驱动里面就可以通过这个获取
 * 到设备里面所有的预定义信息 */
static int sim_idrv_probe(struct platform_device *pdev)
{
    /* 我们先加一个打印调试一下 */
    printk("Start %s probe\n", pdev->name);

    return 0;
}

static int sim_idrv_remove(struct platform_device *pdev)
{
    return 0;
}

/* 定义全局结构体变量 */
static struct platform_driver g_sim_idri = {
    /* 这就是驱动里面有名的函数指针了，
     * 将sim_idrv_probe函数赋给g_sim_idri驱动，
     * 当和device匹配到的时候就会执行probe函数 */
    .probe      = sim_idrv_probe,
    /* remove函数指针就顾名思义了，在卸载driver的时候会调用，
     * 做驱动相关的资源释放等 */
    .remove     = sim_idrv_remove,
    /* 给这个driver附上owner和name，在没有设备树匹配
     * 或者ACPI匹配的情况下会调用name字段匹配，即如果有
     * name为“sim_idev”的device就会触发执行probe */
    .driver     = {
        .owner  = THIS_MODULE,
        .name   = "sim_idev",
    },
};

/* 这是一个宏定义，展开之后就是
static int __init g_sim_idri_init(void)
{
    return platform_driver_register(&(g_sim_idri));
}
module_init(g_sim_idri_init);
static void __exit g_sim_idri_exit(void)
{
    platform_driver_unregister(&(g_sim_idri));
}
module_exit(g_sim_idri_exit);
和我们上文写的sim_idev类似，注册一个platform_driver和device匹配。
有兴趣可以阅读下内核对module_platform_driver的宏定义实现，还是比较有趣的。
 * */
module_platform_driver(g_sim_idri);

MODULE_DESCRIPTION("Simulate the creation of I2C controller driver");
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("wfivenx@163.com");
