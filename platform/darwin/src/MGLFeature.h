#import <Foundation/Foundation.h>

#import "MGLPolyline.h"
#import "MGLPolygon.h"
#import "MGLPointAnnotation.h"
#import "MGLShapeCollection.h"

#import "MGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The `MGLFeature` protocol is used to provide details about geographic features
 contained in a map view’s vector tile sources. Each concrete subclass of
 `MGLShape` in turn has a subclass that conforms to this protocol.
 
 Typically, you do not create feature objects yourself but rather obtain them
 using `-[MGLMapView visibleFeaturesAtPoint:]` and related methods. Each feature
 object associates a shape with an identifier and attributes as specified by the
 source. Like any `MGLAnnotation` object, an `MGLFeature` object can be added to
 a map view using `-[MGLMapView addAnnotations:]` and related methods.
 */
@protocol MGLFeature <MGLAnnotation>

/**
 An `NSNumber` object that uniquely identifies the feature in its vector tile
 source.
 
 The identifier corresponds to the
 <a href="https://github.com/mapbox/vector-tile-spec/tree/master/2.1#42-features">feature identifier</a>
 (`id`) in the vector tile source. If the source does not specify the feature’s
 identifier, the value of this property is `nil`.
 
 For details about the identifiers used in most of Mapbox-provided styles,
 consult the
 <a href="https://www.mapbox.com/vector-tiles/mapbox-streets/">Mapbox Streets</a>
 layer reference.
 */
@property (nonatomic, copy, nullable, readonly) id identifier;

/**
 A dictionary of attributes specified by the vector tile source for this
 feature.
 
 The keys and values of this dictionary are determined by the vector tile
 source. Vector tiles are stored in <a href="http://geojson.org/">GeoJSON</a>
 format; they additionally conform to the
 <a href="https://www.mapbox.com/vector-tiles/specification/">Mapbox Vector Tile Specification</a>.
 The types defined in those specifications are mapped instances of the following
 Foundation types:
 
 <table>
 <thead>
 <tr><th>In the vector tile</th><th>In this dictionary</th></tr>
 </thead>
 <tbody>
 <tr><td>Null</td>                  <td><code>NSNull</code></td></tr>
 <tr><td>Boolean</td>               <td><code>NSNumber</code> (use the <code>boolValue</code> property)</td></tr>
 <tr><td>Integer</td>               <td><code>NSNumber</code> (use the <code>unsignedLongLongValue</code> or <code>longLongValue</code> property)</td></tr>
 <tr><td>Floating-point number</td> <td><code>NSNumber</code> (use the <code>doubleValue</code> property)</td></tr>
 <tr><td>String</td>                <td><code>NSString</code></td></tr>
 </tbody>
 </table>
 
 For details about the attribute names and values found in Mapbox-provided
 vector tile sources, consult the
 <a href="https://www.mapbox.com/vector-tiles/mapbox-streets/">Mapbox Streets</a>
 and
 <a href="https://www.mapbox.com/vector-tiles/mapbox-terrain/">Mapbox Terrain</a>
 layer references.
 */
@property (nonatomic, copy, readonly) NS_DICTIONARY_OF(NSString *, id) *attributes;

/**
 Returns the feature attribute for the given key.
 
 See the `attributes` property’s documentation for details on keys and values
 associated with this method.
 */
- (nullable id)attributeForKey:(NSString *)key;

@end

/**
 The `MGLPointFeature` class represents a point in a vector tile source.
 */
@interface MGLPointFeature : MGLPointAnnotation <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) id identifier;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *attributes;

@end

/**
 The `MGLPolylineFeature` class represents a polyline in a vector tile source.
 */
@interface MGLPolylineFeature : MGLPolyline <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) id identifier;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *attributes;

@end

/**
 The `MGLPolygonFeature` class represents a polygon in a vector tile source.
 */
@interface MGLPolygonFeature : MGLPolygon <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) id identifier;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *attributes;

@end

/**
 The `MGLMultiPointFeature` class represents a multipoint in a vector tile
 source.
 */
@interface MGLMultiPointFeature : MGLMultiPoint <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) id identifier;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *attributes;

@end

/**
 The `MGLMultiPolylineFeature` class represents a multipolyline in a vector tile
 source.
 */
@interface MGLMultiPolylineFeature : MGLMultiPolyline <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) id identifier;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *attributes;

@end

/**
 The `MGLMultiPolygonFeature` class represents a multipolygon in a vector tile
 source.
 */
@interface MGLMultiPolygonFeature : MGLMultiPolygon <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) id identifier;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *attributes;

@end

/**
 The `MGLShapeCollectionFeature` class represents a shape collection in a vector
 tile source.
 */
@interface MGLShapeCollectionFeature : MGLShapeCollection <MGLFeature>

@property (nonatomic, copy, nullable, readwrite) id identifier;
@property (nonatomic, copy, readwrite) NS_DICTIONARY_OF(NSString *, id) *attributes;

@end

NS_ASSUME_NONNULL_END
