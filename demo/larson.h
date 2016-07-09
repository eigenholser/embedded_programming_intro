#ifndef __LARSON_H__
#define __LARSON_H__

#define LARSON_FREQ		0x20U
#define LARSON_MIN_VALUE	0x07U
#define LARSON_MAX_VALUE	0x380U
#define RIGHT     1
#define LEFT      0

extern int larsonValue;
extern int larsonDir;
extern int larsonFlag;
extern int larsonFreq;

void Larson_Init(void);
void shiftLEDBits(void);

#endif  //__LARSON_H__
