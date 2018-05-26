//
//  IOSNDKHelper.h
//  EasyNDK-for-cocos2dx
//
//  Created by Amir Ali Jiwani on 23/02/2013.
//
//

#import <Foundation/Foundation.h>

#ifndef __EasyNDK_for_cocos2dx__IOSNDKHelper__
#define __EasyNDK_for_cocos2dx__IOSNDKHelper__

#include "IOSNDKHelper-C-Interface.h"

@interface IOSNDKHelper : NSObject

//native接收的对象
+ (void) SetNDKReciever:(NSObject*)reciever;

//native发送数据到游戏
+ (void) SendMessage:(NSString*)methodName WithParameters:(NSDictionary*)prms;

@end

#endif /* defined(__EasyNDK_for_cocos2dx__IOSNDKHelper__) */
