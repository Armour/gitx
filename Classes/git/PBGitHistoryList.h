//
//  PBGitHistoryList.h
//  GitX
//
//  Created by Nathan Kinsinger on 2/20/10.
//  Copyright 2010 Nathan Kinsinger. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@class PBGitRepository;
@class PBGitRevSpecifier;
@class PBGitRef;
@class PBGitRevList;
@class PBGitHistoryGrapher;
@class PBGitSHA;

@interface PBGitHistoryList : NSObject {
	__weak PBGitRepository *repository;

	PBGitRevList *currentRevList;

	PBGitSHA *lastSHA;
	NSSet *lastRefSHAs;
	NSInteger lastBranchFilter;
	PBGitRef *lastRemoteRef;
	BOOL resetCommits;
	BOOL shouldReloadProjectHistory;

	PBGitHistoryGrapher *grapher;
	NSOperationQueue *graphQueue;
}

- (id) initWithRepository:(PBGitRepository *)repo;
- (void) forceUpdate;
- (void) updateHistory;
- (void)cleanup;

- (void) updateCommitsFromGrapher:(NSDictionary *)commitData;


@property (nonatomic, strong) PBGitRevList *projectRevList;
@property (nonatomic, strong, readonly) NSArray *projectCommits;
@property (nonatomic, assign, readonly) BOOL isUpdating;

@end
