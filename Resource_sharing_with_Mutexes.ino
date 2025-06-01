#include <Arduino.h>

String sharedlogBuffer = "";

SemaphoreHandle_t Mutex;

void Task1(void *pvParameters) {
  while (true) {
    if (xSemaphoreTake(Mutex, portMAX_DELAY)) {
      sharedlogBuffer += "Task1 writing...\n";
      Serial.print("Task1: Writing to buffer\n");
      vTaskDelay(500 / portTICK_PERIOD_MS); 
      xSemaphoreGive(Mutex);
    }
    vTaskDelay(300 / portTICK_PERIOD_MS); 
  }
}
void Task2(void *pvParameters) {
  while (true) {
    if (xSemaphoreTake(Mutex, portMAX_DELAY)) {
      sharedlogBuffer += "Task2 writing...\n";
      Serial.print("Task2: Writing to buffer\n");
      vTaskDelay(100 / portTICK_PERIOD_MS); 
      xSemaphoreGive(Mutex);
    }
    vTaskDelay(300 / portTICK_PERIOD_MS); 
  }
}
void setup() {
  Serial.begin(115200);
  vTaskDelay(1000 / portTICK_PERIOD_MS); 

  Mutex = xSemaphoreCreateMutex();

  // Create tasks
  xTaskCreate(Task1, "Task1", 2048, NULL, 2, NULL);
  xTaskCreate(Task2, "Task2", 2048, NULL, 1, NULL);
}
void loop() {
}