//
//  LYAPIModel.m
//  LYSDK
//
//  Created by luoyang on 16/5/27.
//  Copyright © 2016年 leroy. All rights reserved.
//

#import "LYAPIModel.h"

@implementation LYAPIModel

+(NSDictionary *)JSONKeyPathsByPropertyKey {
    return @{};
}

@end

#pragma mark - Request

@implementation LYRestAPICreateUserTokenRequest

+(NSDictionary *)JSONKeyPathsByPropertyKey {
    return @{
             @"user" : @"user",
             @"pass" : @"pass",
             @"udid" : @"udid",
             };
}

-(void)initWithUser:(NSString *)user andPass:(NSString *)pass andUDID:(NSString *)udid{
    self.user = user;
    self.pass = pass;
    self.udid = udid;
}

@end


#pragma mark - Response

@implementation LYRestAPICommonResultResponse

+(NSDictionary *)JSONKeyPathsByPropertyKey {
    return @{
             @"code" : NSNull.null,
             @"result" : @"ret",
             };
}

-(id) initWithCode:(LYRestAPIReturnCode)code andResult:(LYAPIReturnResult)result {
    self = [super init];
    if(self) {
        self.code = code;
        self.result = result;
    }
    return self;
}

@end

@implementation LYRestAPICreateUserTokenResponse
@synthesize token, userid, expires, email;

+(NSDictionary *)JSONKeyPathsByPropertyKey {
    return @{
             @"token" : @"token",
             @"userid" : @"userid",
             @"expires" : @"expires",
             @"email" : @"email",
             };
}

@end

