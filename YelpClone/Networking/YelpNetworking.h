//
//  YelpNetworking.h
//  YelpClone
//
//  Created by Shouting Lyu on 2/2/19.
//  Copyright © 2019 Shouting Lyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YelpDataModel.h"

@import CoreLocation;

typedef void (^RestaurantCompletionBlock)(NSArray <YelpDataModel *>* dataModelArray);

NS_ASSUME_NONNULL_BEGIN

@interface YelpNetworking : NSObject

+ (YelpNetworking *)sharedInstance;

- (void)fetchRestaurantsBasedOnLocation:(CLLocation *)location term:(NSString *)term completionBlock:(RestaurantCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
