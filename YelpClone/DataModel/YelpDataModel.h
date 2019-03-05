//
//  YelpDataModel.h
//  YelpClone
//
//  Created by Shouting Lyu on 2/27/19.
//  Copyright © 2019 Shouting Lyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface YelpDataModel : NSObject

+ (NSArray <YelpDataModel *>*)buildDataModelArrayFromDictionaryArray:(NSArray<NSDictionary *> *)dictArray;

@property (nonatomic, strong) NSString *businessId;
@property (nonatomic, assign) NSInteger reviewCount;
@property (nonatomic, strong) NSString *categories;

@property (nonatomic, strong) UIImage *ratingImage;

@property (nonatomic, strong) NSString *displayPhone;
@property (nonatomic, strong) NSString *imageUrl;
@property (nonatomic, strong) NSString *price;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *displayAddress;

@property (nonatomic, assign) CGFloat distance;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, assign) CGFloat latitude;
@property (nonatomic, assign) CGFloat longitude;

- (id)initWithDictionary:(NSDictionary *)dictionary;
@end
