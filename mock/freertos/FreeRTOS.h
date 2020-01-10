#ifndef __FreeRTOS_H__
#define __FreeRTOS_H__


// components/esp_common/include/esp_err.h:typedef int32_t esp_err_t;
// components/esp_common/include/esp_err.h:#define ESP_OK          0       /*!< esp_err_t value indicating success (no error) */
// components/esp_common/include/esp_err.h:#define ESP_FAIL        -1      /*!< Generic esp_err_t code indicating failure */

    // to mock:
    /*
    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(BLINK_GPIO, 0);

    vTaskDelay(1000 / portTICK_PERIOD_MS);
    */

#endif