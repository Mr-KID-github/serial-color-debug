#pragma once
#include <Arduino.h>

// 🎨 ANSI 控制字符，用于终端颜色控制
#define ANSI_RESET   "\033[0m"   // 重置颜色
#define ANSI_RED     "\033[31m"  // 红色
#define ANSI_GREEN   "\033[32m"  // 绿色
#define ANSI_YELLOW  "\033[33m"  // 黄色
#define ANSI_CYAN    "\033[36m"  // 青色（蓝绿）
#define ANSI_BLUE    "\033[34m"  // 蓝色
#define ANSI_MAGENTA "\033[35m"  // 品红

// ⚙️ 开关调试日志功能（true = 打开，false = 关闭）
#define DEBUG_MODE true

#if DEBUG_MODE

  // ✅ 基础输出支持（原始串口输出）
  #define DEBUG_PRINT(x)       Serial.print(x)
  #define DEBUG_PRINTLN(x)     Serial.println(x)
  #define DEBUG_PRINTF(...)    Serial.printf(__VA_ARGS__)

  // ✅ 文本日志输出（非格式化，字符串常量使用 F() 宏节省 Flash）
  #define DEBUG_INFO(msg)     do { Serial.print(F(ANSI_GREEN  "[INFO]  ✅ ")); Serial.print(F(msg)); Serial.print(F(" at ")); Serial.print(F(ANSI_BLUE __FILE__)); Serial.print(F(":")); Serial.print(__LINE__); Serial.println(F(ANSI_RESET)); } while (0)
  #define DEBUG_STATUS(msg)   do { Serial.print(F(ANSI_CYAN   "[STAT]  📶 ")); Serial.print(F(msg)); Serial.print(F(" at ")); Serial.print(F(ANSI_BLUE __FILE__)); Serial.print(F(":")); Serial.print(__LINE__); Serial.println(F(ANSI_RESET)); } while (0)
  #define DEBUG_WARN(msg)     do { Serial.print(F(ANSI_YELLOW "[WARN]  ⚠️  ")); Serial.print(F(msg)); Serial.print(F(" at ")); Serial.print(F(ANSI_MAGENTA __FILE__)); Serial.print(F(":")); Serial.print(__LINE__); Serial.println(F(ANSI_RESET)); } while (0)
  #define DEBUG_ERROR(msg)    do { Serial.print(F(ANSI_RED    "[ERROR] 💥 ")); Serial.print(F(msg)); Serial.print(F(" at ")); Serial.print(F(ANSI_MAGENTA __FILE__)); Serial.print(F(":")); Serial.print(__LINE__); Serial.println(F(ANSI_RESET)); } while (0)

  // ✅ 格式化日志输出（printf 风格 + 颜色 + 重置）
  #define DEBUG_INFOF(fmt, ...)     do { Serial.print(F(ANSI_GREEN  "[INFO]  ✅ ")); Serial.printf(fmt, ##__VA_ARGS__); Serial.print(F(" at ")); Serial.print(F(ANSI_BLUE __FILE__)); Serial.print(F(":")); Serial.print(__LINE__); Serial.println(F(ANSI_RESET)); } while (0)
  #define DEBUG_STATUSF(fmt, ...)   do { Serial.print(F(ANSI_CYAN   "[STAT]  📶 ")); Serial.printf(fmt, ##__VA_ARGS__); Serial.print(F(" at ")); Serial.print(F(ANSI_BLUE __FILE__)); Serial.print(F(":")); Serial.print(__LINE__); Serial.println(F(ANSI_RESET)); } while (0)
  #define DEBUG_WARNF(fmt, ...)     do { Serial.print(F(ANSI_YELLOW "[WARN]  ⚠️  ")); Serial.printf(fmt, ##__VA_ARGS__); Serial.print(F(" at ")); Serial.print(F(ANSI_MAGENTA __FILE__)); Serial.print(F(":")); Serial.print(__LINE__); Serial.println(F(ANSI_RESET)); } while (0)
  #define DEBUG_ERRORF(fmt, ...)    do { Serial.print(F(ANSI_RED    "[ERROR] 💥 ")); Serial.printf(fmt, ##__VA_ARGS__); Serial.print(F(" at ")); Serial.print(F(ANSI_MAGENTA __FILE__)); Serial.print(F(":")); Serial.print(__LINE__); Serial.println(F(ANSI_RESET)); } while (0)
  
#else

  // ❌ 调试关闭时，所有宏为空
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
  #define DEBUG_PRINTF(...)

  #define DEBUG_INFO(msg)
  #define DEBUG_STATUS(msg)
  #define DEBUG_WARN(msg)
  #define DEBUG_ERROR(msg)

  #define DEBUG_INFOF(fmt, ...)
  #define DEBUG_STATUSF(fmt, ...)
  #define DEBUG_WARNF(fmt, ...)
  #define DEBUG_ERRORF(fmt, ...)

#endif
