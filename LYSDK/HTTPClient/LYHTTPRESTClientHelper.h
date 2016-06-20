//
//  LYHTTPRESTClientHelper.h
//  LYSDK
//
//  Created by luoyang on 16/5/27.
//  Copyright © 2016年 leroy. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LYHTTPMethod) {
    lyHttpMethod_POST = 0,
    lyHttpMethod_PUT = 1,
    lyHttpMethod_GET = 2,
    lyHttpMethod_Delete = 3,
};

typedef NS_ENUM(NSInteger, LYHTTPStatus) {
    lyHTTPStatus_SUCCESS_OK = 200,
    lyHTTPStatus_SUCCESS_NO_CONTENT = 204,
    lyHTTPStatus_NOT_AUTH = 401,
    lyHTTPStatus_FORBIDDEN = 403,
};

@interface LYHTTPRESTClientHelper : NSObject

+(void) setEndpoint:(NSString *) endpoint;
+(NSString *) getV1URL:(NSString *) path;
+(NSMutableDictionary *) getHeaderWithToken:(NSString *) token UCID:(NSString *) ucid body:(BOOL) hasBody;

@end
