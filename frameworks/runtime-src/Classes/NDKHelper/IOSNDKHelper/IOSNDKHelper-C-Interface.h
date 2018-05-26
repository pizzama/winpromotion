//
//  IOSNDKHelper-C-Interface.h
//  EasyNDK-for-cocos2dx
//
//  Created by Amir Ali Jiwani on 23/02/2013.
//
//

#ifndef EasyNDK_for_cocos2dx_IOSNDKHelper_C_Interface_h
#define EasyNDK_for_cocos2dx_IOSNDKHelper_C_Interface_h

#include "cocos2d.h"
#include <string>
USING_NS_CC;
using namespace std;

class IOSNDKHelperImpl
{
    public :
        IOSNDKHelperImpl();
        ~IOSNDKHelperImpl();
    
        //接受从游戏传的参数，调用native方法
        static void RecieveCPPMessage(const string& methodName, const char* methodParams);
    
        //native接收的对象
        static void SetNDKReciever(void* reciever);
};

#endif
