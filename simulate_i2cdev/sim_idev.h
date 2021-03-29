/*************************************************************************
	> File Name: sim_idev.h
	> Author: 
	> Mail: 
	> Created Time:
 ************************************************************************/
/* 如果没有定义_SIM_IDEV_H就定义_SIM_IDEV_H，然后引用该文的定义
 * 这样做可以避免一个C文件中头文件嵌套include多次导致数据、宏等重复定义 */
#ifndef _SIM_IDEV_H
#define _SIM_IDEV_H

/* 用宏封装我们的debug打印接口，我们定义一个模块debug的变量，通过更改debug变量的值来控制debug信息输出。
 * args..表示第一个参数传给fmt,参入参数可能为多个。 ##args表示args...中的多个参数，串连起来
 * 宏定义中用do...while(0)将if包裹起来是为了避免在条件语句里面引用的时候导致乱入的if嵌套
 */
#define IDEV_DBG(fmt, arg...)  \
    do {                       \
      if (debug) {             \
        printk(KERN_ALERT "[%s](%d)" fmt, __func__, __LINE__, ##arg); \
      }                        \
    } while (0)

/* typedef 的作用就是定义 sim_idev_data_t 为 struct sim_idev_data */
typedef struct sim_idev_data {
    /* 控制器下从设备数量 */
    unsigned int slave_max_num;
    /* 设置写保护地址，设定某个I2C地址不可写 */
    unsigned int wr_protect_addr;
} sim_idev_data_t;

#endif
