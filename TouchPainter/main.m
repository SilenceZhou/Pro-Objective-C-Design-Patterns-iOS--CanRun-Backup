//
//  main.m
//  TouchPainter
//
//  Created by Carlo Chung on 8/21/10.
//  Copyright 2010 Carlo Chung. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TouchPainterAppDelegate.h"

//int main(int argc, char *argv[]) {
//
//    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
//    int retVal = UIApplicationMain(argc, argv, nil, nil);
//    [pool release];
//    return retVal;
//}

int main(int argc, char * argv[]) {
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([TouchPainterAppDelegate class]));
    }
}
