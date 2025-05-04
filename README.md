# 🎯 PlatformIO 彩色调试日志库（serial.color.debug）

> 一个轻量、支持彩色输出的日志调试宏头文件，适用于 ESP32 / ESP8266 / Arduino 等平台。

---

## 🧩 功能特点

- ✅ 支持 `Serial.print` 和 `Serial.printf`
- ✅ 提供 INFO / STATUS / WARN / ERROR 四级日志分类
- ✅ 彩色终端支持，便于阅读（支持 ANSI 控制码）
- ✅ 每行附带 Emoji 图标标识类型
- ✅ 宏定义可编译时自动关闭日志（不产生体积）
- ✅ 支持外部控制日志开关，无需修改源码
- ✅ 无需第三方库，100% 纯头文件

---

## 🚀 快速上手
### ✅ 安装方式（建议通过 PlatformIO 导入）

你可以在 **PlatformIO 项目的 `platformio.ini` 文件中添加以下依赖项：**
```ini
monitor_filters = esp32_exception_decoder, time, log2file

lib_deps =
  https://github.com/YourUsername/serial-color-debug.git
```

### ✅ 示例代码（参考exampples\BasicUsage\BasicUsage.cpp）

```cpp
#include <Arduino.h>  // Arduino核心库
#include "serial_color_debug.h"  // 导入serial.color.debug库

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

```

### 🔍 各类日志输出示例

### 🧪 各类调试日志宏说明（含用途、颜色、格式化支持、输出示例）

| 宏名称                 | 用途                                           | 终端颜色           | 是否支持 `printf` 格式 | 示例代码                                     | 终端输出样式                   |
|------------------------|------------------------------------------------|--------------------|--------------------------|----------------------------------------------|--------------------------------|
| `DEBUG_INFO(msg)`      | 打印普通运行信息（如启动完成、状态初始化等） | 🟢 绿色             | ❌                       | `DEBUG_INFO("系统启动完成");`                | `[INFO]  ✅ 系统启动完成`       |
| `DEBUG_STATUS(msg)`    | 打印系统状态（如 WiFi 连接、IP 获取等）       | 🔵 青色             | ❌                       | `DEBUG_STATUS("WiFi 已连接");`              | `[STAT]  📶 WiFi 已连接`        |
| `DEBUG_WARN(msg)`      | 打印非致命警告（如电压偏低、传感器波动）     | 🟡 黄色             | ❌                       | `DEBUG_WARN("电压过低");`                   | `[WARN]  ⚠️ 电压过低`            |
| `DEBUG_ERROR(msg)`     | 打印致命错误（如初始化失败、断连）           | 🔴 红色             | ❌                       | `DEBUG_ERROR("串口不可用");`                | `[ERROR] 💥 串口不可用`         |
| `DEBUG_INFOF(fmt, ...)`| 打印带参数的普通信息（使用 printf 风格格式） | 🟢 绿色             | ✅                       | `DEBUG_INFOF("电压为 %.2fV", 3.74);`         | `[INFO]  ✅ 电压为 3.74V`        |
| `DEBUG_STATUSF(fmt, ...)`| 打印格式化的状态信息                        | 🔵 青色             | ✅                       | `DEBUG_STATUSF("IP: %s", "192.168.1.8");`    | `[STAT]  📶 IP: 192.168.1.8`     |
| `DEBUG_WARNF(fmt, ...)`| 打印格式化的警告信息                         | 🟡 黄色             | ✅                       | `DEBUG_WARNF("电压过低: %.2fV", 3.00);`      | `[WARN]  ⚠️ 电压过低: 3.00V`     |
| `DEBUG_ERRORF(fmt, ...)`| 打印格式化的错误信息                         | 🔴 红色             | ✅                       | `DEBUG_ERRORF("错误码: %d", -1);`            | `[ERROR] 💥 错误码: -1`          |


---

### 🎨 彩色输出说明（基于 ANSI 控制码）

如果你使用的是支持 ANSI 控制码的终端工具（如 PlatformIO、VSCode 内置终端、Linux 终端），则日志将自动显示颜色和图标。

不支持彩色的工具（如 Arduino IDE 串口监视器）将会看到原始控制字符，建议改用以下工具：

| 工具                         | 彩色支持 | 推荐级别 |
|------------------------------|----------|-----------|
| PlatformIO / VSCode Terminal | ✅        | ⭐⭐⭐⭐⭐    |
| Arduino IDE 串口监视器       | ❌        | ⭐         |

---

## ❓ 常见问题

**Q: 为什么我的串口没有彩色输出？**  
因为 Arduino IDE 自带的串口监视器不支持 ANSI 控制码。建议改用 PlatformIO 或其他带彩色支持的终端工具。

**Q: 使用 `DEBUG_INFOF()` 编译报错？**  
请确认你的开发板是否支持 `Serial.printf()` —— ESP32 和 ESP8266 支持。

---

## 📄 License

本项目使用 **MIT License**，欢迎自由使用和二次开发。

---

## 👨‍💻 作者

**开发者**：YuZou 邹宇  
**联系邮箱**：zouyu1121@gmail.com

如果你觉得有帮助，欢迎 🌟Star 或推荐给朋友！