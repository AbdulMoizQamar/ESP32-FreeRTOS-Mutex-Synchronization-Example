# ESP32-FreeRTOS-Mutex-Synchronization-Example
This project demonstrates how to safely share a resource (a string buffer) between two concurrent tasks on an ESP32 using a FreeRTOS mutex.
📝 Description:
This project demonstrates how to safely share a resource (a string buffer) between two concurrent tasks on an ESP32 using a FreeRTOS mutex. It includes:
Task1 and Task2, which both write to a shared string (sharedlogBuffer).
A mutex (SemaphoreHandle_t) is used to prevent concurrent writes and avoid race conditions.
This example illustrates the importance of mutual exclusion in multitasking environments to ensure data consistency and proper synchronization.

✅ Features:
FreeRTOS mutex synchronization (xSemaphoreCreateMutex, xSemaphoreTake, xSemaphoreGive)
Two tasks writing to a shared resource without conflict
Serial output to observe controlled access
ESP32 + Arduino framework compatible

📦 Requirements:
ESP32 development board
Arduino IDE or PlatformIO
FreeRTOS (included with ESP32 core)

