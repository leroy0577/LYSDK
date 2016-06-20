//
//  LYAPIModel.h
//  LYSDK
//
//  Created by luoyang on 16/5/27.
//  Copyright © 2016年 leroy. All rights reserved.
//

#import "LYModel.h"

@interface LYAPIModel : LYModel

@end


typedef NS_ENUM(NSInteger, LYRestAPIReturnCode) {
    LYRestAPIReturnCodeTokenInvalid = 401,//Direct prompted to log in again
    LYRestAPIReturnCodeCredentialInvalid = 403,//Re-enter the password directly Tips
    LYRestAPIReturnCodeNetworkError = 450,//Network reasons directly Tips
    LYRestAPIReturnCodeBusinessError = 451,//Return the results to determine the type of response is returned results
    LYRestAPIReturnCodeUnknown = 460,//Unknown error type direct assertion
};
#pragma mark - Request

@interface LYRestAPICreateUserTokenRequest : LYAPIModel

@property(nonatomic, copy) NSString *user;
@property(nonatomic, copy) NSString *pass;
@property(nonatomic, copy) NSString *udid;

-(void) initWithUser:(NSString *) user andPass:(NSString *) pass andUDID:(NSString *) udid;

@end


#pragma mark - Response

@interface LYRestAPICommonResultResponse : LYAPIModel

@property(nonatomic, assign) LYRestAPIReturnCode code;
@property(nonatomic, assign) LYAPIReturnResult result;

-(id) initWithCode:(LYRestAPIReturnCode) code andResult:(LYAPIReturnResult) result;

@end

@interface LYRestAPICreateUserTokenResponse : LYAPIModel

@property(nonatomic, copy) NSString *token;
@property(nonatomic, assign) long long userid;
@property(nonatomic, assign) long long expires;
@property(nonatomic, copy) NSString *email;

@end
