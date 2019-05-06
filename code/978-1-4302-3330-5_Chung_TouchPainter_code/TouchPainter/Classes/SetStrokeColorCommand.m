//
//  StrokeColorCommand.m
//  TouchPainter
//
//  Created by Carlo Chung on 11/9/10.
//  Copyright 2010 Carlo Chung. All rights reserved.
//

#import "SetStrokeColorCommand.h"
#import "CoordinatingController.h"
#import "CanvasViewController.h"

@implementation SetStrokeColorCommand

//@synthesize delegate=delegate_;
@synthesize postColorUpdateProvider=postColorUpdateProvider_;
@synthesize RGBValuesProvider=RGBValuesProvider_;


- (void)setDelegate:(id<SetStrokeColorCommandDelegate>)delegate
{
    
}

- (void) execute
{
    CGFloat redValue = 0.0;
    CGFloat greenValue = 0.0;
    CGFloat blueValue = 0.0;
    
    // 用协议或闭包来实现适配器模式
    // Retrieve RGB values from a delegate or a block
    
    // 1. 获取颜色分量值
    // 1.1. 通过代理获取颜色  Delegation (object adapter) approach:
    [delegate_ command:self didRequestColorComponentsForRed:&redValue
                 green:&greenValue
                  blue:&blueValue];
    
    
    // 1.2. 通过block获取颜色 two way: Block approach:
    if (RGBValuesProvider_ != nil)
    {
        RGBValuesProvider_(&redValue, &greenValue, &blueValue);
    }
    
    
    
    // 2. 获取颜色
    // Create a color object based on the RGB values
    UIColor *color = [UIColor colorWithRed:redValue
                                     green:greenValue
                                      blue:blueValue
                                     alpha:1.0];
    
    // Assign it to the current canvasViewController
    // 3. 更改CanvasViewController中线的颜色
    CoordinatingController *coordinator = [CoordinatingController sharedInstance];
    CanvasViewController *controller = [coordinator canvasViewController];
    [controller setStrokeColor:color];
    
    
    
    // Forward a post update message
    
    // 4. 转发更新成功的消息 - 让适配器 （协议方法或闭包作出相应更改）
    // 4.1 Delegation approach:
    [delegate_ command:self didFinishColorUpdateWithColor:color];
    
    // 4.2. Block approach:
    if (postColorUpdateProvider_ != nil)
    {
        postColorUpdateProvider_(color);
    }
}

- (void) dealloc
{
  [RGBValuesProvider_ release];
  [postColorUpdateProvider_ release];
  [super dealloc];
}

@end
