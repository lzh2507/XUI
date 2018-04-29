//
//  XUICellFactory.h
//  XXTExplorer
//
//  Created by Zheng on 17/07/2017.
//  Copyright © 2017 Zheng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XUIAdapter.h"

@class XUIBaseCell, XUIGroupCell, XUILogger, XUITheme;

@class XUICellFactory;

@protocol XUICellFactoryDelegate <NSObject>

- (void)cellFactory:(nonnull XUICellFactory *)parser didFailWithError:(nonnull NSError *)error;
- (void)cellFactoryDidFinishParsing:(nonnull XUICellFactory *)parser;

@end

@interface XUICellFactory : NSObject

#pragma mark - Adapter Parsing

@property (nonatomic, weak, nullable) id <XUICellFactoryDelegate> delegate;
@property (nonatomic, strong, readonly, nullable) NSDictionary <NSString *, id> *rootEntry;
@property (nonatomic, assign) BOOL parsed;
- (void)parsePath:(nonnull NSString *)path Bundle:(nonnull NSBundle *)bundle;
// this method should run in main thread

#pragma mark - Factory Cells

@property (nonatomic, strong, readonly, nullable) NSArray <XUIGroupCell *> *sectionCells;
@property (nonatomic, strong, readonly, nullable) NSArray <NSArray <XUIBaseCell *> *> *otherCells;
@property (nonatomic, strong, readonly, nullable) NSArray <XUIBaseCell *> *cells; // section cells + other cells
- (void)updateRelatedCellsForCell:(nonnull XUIBaseCell *)inCell;

#pragma mark - Factory Properties

@property (nonatomic, strong, nullable) XUITheme *theme;
@property (nonatomic, strong, nullable) XUILogger *logger;
@property (nonatomic, strong, nullable) id <XUIAdapter> adapter;

- (void)setNeedsReload;

@end
