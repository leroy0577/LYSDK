//
//  LYModel.h
//  LYSDK
//
//  Created by luoyang on 16/5/27.
//  Copyright © 2016年 leroy. All rights reserved.
//

#import <Mantle/Mantle.h>

typedef NS_ENUM(NSInteger, LYAPIReturnResult) {
    LYAPIReturnResultOK = 0,
    LYAPIReturnResultERR_ILYAILD_PARAM = 1,
    LYAPIReturnResultERR_USER_NOT_EXISTS = 2,
    LYAPIReturnResultERR_USERNAME_ALREADY_EXISTS = 3,
    LYAPIReturnResultERR_EMAIL_ALREADY_EXISTS = 4,
    LYAPIReturnResultERR_USER_PW_NOT_MATCH = 5,
    LYAPIReturnResultERR_ACTION_NOT_SUPPORT = 6,
    LYAPIReturnResultERR_SEED_TIMEOUT = 7,
    LYAPIReturnResultERR_SEED_HASH_NOT_MATCH = 8,
    LYAPIReturnResultERR_SERVER_INTERNAL_ERROR = 9,
    LYAPIReturnResultERR_ALREADY_FRIENDS = 10,
    LYAPIReturnResultERR_FACEBOOK_USER = 11,
    LYAPIReturnResultERR_DEVICE_ALREAD_REGISTERED_TO_ANOTHER_UESR = 12,
    LYAPIReturnResultERR_DEVICE_NOT_EXISTS = 13,
    LYAPIReturnResultERR_DEVICE_USER_NOT_MATCH = 14,
    LYAPIReturnResultERR_DEVICE_NOT_SHARE_TO_YOU = 15,
    LYAPIReturnResultERR_USER_NOT_AUTH_BY_SESSION = 16,
    LYAPIReturnResultERR_TCPLAN_IMPOSSIBLE = 17,
    LYAPIReturnResultERR_DEVICE_NOT_ONLINE = 18,
    LYAPIReturnResultERR_TRAN_SERVER_NOT_EXISTS = 19,
    LYAPIReturnResultERR_TRAN_SERVER_ALREADY_LOGIN = 20,
    LYAPIReturnResultERR_TRAN_SERVER_PASSWORD_NOT_MATCH = 21,
    LYAPIReturnResultERR_NO_TRAN_SERVER_AVAILABLE = 22,
    LYAPIReturnResultWARNING_RENRENUID_NOT_FOUND = 23,
    LYAPIReturnResultWARNING_FRIENDSHIP_ALREADY_EXISTS = 24,
    LYAPIReturnResultWARNING_FACEBOOKUID_NOT_FOUND = 25,
    LYAPIReturnResultERR_USER_EMAIL_NOT_MATCH = 26,
    LYAPIReturnResultERR_RECOVER_PASSWORD_TOO_OFTEN = 27,
    LYAPIReturnResultERR_DEVICE_ALREADY_REG_TO_THIS_USER = 28,
    LYAPIReturnResultERR_DEVICE_ALREADY_SHARE_TO_THIS_USER = 29,
    LYAPIReturnResultERR_DEVICE_CNANOT_SHARE_TO_OWNER = 30,
    LYAPIReturnResultERR_USER_TARGET_NOT_EXISTS = 31,
    LYAPIReturnResultERR_APP_NOT_EXISTS = 32,
    LYAPIReturnResultERR_APP_NOT_MATCH = 33,
    LYAPIReturnResultERR_APP_NOT_PERMITED = 34,
    LYAPIReturnResultERR_CLIENT_NOT_EXISTS = 35,
    LYAPIReturnResultERR_CLIENT_NOT_MATCH = 36,
    LYAPIReturnResultERR_PAIR_AUTH_FAILED = 37,
    LYAPIReturnResultERR_CAMERA_ALREADY_PAIRED = 38,
    LYAPIReturnResultERR_CAMERA_NOT_PAIRED = 39,
    LYAPIReturnResultERR_CONNECT_MQ_SERVER_ERROR = 40,
    LYAPIReturnResultERR_ILYITATION_CODE_ERROR = 41,
    LYAPIReturnResultERR_ILYALID_PACKET = 42,
    LYAPIReturnResultERR_SHARING_NOT_EXISTS = 43,
    LYAPIReturnResultERR_PASSWORD_RESET_CODE_ERROR = 44
};

@interface LYModel : MTLModel <MTLJSONSerializing>

@end