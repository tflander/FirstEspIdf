#include <stdint.h>

typedef uint32_t TickType_t;
#define portTICK_PERIOD_MS 11

void vTaskDelay( const TickType_t xTicksToDelay );
