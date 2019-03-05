//
//  YelpNetworking.m
//  YelpClone
//
//  Created by Shouting Lyu on 2/2/19.
//  Copyright © 2019 Shouting Lyu. All rights reserved.
//

#import "YelpNetworking.h"
#import <Foundation/Foundation.h>

static NSString const * kClient_secret = @"";


@implementation YelpNetworking

+ (YelpNetworking *)sharedInstance {
    static YelpNetworking *_sharedInstance = nil;
    static dispatch_once_t oncePredicate;
    
    dispatch_once(&oncePredicate, ^{
        _sharedInstance = [[YelpNetworking alloc] init];
    });
    return _sharedInstance;
    
}

- (void)fetchRestaurantsBasedOnLocation:(CLLocation *)location term:(NSString *)term completionBlock:(RestaurantCompletionBlock)completionBlock
{
    //TokenPendingTask tokenTask = ^(NSString *token) {
        NSString *string = [NSString stringWithFormat:@"https://api.yelp.com/v3/businesses/search?term=%@&latitude=%.6f&longitude=%.6f",term, location.coordinate.latitude, location.coordinate.longitude];
        NSURL *url = [NSURL URLWithString:string];
        
        NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url
                                                               cachePolicy:NSURLRequestUseProtocolCachePolicy
                                                           timeoutInterval:60.0];
        [request setHTTPMethod:@"GET"];
        NSString *headerToken = [NSString stringWithFormat:@"Bearer %@", kClient_secret];
        [request addValue:headerToken forHTTPHeaderField:@"Authorization"];
        NSURLSessionDataTask *dataTask = [[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
            NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:data options:NULL error:nil];
            if (!error) {
                completionBlock([YelpDataModel buildDataModelArrayFromDictionaryArray:dict[@"businesses"]]);
            }
        }];
        [dataTask resume];
}

@end
