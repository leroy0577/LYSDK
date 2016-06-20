//
//  LYRestClient.h
//  LYSDK
//
//  Created by luoyang on 16/5/27.
//  Copyright © 2016年 leroy. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LYRestAPICommonResultResponse;
@class LYRestAPICreateUserTokenRequest;
@class LYRestAPICreateUserTokenResponse;

typedef void (^LYRestAPICommonResultResponseBlock)(LYRestAPICommonResultResponse *response);

typedef void (^LYRestAPICreateUserTokenRequestBlock)(LYRestAPICreateUserTokenRequest *request);
typedef void (^LYRestAPICreateUserTokenResponseBlock)(LYRestAPICreateUserTokenResponse *responseOK, LYRestAPICommonResultResponse *responseErr);

@protocol LYRestClient <NSObject>

//登录时创建用户信息
-(BOOL) createUserToken:(LYRestAPICreateUserTokenRequestBlock) configRequest response:(LYRestAPICreateUserTokenResponseBlock) returnResponse;

@end
