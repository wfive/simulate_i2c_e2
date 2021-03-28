/*************************************************************************
	> File Name: sim_idev.h
	> Author: 
	> Mail: 
	> Created Time:
 ************************************************************************/

#ifndef _SIM_IDEV_H
#define _SIM_IDEV_H

#define IDEV_DBG(fmt, arg...)  \
    do {                       \
      if (debug) {             \
        printk(KERN_ALERT "[%s](%d)" fmt, __func__, __LINE__, ##arg); \
      }                        \
    } while (0)

typedef struct sim_idev_data {
    /* 控制器下从设备数量 */
    unsigned int slave_max_num;
    /* 设置写保护地址，设定某个I2C地址不可写 */
    unsigned int wr_protect_addr;
} sim_idev_data_t;

#endif
