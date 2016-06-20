//
//  LYHTTPRestClient.m
//  LYSDK
//
//  Created by luoyang on 16/5/27.
//  Copyright © 2016年 leroy. All rights reserved.
//

#import "LYHTTPRestClient.h"
#import "LYAPIModel.h"
#import "LYHTTPRESTClientHelper.h"
#import <AFNetworking/AFNetworking.h>

@implementation LYHTTPRestClient

-(id)getBlockResult:(id)instance block:(void (^)(id))block {
    if(block) {
        block(instance);
    }
    return instance;
}

-(BOOL) getBlockResponse:(NSHTTPURLResponse *) response andOK:(Class) okClass andBlock:(void (^)(id, id)) block {
    NSLog(@"Code:%ld,\nBody:%@", (long)response.statusCode, [[NSString alloc] initWithData:(NSData *)response encoding:NSUTF8StringEncoding]);
    LYRestAPICommonResultResponse *responseErr = nil;
    LYAPIModel *responseOK = nil;
    if(response) {
        if(lyHTTPStatus_SUCCESS_OK == response.statusCode && okClass) {
            responseOK = [MTLJSONAdapter modelOfClass:okClass fromJSONDictionary:[NSJSONSerialization JSONObjectWithData:(NSData *)response options:NSJSONReadingMutableContainers | NSJSONReadingMutableLeaves error:nil] error:nil];
        } else if(lyHTTPStatus_SUCCESS_NO_CONTENT == response.statusCode && !okClass) {
            // ok
        } else if(lyHTTPStatus_NOT_AUTH == response.statusCode || 0 == response.statusCode) {
            responseErr = [[LYRestAPICommonResultResponse alloc] initWithCode:LYRestAPIReturnCodeTokenInvalid andResult:0];
        } else {
            responseErr = [MTLJSONAdapter modelOfClass:[LYRestAPICommonResultResponse class] fromJSONDictionary:[NSJSONSerialization JSONObjectWithData:(NSData *)response options:NSJSONReadingMutableContainers | NSJSONReadingMutableLeaves error:nil] error:nil];
            responseErr.code = LYRestAPIReturnCodeBusinessError;
        }
    } else {
        responseErr = [[LYRestAPICommonResultResponse alloc] initWithCode:LYRestAPIReturnCodeBusinessError andResult:0];
    }
    
    if(block) {
        block(responseOK, responseErr);
    }
    
    return responseErr==nil;
}


-(BOOL)createUserToken:(LYRestAPICreateUserTokenRequestBlock)configRequest response:(LYRestAPICreateUserTokenResponseBlock)returnResponse {
    
    LYRestAPICreateUserTokenRequest *request = [self getBlockResult:[[LYRestAPICreateUserTokenRequest alloc] init] block:configRequest];
    [MTLJSONAdapter JSONDictionaryFromModel:request error:nil];
    
    NSString *URLString = [LYHTTPRESTClientHelper getV1URL:@"test"];
    NSDictionary *parameters = [MTLJSONAdapter JSONDictionaryFromModel:request error:nil];
    __block NSHTTPURLResponse *response;
    
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.responseSerializer = [AFHTTPResponseSerializer serializer];
    
    [manager POST:URLString parameters:parameters constructingBodyWithBlock:^(id<AFMultipartFormData>  _Nonnull formData) {
        
    } progress:^(NSProgress * _Nonnull uploadProgress) {
        
    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        
        response = responseObject;
        
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        
    }];
    
    return [self getBlockResponse:response andOK:nil andBlock:returnResponse];
}

@end
