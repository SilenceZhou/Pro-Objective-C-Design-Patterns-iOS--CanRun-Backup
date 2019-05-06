//
//  CommandSlider.h
//  TouchPainter
//
//  Created by Carlo Chung on 11/9/10.
//  Copyright 2010 Carlo Chung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Command.h"

@interface CommandSlider : UISlider
{
  @protected
  Command *command_;
}

// 学习参考链接： https://www.jianshu.com/p/a43ee3dea26b
// xib 想连线object 需要只有该对象
@property (nonatomic, retain) IBOutlet Command *command;


@end
