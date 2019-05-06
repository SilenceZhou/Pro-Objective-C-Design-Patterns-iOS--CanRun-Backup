//
//  CanvasViewGenerator.h
//  TouchPainter
//
//  Created by Carlo Chung on 10/16/10.
//  Copyright 2010 Carlo Chung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CanvasView.h"


/**
 工厂设计模式 CanvasViewGenerator 为类簇
 */
@interface CanvasViewGenerator : NSObject
{

}

- (CanvasView *) canvasViewWithFrame:(CGRect) aFrame;


@end
