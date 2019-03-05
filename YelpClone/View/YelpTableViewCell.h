//
//  YelpTableViewCell.h
//  YelpClone
//
//  Created by Shouting Lyu on 3/5/19.
//  Copyright © 2019 Shouting Lyu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YelpDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface YelpTableViewCell : UITableViewCell

- (void)updateBasedOnDataModel:(YelpDataModel *)dataModel;

@end

NS_ASSUME_NONNULL_END
