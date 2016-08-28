//
//  MCCommonClass.h
//  CommonClass
//
//  Created by mac on 16/8/26.
//  Copyright © 2016年 GMC. All rights reserved.
//

#ifndef MCCommonClass_h
#define MCCommonClass_h

/**
 *  ARC与非ARC
 */
#if __has_feature(objc_arc)


//--------------------------------屏幕宽度与高度---------------------------------
/**
 *  获取屏幕宽度与高度
 */
#define SCREEN_WIDTH    [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT   [UIScreen mainScreen].bounds.size.height

//--------------------------------屏幕宽度与高度---------------------------------


//-----------------------------------通知中心-----------------------------------
/**
 *  获取通知中心
 */

#define MCNotificationCenter [NSNotificationCenter defaultCenter]
//-----------------------------------通知中心-----------------------------------




//-----------------------------------打印日志-----------------------------------
/**
 *  打印LOG
 */
#ifdef DEBUG
#define MCLog(...) NSLog (@"%s 第%d行 %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define MCLog(...)
#endif

//------------------------------------打印日志-----------------------------------





//------------------------------------强/弱引用-----------------------------------

/**
 *  弱引用/强引用
 */
#define MCWeakSelf(type)    __weak typeof(type) weak##type = type;
#define MCStrongSelf(type)  __strong typeof(type) type = weak##type;

//---------------------------------强/弱引用---------------------------------




//------------------------------------颜色------------------------------------

/**
 *  设置随机颜色
 */
#define MCRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0f green:arc4random_uniform(256)/255.0f blue:arc4random_uniform(256)/255.0f alpha:1.0] 
/**
 *  设置RGB颜色/设置RGBA颜色/无色
 */
#define MCRGBColor (r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1.0f]
#define MCRGBAColor (r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define  MCClearColor [UIColor clearColor]

//---------------------------------颜色---------------------------------





//---------------------------------系统---------------------------------
/**
 *  系统版本
 */
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion [[UIDevice currentDevice] systemVersion]
/**
 *  当前语言
 */
#define CurrentLanguage [[NSLocale preferredLanguages] objectAtIndex:0]

/**
 * 获取temp
 */
#define kPathTemp NSTemporaryDirectory()

/**
 * 获取沙盒Document
 */
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject]
/**
 *  获取沙盒 Cache
 */
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]
//---------------------------------系统---------------------------------





//---------------------------------图片-----------------------------------
/**
 *  读取本地图片
 */
#define LOADIMAGE (file，ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:file ofType:ext]]
/**
 *  定义UIImage对象
 */
#define IMAGE(a) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:a ofType:nil]]


//建议使用前两种宏定义，性能高于后者
//---------------------------------图片-----------------------------------


//---------------------------------角度弧度互转---------------------------------

#define MCDegeressToRadian (x) (M_PI *(x)/180.0)
#define MCRadianToDegrees (radian) (radian *180.0)/(M_PI)

//---------------------------------角度弧度互转---------------------------------



//---------------------------------iphone设备---------------------------------
/**
 *  判断是否为iphone
 */
#define IS_ISPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

/**
 *  判断是否为ipod
 */
#define IS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])
/**
 *  判断是否为iphone5SE/iphone5/iphone5S
 */
#define iPhone5_5s ([[UIScreen mainScreen] bounds].size.width ==320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f)
/**
 *  判断是否为iPhone6/6S
 */
#define iPhone6_6s ([[UIScreen mainScreen] bounds].size.width ==375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f)
/**
 *  判断是否为iPhone6 plus/6S plus
 */
#define iPhone6plus_6splus ([[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f)

//---------------------------------iphone设备---------------------------------

#else
//非ARC


#endif


#endif /* MCCommonClass_h */
