#import <Foundation/Foundation.h>

#import "MGLPolyline.h"
#import "MGLPolygon.h"
#import "MGLPointAnnotation.h"
#import "MGLShapeCollection.h"

#import "MGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MGLFeature <MGLAnnotation>

@property (nonatomic, copy, nullable, readonly) NSNumber *featureTag;
@property (nonatomic, copy, readonly) NS_DICTIONARY_OF(NSString *, id) *featureAttributes;

- (nullable id)objectForKey:(NSString *)attribute;

@end

@interface MGLPointFeature : MGLPointAnnotation <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) NSNumber *featureTag;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *featureAttributes;

@end

@interface MGLPolylineFeature : MGLPolyline <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) NSNumber *featureTag;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *featureAttributes;

@end

@interface MGLPolygonFeature : MGLPolygon <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) NSNumber *featureTag;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *featureAttributes;

@end

@interface MGLMultiPointFeature : MGLMultiPoint <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) NSNumber *featureTag;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *featureAttributes;

@end

@interface MGLMultiPolylineFeature : MGLMultiPolyline <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) NSNumber *featureTag;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *featureAttributes;

@end

@interface MGLMultiPolygonFeature : MGLMultiPolygon <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) NSNumber *featureTag;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *featureAttributes;

@end

@interface MGLShapeCollectionFeature : MGLShapeCollection <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) NSNumber *featureTag;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *featureAttributes;

@end

NS_ASSUME_NONNULL_END
