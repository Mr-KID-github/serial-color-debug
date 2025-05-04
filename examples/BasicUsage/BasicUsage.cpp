#include <Arduino.h>  // Arduino核心库
#include "debug_log.h"

// setup()函数：初始化系统
void setup() {
    Serial.begin(115200);
    DEBUG_INFO("启动完成");

    // ----------------

    DEBUG_INFO("系统初始化完成");
    DEBUG_STATUSF("启动时间: %lu ms", millis());
    DEBUG_STATUS("正在连接串口...");
    DEBUG_WARN("电压偏低，已进入保护模式");
    DEBUG_ERROR("系统崩溃！即将重启");
  
}

// loop()函数：主循环函数
void loop() {

}