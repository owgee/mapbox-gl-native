#import "MBXAnnotationView.h"

@interface MBXAnnotationView ()

@property (nonatomic) UIView *centerView;

@end

@implementation MBXAnnotationView

- (void)layoutSubviews {
    [super layoutSubviews];
    if (!self.centerView) {
        self.backgroundColor = [UIColor blueColor];
        self.centerView = [[UIView alloc] initWithFrame:CGRectInset(self.bounds, 5.0, 5.0)];
        self.centerView.backgroundColor = self.centerColor;
        
        [self addSubview:self.centerView];
        
        UIView *borderView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(self.frame), 15)];
        borderView.backgroundColor = [UIColor purpleColor];
        [self addSubview:borderView];
    }
}

- (void)setCenterColor:(UIColor *)centerColor {
    if (![_centerColor isEqual:centerColor]) {
        _centerColor = centerColor;
        self.centerView.backgroundColor = centerColor;
    }
}

@end
