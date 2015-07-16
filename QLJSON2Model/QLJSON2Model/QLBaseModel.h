//
//  YQBaseModel.h
//  PengBei
//
//  Created by xuqianlong on 15/3/5.
//  Copyright (c) 2015年 夕阳栗子. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AnalyzeJSON2ModelProtocol <NSObject>

/**
 *  brief:  存放冲突key映射的字典 @{@"id":@"Newsid"}
 */
- (NSDictionary *)collideKeysMap;

/**
 *  brief:  存放冲突key映射Model的字典，@{@"courses":@"CourseModel"}
 */
- (NSDictionary *)collideKeyModelMap;

//如果需要进行值的转化，可以实现这个方法；比如：你想把一个String转为URL等
- (void)valueNeedTransfer;

@end

@interface QLBaseModel : NSObject <AnalyzeJSON2ModelProtocol>

/**
 *
 *  创建一个已经赋过值的model对像
 *
 *  @param dic 与 modle 属性对应的字典
 *
 */
+ (instancetype)instanceFormDic:(NSDictionary *)dic;

/**
 *  brief:  JSON数组--》model数组,if JSON is nil or empty return nil;
 */
+ (NSArray *)instanceArrFormArray:(NSArray *)arr;

//创建实例后用这个方法可以把字典里的值塞到model中，这个方法不会触发valueNeedTransfer方法；
- (void)assembleDataFormDic:(NSDictionary *)dic;

@end
