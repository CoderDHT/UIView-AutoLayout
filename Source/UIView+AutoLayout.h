//
//  UIView+AutoLayout.h
//  Copyright (c) 2013 Tyler Fox
//  https://github.com/smileyborg/UIView-AutoLayout
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ALEdge) {
    ALEdgeTop = 0,      // the top edge of the view
    ALEdgeLeft,         // the left edge of the view
    ALEdgeBottom,       // the bottom edge of the view
    ALEdgeRight         // the right edge of the view
};

typedef NS_ENUM(NSInteger, ALAxis) {
    ALAxisHorizontal = 0,   // a horizontal line through the center of the view
    ALAxisVertical,         // a vertical line through the center of the view
    ALAxisBaseline          // a horizontal line at the text baseline (not applicable to all views)
};

typedef NS_ENUM(NSInteger, ALDimension) {
    ALDimensionWidth = 0,   // the width of the view
    ALDimensionHeight       // the height of the view
};


#pragma mark - UIView+AutoLayout

/**
 A category on UIView that provides a simpler semantic interface for creating Auto Layout constraints.
 */
@interface UIView (AutoLayout)


#pragma mark Factory & Initializer Methods

/** Creates and returns a new view that does not convert autoresizing masks into constraints. */
+ (id)newAutoLayoutView;

/** Initializes and returns a new view that does not convert autoresizing masks into constraints. */
- (id)initForAutoLayout;


#pragma mark Auto Layout Convenience Methods

/** Removes the given constraint from the view it has been added to. */
+ (void)removeConstraint:(NSLayoutConstraint *)constraint;
/** Removes the given constraints from the views they have been added to. */
+ (void)removeConstraints:(NSArray *)constraints;

/** Centers the view in its superview. */
- (NSArray *)autoCenterInSuperview;
/** Centers the view along the given axis (horizontal or vertical) within its superview. */
- (NSLayoutConstraint *)autoCenterInSuperviewAlongAxis:(ALAxis)axis;

/** Pins the given center axis of the view to a fixed position (X or Y value, depending on axis) in the superview. */
- (NSLayoutConstraint *)autoPinCenterAxis:(ALAxis)axis toPositionInSuperview:(CGFloat)value;
/** Pins the given edge of the view to a fixed position (X or Y value, depending on edge) in the superview. */
- (NSLayoutConstraint *)autoPinEdge:(ALEdge)edge toPositionInSuperview:(CGFloat)value;

/** Pins the given edge of the view to the same edge of the superview with an inset. */
- (NSLayoutConstraint *)autoPinEdgeToSuperviewEdge:(ALEdge)edge withInset:(CGFloat)inset;
/** Pins the edges of the view to the edges of its superview with the given edge insets. */
- (NSArray *)autoPinEdgesToSuperviewEdgesWithInsets:(UIEdgeInsets)insets;

/** Pins an edge of the view to a given edge of another view. */
- (NSLayoutConstraint *)autoPinEdge:(ALEdge)edge toEdge:(ALEdge)toEdge ofView:(UIView *)peerView;
/** Pins an edge of the view to a given edge of another view with an offset. */
- (NSLayoutConstraint *)autoPinEdge:(ALEdge)edge toEdge:(ALEdge)toEdge ofView:(UIView *)peerView withOffset:(CGFloat)offset;
/** Pins an edge of the view to a given edge of another view with an offset as a maximum or minimum. */
- (NSLayoutConstraint *)autoPinEdge:(ALEdge)edge toEdge:(ALEdge)toEdge ofView:(UIView *)peerView withOffset:(CGFloat)offset relation:(NSLayoutRelation)relation;

/** Aligns an axis of the view to the same axis of another view. */
- (NSLayoutConstraint *)autoAlignAxis:(ALAxis)axis toSameAxisOfView:(UIView *)peerView;
/** Aligns an axis of the view to the same axis of another view with an offset. */
- (NSLayoutConstraint *)autoAlignAxis:(ALAxis)axis toSameAxisOfView:(UIView *)peerView withOffset:(CGFloat)offset;

/** Matches a dimension of the view to a given dimension of another view. */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(UIView *)peerView;
/** Matches a dimension of the view to a given dimension of another view with an offset. */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(UIView *)peerView withOffset:(CGFloat)offset;
/** Matches a dimension of the view to a given dimension of another view with an offset as a maximum or minimum. */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(UIView *)peerView withOffset:(CGFloat)offset relation:(NSLayoutRelation)relation;
/** Matches a dimension of the view to a multiple of a given dimension of another view. */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(UIView *)peerView withMultiplier:(CGFloat)multiplier;
/** Matches a dimension of the view to a multiple of a given dimension of another view as a maximum or minimum. */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(UIView *)peerView withMultiplier:(CGFloat)multiplier relation:(NSLayoutRelation)relation;

/** Sets the view to a specific size. */
- (NSArray *)autoSetDimensionsToSize:(CGSize)size;
/** Sets the given dimension of the view to a specific size. */
- (NSLayoutConstraint *)autoSetDimension:(ALDimension)dimension toSize:(CGFloat)size;
/** Sets the given dimension of the view to a specific size as a maximum or minimum. */
- (NSLayoutConstraint *)autoSetDimension:(ALDimension)dimension toSize:(CGFloat)size relation:(NSLayoutRelation)relation;


#pragma mark Advanced Auto Layout Methods

/** Distributes the given subviews equally along the selected axis. Views will be the same size (variable) in the dimension along the axis and will have spacing (fixed) between them. */
- (NSArray *)autoDistributeSubviews:(NSArray *)views alongAxis:(ALAxis)axis withFixedSpacing:(CGFloat)spacing alignment:(NSLayoutFormatOptions)alignment;
/** Distributes the given subviews equally along the selected axis. Views will be the same size (fixed) in the dimension along the axis and will have spacing (variable) between them. */
- (NSArray *)autoDistributeSubviews:(NSArray *)views alongAxis:(ALAxis)axis withFixedSize:(CGFloat)size alignment:(NSLayoutFormatOptions)alignment;

@end


#pragma mark - NSLayoutConstraint+AutoLayout

/**
 A category on NSLayoutConstraint that allows constraints to easily removed.
 */
@interface NSLayoutConstraint (AutoLayout)

/** Removes the constraint from the view it has been added to. */
- (void)remove;

@end
