//
//  VEExportConfiguration.h
//  VEENUMCONFIGER
//
//  Created by iOS VESDK Team on 2021/1/13.
//

#import <Foundation/Foundation.h>

/**水印位置
 */
typedef NS_ENUM(NSInteger,VEWatermarkPosition){
    VEWatermarkPosition_leftTop,
    VEWatermarkPosition_rightTop,
    VEWatermarkPosition_leftBottom,
    VEWatermarkPosition_rightBottom
};

//转码需要导出的文件方式，暂时只针对编码使用，其他功能选择默认  2022.07.20
typedef NS_ENUM(NSInteger, ExportFileType) {
    ExportFileTypeDefault = 0,        //默认,什么也不做
    ExportFileTypeAlbum,  //相册
    ExportFileTypeFile,    //文件
};
#pragma mark - 片尾
@interface VEEndingMedia : NSObject

/** 资源地址
 */
@property (nonatomic, copy) NSString *path;

/** 显示时长
 */
@property (nonatomic, assign) float duration;

/** 是否改变虚拟视频的时间线，默认为YES
 */
@property (nonatomic, assign) BOOL isChangeTimeline;

@end

@interface VEExportConfiguration : NSObject<NSMutableCopying,NSCopying>

#pragma mark- 设置视频水印和码率

/** 设置视频输出最大时长 (单位是秒) 不限制则传0，默认不限制
 */
@property (nonatomic,assign)long int   outputVideoMaxDuration;
/** 设置视频输入最大时长 (单位是秒) 不限制则传0，默认不限制
 */
@property (nonatomic,assign)long int   inputVideoMaxDuration;
/** 是否禁用片尾，(default true)
 */
@property (nonatomic,assign)bool    endingMediaDisabled;

/** 片尾，使用该接口后，endPic相关接口无效
 */
@property (nonatomic, strong) VEEndingMedia *endingMedia;

/** 片尾显示的用户名
 */
@property (nonatomic,copy)NSString * endPicUserName;
/** 片尾显示时长（不包括淡入时长）
 */
@property (nonatomic,assign)float    endPicDuration;
/** 片尾淡入时长
 */
@property (nonatomic,assign)float    endPicFadeDuration;
/** 片尾显示的图片路径
 */
@property (nonatomic,copy)NSString * endPicImagepath;

/** 设置视频输出码率 (单位是兆,默认是6M),建议设置大于1M，导出和压缩都生效
 */
@property (nonatomic,assign)float   videoBitRate;
/**压缩视频分辨率（调用压缩视频接口生效）
 */
@property (nonatomic,assign)CGSize  condenseVideoResolutionRatio;
/** 导出视频声道 (默认为2 双声道)
 */
@property (nonatomic,assign)int    audioChannelNumbers;
/** 是否禁用水印(default true)
 */
@property (nonatomic,assign) bool watermarkDisabled;
/** 是否可删除水印(default true)
 */
@property (nonatomic,assign) bool isCanDeleteWatermark;
/** 图片水印
 */
@property (nonatomic,strong) UIImage *watermarkImage DEPRECATED_MSG_ATTRIBUTE("Use watermarkImagePath instead.");
/** 图片水印地址
 */
@property (nonatomic,strong) NSString *watermarkImagePath;
/** 显示位置
 */
@property (nonatomic,assign)VEWatermarkPosition watermarkPosition;

/** 是否可以导出模板，(default false)
 */
@property (nonatomic,assign) bool enableExportTemplate;

/** 是否默认导出GIF，(default false)
 */
@property (nonatomic,assign) bool isDefaultExportGif;

/** 上传模板网络资源地址
 */
@property (nonatomic,copy)NSString *uploadTemplatePath;

/** 新建模板分类地址
 */
@property (nonatomic,copy)NSString *createTemplateCategoryPath;

/** 上传封面模板网络资源地址
 */
@property (nonatomic,copy)NSString *uploadCoverTemplatePath;

/** 新建封面模板分类地址
 */
@property (nonatomic,copy)NSString *createCoverTemplateCategoryPath;

/** 导出模板中分片段，(default false)
 */
@property (nonatomic,assign) bool enableTemplateFragment;

/** 上传草稿云备份网络资源地址
 */
@property (nonatomic,copy)NSString *uploadCloudBackupPath;

/** 更新草稿云备份网络资源地址
 */
@property (nonatomic,copy)NSString *updateCloudBackupPath;

/** 删除草稿云备份网络资源地址
 */
@property (nonatomic,copy)NSString *deleteCloudBackupPath;

/** 获取草稿云备份列表网络资源地址
 */
@property (nonatomic,copy)NSString *cloudBackupListPath;

/** 草稿云备份的用户唯一ID
 */
@property (nonatomic,copy)NSString *userUniqueId;
/** 草稿云备份的分类（图片编辑，图片流动）
 */
@property (nonatomic,copy)NSString *cloudType;

/** 是否可以设置导出参数，(default true)
 */
@property (nonatomic,assign) bool enableSetExportParams;

//编码添加导出文件方式 2022.07.20
@property (assign, assign)ExportFileType exportFileType;

/** 是否禁用片尾，(default true)
 */
@property (nonatomic,assign)bool    endPicDisabled DEPRECATED_MSG_ATTRIBUTE("Use endingMediaDisabled instead.");

/** 是否禁用水印(default true)
 */
@property (nonatomic,assign)bool     waterDisabled DEPRECATED_MSG_ATTRIBUTE("Use watermarkDisabled instead.");
/** 文字水印
 */
@property (nonatomic,copy)NSString *waterText DEPRECATED_MSG_ATTRIBUTE("Use watermarkImage instead.");
/** 图片水印
 */
@property (nonatomic,strong)UIImage *waterImage DEPRECATED_MSG_ATTRIBUTE("Use watermarkImage instead.");
/** 显示位置
 */
@property (nonatomic,assign)VEWatermarkPosition  waterPosition DEPRECATED_MSG_ATTRIBUTE("Use watermarkPosition instead.");



@end
