#import <Foundation/Foundation.h>

#import "MGLShape.h"

#import "MGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

@interface MGLShapeCollection : MGLShape

@property (nonatomic, copy) NS_ARRAY_OF(MGLShape <MGLAnnotation> *) *shapes;

+ (instancetype)shapeCollectionWithShapes:(NS_ARRAY_OF(MGLShape <MGLAnnotation> *) *)shapes;

@end

NS_ASSUME_NONNULL_END
