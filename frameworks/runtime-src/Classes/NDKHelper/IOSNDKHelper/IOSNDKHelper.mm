//
//  IOSNDKHelper.cpp
//  EasyNDK-for-cocos2dx
//
//  Created by Amir Ali Jiwani on 23/02/2013.
//
//

#import "IOSNDKHelper.h"
#import "NDKHelper.h"

#pragma mark -
#pragma mark Private To IOSNDKHelper.mm

static NSObject *helperInstance = nil;

void IOSNDKHelperImpl::SetNDKReciever(void *reciever)
{
    helperInstance = (NSObject*)reciever;
}

NSObject *getHelperInstance()
{
    return helperInstance;
}

#pragma mark -
#pragma mark IOSNDKHelperImpl Methods

void IOSNDKHelperImpl::RecieveCPPMessage(const string& methodName, const char* methodParams)
{
    NSObject *reciever = getHelperInstance();
    if (reciever == nil)
    {
        return;
    }
    
    if (methodName.length() == 0)
        return;
    
    NSString *methodCalledStr = [NSString stringWithFormat:@"%@:", [NSString stringWithUTF8String:methodName.c_str()]];
    SEL selectorToBeCalled = NSSelectorFromString(methodCalledStr);
        
        // Return from message if the selector won't respond to our reciever
        if (![reciever respondsToSelector:selectorToBeCalled])
        {
            NSLog(@"Reciever won't respond to selector : %@", methodCalledStr);
            return;
        }

    if (methodParams != NULL)
    {
        // Convert the parameters into NSDictionary

        NSString *methodParamsJson = [[NSString alloc] initWithUTF8String:methodParams];
        NSData *jsonData = [methodParamsJson dataUsingEncoding:NSUTF8StringEncoding];
        [methodParamsJson release];
    
        //parse out the json data
        NSError* error = nil;
        NSDictionary* json = [NSJSONSerialization
                              JSONObjectWithData:jsonData
                              options:kNilOptions
                              error:&error];
        
        // If parameters are available call the respective selector with parameters
        if (error == nil)
        {
            [reciever performSelector:selectorToBeCalled withObject:json];
        }
        else
        {
            NSLog(@"parameter error");
            return;
        }
    }
    else
    {
        [reciever performSelector:selectorToBeCalled withObject:[NSDictionary dictionary]];
    }
}

#pragma mark -
#pragma mark IOSNDKHelper Implementation

@implementation IOSNDKHelper

+(void)SendMessage:(NSString *)methodName WithParameters:(NSDictionary *)prms
{
    string method = [methodName UTF8String];
    if (prms != nil)
    {
        NSError *error = nil;
        NSData *jsonData = [NSJSONSerialization
                            dataWithJSONObject:prms
                            options:NSJSONWritingPrettyPrinted
                            error:&error];
        
        if (error != nil)
            return;
        
        NSString *jsonPrmsString = [[NSString alloc] initWithData:jsonData
                                                         encoding:NSUTF8StringEncoding];
        NDKHelper::HandleMessage(method, [jsonPrmsString UTF8String]);
        
        [jsonPrmsString release];
        
    } else
    {
         NDKHelper::HandleMessage(method, NULL);
    }
}

//native接收的对象
+ (void) SetNDKReciever:(NSObject*)reciever
{
    IOSNDKHelperImpl::SetNDKReciever((void*)reciever);
}

@end
