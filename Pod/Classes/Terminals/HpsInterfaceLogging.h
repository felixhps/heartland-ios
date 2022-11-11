//
//  HpsInterfaceLogging.h
//  Heartland-iOS-SDK
//
//  Created by Desimini, Wilson on 9/27/22.
//

#import <Foundation/Foundation.h>

@class HpsConnectionConfig;

@protocol HpsInterfaceLogging <NSObject>

- (void)hpsInterfaceDidDisconnect;
- (void)hpsInterfaceDidReceiveData:(NSData *)data;
- (void)hpsInterfaceDidReceiveError:(NSError *)error;
- (void)willLogHPSInterfaceWithConfig:(HpsConnectionConfig *)config;

@end
