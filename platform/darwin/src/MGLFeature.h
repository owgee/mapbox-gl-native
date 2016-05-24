#import <Foundation/Foundation.h>

#import "MGLAnnotation.h"

#import "MGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MGLFeature <MGLAnnotation>

@property (nonatomic, copy, nullable, readonly) NSNumber *featureTag;
@property (nonatomic, copy, readonly) NS_DICTIONARY_OF(NSString *, id) *featureAttributes;

- (nullable id)objectForKey:(NSString *)attribute;

@end

NS_ASSUME_NONNULL_END
