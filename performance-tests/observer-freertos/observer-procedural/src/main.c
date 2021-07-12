#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

/**
 * This is a procedural implementation of an "Observer" style design pattern
 * Meant to compare its performance with an OOP-equivalent implementation,
 * in terms of memory usage and CPU cycle usage.
 * Asynchronous implementation for an RTOS environment.
 */


// PROGRAM SIZE:
// Checking size .pio/build/esp32dev/firmware.elf
// Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
// RAM:   [          ]   3.8% (used 12604 bytes from 327680 bytes)
// Flash: [==        ]  15.3% (used 160209 bytes from 1048576 bytes)
// Building .pio/build/esp32dev/firmware.bin

// Settings
static const int queue_len = 5;

// Globals
static QueueHandle_t observer1_queue;
static QueueHandle_t observer2_queue;
void notifier_task(void *pvParameter);
void observer1_task(void *pvParameter);
void observer2_task(void *pvParameter);

void app_main(void)
{
    printf("Hello world!\n");
	// Creating queues
	observer1_queue = xQueueCreate(queue_len,sizeof(uint32_t));
	observer2_queue = xQueueCreate(queue_len,sizeof(uint32_t));

	printf("Starting notifier...\n");
	xTaskCreate(notifier_task,
				"notifier_task",
				configMINIMAL_STACK_SIZE,
				NULL,
				1,
				NULL);

	printf("Starting observers...\n");
	xTaskCreate(observer1_task,
				"observer1_task",
				configMINIMAL_STACK_SIZE,
				NULL,
				1,
				NULL);
	xTaskCreate(observer2_task,
				"observer2_task",
				configMINIMAL_STACK_SIZE,
				NULL,
				1,
				NULL);
    
}

void notifier_task(void *pvParameter)
{
	uint32_t data = 0;
	while (1)
	{
		// Get data (e.g. from a sensor)
		data = esp_random();

		// Send data to observers
		xQueueSend(observer1_queue,(void*)&data,0);
		xQueueSend(observer2_queue,(void*)&data,0);
		vTaskDelay(100/portTICK_PERIOD_MS); // in ms
	}
	
}

void observer1_task(void *pvParameter)
{
	uint32_t receive_message = 0; 
	while (1)
	{
		// Non-blocking receive from queue
		if (xQueueReceive(observer1_queue,(void*)&receive_message,0) == pdTRUE) {
			// Print to terminal
			printf("Observer 1 Received: %u",receive_message);
		}
		// Simulate some processing time for its main operations
		vTaskDelay(300/portTICK_PERIOD_MS); // in ms
	}
	
}

void observer2_task(void *pvParameter)
{
	uint32_t receive_message = 0; 
	while (1)
	{
		// Non-blocking receive from queue
		if (xQueueReceive(observer2_queue,(void*)&receive_message,0) == pdTRUE) {
			// Print to terminal
			printf("Observer 2 Received: %u",receive_message);
		}
		// Simulate some processing time for its main operations
		vTaskDelay(500/portTICK_PERIOD_MS); // in ms
	}
	
}