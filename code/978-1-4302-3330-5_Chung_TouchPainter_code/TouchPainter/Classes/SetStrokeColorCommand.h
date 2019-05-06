//
//  StrokeColorCommand.h
//  TouchPainter
//
//  Created by Carlo Chung on 11/9/10.
//  Copyright 2010 Carlo Chung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Command.h"

typedef void (^RGBValuesProvider)(CGFloat *red, CGFloat *green, CGFloat *blue);
typedef void (^PostColorUpdateProvider)(UIColor *color);

@class SetStrokeColorCommand;

@protocol SetStrokeColorCommandDelegate

- (void) command:(SetStrokeColorCommand *) command 
                didRequestColorComponentsForRed:(CGFloat *) red
                                          green:(CGFloat *) green 
                                           blue:(CGFloat *) blue;

- (void) command:(SetStrokeColorCommand *) command
                didFinishColorUpdateWithColor:(UIColor *) color;

@end


@interface SetStrokeColorCommand : Command
{
  @private
    // 这个地方，已经通过xib建立过联系了
  id <SetStrokeColorCommandDelegate> delegate_;  
  RGBValuesProvider RGBValuesProvider_;
  PostColorUpdateProvider postColorUpdateProvider_;
}

@property (nonatomic, assign) id <SetStrokeColorCommandDelegate> delegate;
@property (nonatomic, copy) RGBValuesProvider RGBValuesProvider;
@property (nonatomic, copy) PostColorUpdateProvider postColorUpdateProvider;

- (void) execute;

@end
