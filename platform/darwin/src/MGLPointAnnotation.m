#import "MGLPointAnnotation.h"

@implementation MGLPointAnnotation

@synthesize coordinate;

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@: %p; title = %@; subtitle = %@; coordinate = %f, %f>",
            NSStringFromClass([self class]), (void *)self,
            self.title ? [NSString stringWithFormat:@"\"%@\"", self.title] : self.title,
            self.subtitle ? [NSString stringWithFormat:@"\"%@\"", self.subtitle] : self.subtitle,
            coordinate.latitude, coordinate.longitude];
}

@end

@implementation MGLPointFeature

- (id)objectForKey:(NSString *)attribute {
    return self.featureAttributes[attribute];
}

@end

@implementation MGLGeometryCollection

+ (instancetype)geometryCollectionWithGeometries:(NS_ARRAY_OF(id<MGLAnnotation>) *)geometries {
    return [[self alloc] init];
}

- (instancetype)initWithGeometries:(NS_ARRAY_OF(id<MGLAnnotation>) *)geometries {
    if (self = [super init]) {
        NSAssert(geometries.count, @"Cannot create an empty geometry collection");
        _geometries = geometries;
    }
    return self;
}

- (CLLocationCoordinate2D)coordinate {
    return _geometries.firstObject.coordinate;
}

@end

@implementation MGLGeometryCollectionFeature

- (id)objectForKey:(NSString *)attribute {
    return self.featureAttributes[attribute];
}

@end
