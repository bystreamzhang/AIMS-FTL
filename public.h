#ifndef PUBLIC_H
#define PUBLIC_H

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RETURN_ERROR (-1)
#define RETURN_OK 0

#define MAX_IO_NUM 10000000000
#define MAX(a, b) ((a)>(b) ? (a):(b))

/* IO 类型 */
typedef enum {
    IO_READ,
    IO_WRITE
} IOType;

/* IO 结构体 */
typedef struct {
    IOType type;
    uint64_t lba;
    uint64_t ppn;
} IOUnit;

/* IO 数组 */
typedef struct {
    uint64_t len;       // IO数量
    char *inputFile;    // IO数组文件名
    IOUnit ioUnit;      // IO数组成员
} IOVector;

/* 关键指标 */
typedef struct {
    uint32_t testIOCount;               // 读IO数量
    double algorithmRunningDuration;    // 算法运行时长
    double accuracy;                    // 读IO准确率
    long memoryUse;                     // 内存占用 KB  (程序外工具统计)
} KeyMetrics;

#ifdef __cplusplus
}
#endif

#endif  // PUBLICK_H