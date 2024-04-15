/*
 *  main.c - Application main entry point
 */

// #include <stdio.h>
// #include <zephyr/device.h>
// #include <zephyr/kernel.h>
// // #include <zephyr/drivers/display.h>
// #include <zephyr/display/cfb.h>
// #include <zephyr/logging/log.h>

#include <zephyr/kernel.h>
// #include <zephyr/logging/log.h>

// #include "display.h"
#include <zephyr/drivers/display.h>


// #include <logging/log.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, 3);

#define STACKSIZE 1024
#define PRIORITY 7

// LOG_MODULE_REGISTER(display);

static const struct device *display = DEVICE_DT_GET(DT_NODELABEL(ssd1306));

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
void main_thread(void* id, void* unused1, void* unused2) {
    LOG_INF("%s", __func__);

    display_init();
    display_play();
}

K_THREAD_DEFINE(main_id, STACKSIZE, main_thread, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);
