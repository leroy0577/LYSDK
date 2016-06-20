//
//  LYHTTPRESTClientHelper.m
//  LYSDK
//
//  Created by luoyang on 16/5/27.
//  Copyright © 2016年 leroy. All rights reserved.
//

#import "LYHTTPRESTClientHelper.h"

@implementation LYHTTPRESTClientHelper

#define NVHEADER_TOKEN_NAME @"x-nvs-token"
#define NVHEADER_UCID_NAME @"x-nvs-ucid"
#define NVHEADER_CONTENT_TYPE_NAME @"content-type"
#define NVHEADER_CONTENT_TYPE_JSON_VALUE @"application/json"
#define NVHEADER_ACCEPT_NAME @"accept"
#define NVHEADER_ACCEPT_JSON_VALUE @"application/json"
#define NVHEADER_CACHE_NAME @"Cache-Control"
#define NVHEADER_CACHE_VALUE @"no-cache"

static NSString *ENDPOINT = @"https://nvweb.nvts.co";
static NSString *TESTPOINT = @"https://test.nvts.co";

+(void)setEndpoint:(NSString *)endpoint {
    if(endpoint) {
        ENDPOINT = endpoint;
    }
}

+(NSString *)getV1URL:(NSString *)path {
    
    NSString *url = [NSString stringWithFormat:@"%@/v1%@", ENDPOINT, path];
    NSString *encodedValue;
    if (!IOS9)
    {
        encodedValue = [url stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    }
    else {
        encodedValue = [url stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet characterSetWithCharactersInString:@"`#%^{}\"[]|\\<> "].invertedSet];
    }
    
    
    
    return encodedValue;
}

+(NSMutableDictionary *)getHeaderWithToken:(NSString *)token UCID:(NSString *)ucid body:(BOOL)hasBody {
    NSMutableDictionary *ret = [[NSMutableDictionary alloc] init];
    if(nil != ucid) {
        [ret setValue:ucid forKey:NVHEADER_UCID_NAME];
    }
    if(nil != token) {
        [ret setValue:token forKey:NVHEADER_TOKEN_NAME];
    }
    if(hasBody) {
        [ret setValue:NVHEADER_CONTENT_TYPE_JSON_VALUE forKey:NVHEADER_CONTENT_TYPE_NAME];
    }
    // TODO - set date
    
    [ret setValue:NVHEADER_CACHE_VALUE forKey:NVHEADER_CACHE_NAME];
    return ret;
}

@end

