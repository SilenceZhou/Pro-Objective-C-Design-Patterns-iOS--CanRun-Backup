//
//  ChasingGame.h
//  Builder
//
//  Created by Carlo Chung on 11/27/10.
//  Copyright 2010 Carlo Chung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StandardCharacterBuilder.h"

/**
 该类就是作者定义的Director
 
 整体思想是分离"什么"和"如何";
 让Director可以把一个规格(Character)应用到不同的Builder，而它懂得"如何"按照给定的规格建造自己的特定产品。
 
 笔者的理解：把生成一个对象进行步奏分解，便于后续复用
 解决表格从左到右：
 
 指引者    --->              构造器                           --->         具体实例
 Director                   Builder                                      charator
 
 ChasingGame           CharacterBuilder                                   具体角色
 获取构造器构造的实例     （规范：基础生成器,规定任何生成器都有那些API）
                        StandardCharacterBuilder
                        (具体生成器：把规范的API进行事项)
 */
@interface ChasingGame : NSObject

- (Character *) createPlayer:(CharacterBuilder *) builder;
- (Character *) createEnemy:(CharacterBuilder *) builder;

@end
