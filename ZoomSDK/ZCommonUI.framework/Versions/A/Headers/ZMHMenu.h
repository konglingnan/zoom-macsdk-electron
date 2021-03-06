//
//  ZMHMenu.h
//  zChatUI
//
//  Created by Huxley Yang on 19/01/2018.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZMHMenuItem.h"

NS_ASSUME_NONNULL_BEGIN

@class ZMHMenu;

@protocol ZMHMenuDelegate <NSObject>

@optional
- (void)menu:(ZMHMenu *)menu clickedItem:(ZMHMenuItem *)item;//!<ZMHMenuItem which has custom view property will not trigger this method
- (void)menuWillShow:(ZMHMenu *)menu;
- (void)menuWillClose:(ZMHMenu *)menu;
- (void)menuDidClosed:(ZMHMenu *)menu;

@end

@interface ZMHMenu : NSObject <ZMObjectDispose> //Tree Menu
{
    id _localMouseDownEventMonitor;
    id _globalMouseDownEventMonitor;
    id _lostFocusObserver;
}

@property (assign, nullable) id <ZMHMenuDelegate> delegate;

@property (copy, nonatomic, nullable) NSArray <ZMHMenuItem *> *items;

- (void)popupAtPosition:(NSPoint)position inView:(nullable NSView *)view anchorCorner:(NSRectCorner)corner;
- (void)close;
@property (readonly) BOOL shown;
- (void)cleanUp;

@property (copy) NSColor *backgroundColor;//default is White
@property (nonatomic) NSEdgeInsets edgePaddings;//Not working

@property (assign) BOOL paddingTopAndBottom;

@property (assign) BOOL autoCloseWhenMouseExist;

@property (assign) BOOL costMouseEventWhenClose;//!< 'event == nil', Default is YES. (Deprecated)

@property (retain) id representedObject;

@property (copy) NSDictionary *shadowParameters;

- (BOOL)isMouseOnMenu;

- (void)showSubMenuWithItem:(ZMHMenuItem *)item;
- (void)menuKeyMayChanged;

- (void)selectPreviousItem:(nullable id)sender;
- (void)selectNextItem:(nullable id)sender;

@end

NS_ASSUME_NONNULL_END
