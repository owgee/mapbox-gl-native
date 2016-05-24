#import "MGLFeature.h"
#import "MGLShape.h"

#import <mbgl/util/geo.hpp>
#import <mbgl/util/feature.hpp>

MGLShape <MGLFeature> * MGLFeatureFromMBGLFeature(const mbgl::Feature &feature);
