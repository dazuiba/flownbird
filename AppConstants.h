// Settings
#define kClearAvatarCacheDefaultsKey @"clearAvatarCache"
#define kLastReadingDateURLDefaultsKeyPrefix @"lastReadingDate:"
#define kLoginDefaultsKey @"username"
#define kTokenDefaultsKey @"token"

// API
#define kLoginParamName @"login"
#define kTokenParamName @"token"
#define kISO8601TimeFormat @"yyyy-MM-dd'T'HH:mm:ssz"
#define kIssueTimeFormat @"yyyy/MM/dd HH:mm:ss z"

// tables
#define kRepositoryCellIdentifier @"RepositoryCell"
#define kFeedEntryCellIdentifier @"FeedEntryCell"
#define kIssueCellIdentifier @"IssueCell"
#define kUserCellIdentifier @"UserCell"
#define kNetworkCellIdentifier @"NetworkCell"
#define kBranchCellIdentifier @"BranchCell"
#define kCommentCellIdentifier @"CommentCell"
#define kOrganizationCellIdentifier @"OrganizationCell"

// API URLs
#define kAPIBaseFormat @"http://www.1q84.local/api/v1/"

// User
#define kUserFeedFormat @"http://github.com/%@.atom"
#define kUserNewsFeedFormat @"http://github.com/%@.private.atom?token=%@"

#define kUserActivityFeedFormat @"http://beta.1q84.local/api/v1?method=activity.private"
#define kUserGithubFormat @"http://github.com/%@"
#define kUserFormat @"http://beta.1q84.local/api/v1?method=user.show&login=%@"
#define kUserReposFormat @"http://github.com/api/v2/json/repos/show/%@"
#define kUserWatchedReposFormat @"http://github.com/api/v2/json/repos/watched/%@"
#define kUserSearchFormat @"http://github.com/api/v2/json/user/search/%@"
#define kUserFollowingFormat @"http://github.com/api/v2/json/user/show/%@/following"
#define kUserFollowersFormat @"http://github.com/api/v2/json/user/show/%@/followers"
#define kUserFollowFormat @"http://github.com/api/v2/json/user/%@/%@"

// Repos
#define kRepoGithubFormat @"http://github.com/%@/%@/tree/master"
#define kRepoFeedFormat @"http://github.com/feeds/%@/commits/%@/%@"
#define kRepoPrivateFeedFormat @"http://github.com/feeds/%@/commits/%@/%@"
#define kRepoFormat @"http://github.com/api/v2/json/repos/show/%@/%@"
#define kRepoSearchFormat @"http://github.com/api/v2/json/repos/search/%@"
#define kRepoWatchFormat @"http://github.com/api/v2/json/repos/%@/%@/%@"
#define kRepoBranchesFormat @"http://github.com/api/v2/json/repos/show/%@/%@/branches"
#define kRepoNetworkFormat @"http://github.com/api/v2/json/repos/show/%@/%@/network"
#define kRepoPublicCommitsFormat @"http://github.com/api/v2/json/commits/list/%@/%@/%@"
#define kRepoPublicCommitFormat @"http://github.com/api/v2/json/commits/show/%@/%@/%@"
#define kRepoPrivateCommitsFormat @"http://github.com/api/v2/json/commits/list/%@/%@/%@"
#define kRepoPrivateCommitFormat @"http://github.com/api/v2/json/commits/show/%@/%@/%@"

// Issues
#define kIssueGithubFormat @"http://github.com/%@/%@/issues#issue/%d"
#define kIssueFormat @"http://github.com/api/v2/json/issues/show/%@/%@/%d"
#define kIssueOpenFormat @"http://github.com/api/v2/json/issues/open/%@/%@"
#define kIssueEditFormat @"http://github.com/api/v2/json/issues/edit/%@/%@/%d"
#define kIssueCommentsFormat @"http://github.com/api/v2/json/issues/comments/%@/%@/%d"
#define kIssueCommentFormat @"http://github.com/api/v2/json/issues/comment/%@/%@/%d"
#define kIssueToggleFormat @"http://github.com/api/v2/json/issues/%@/%@/%@/%d"
#define kIssuesFormat @"http://github.com/api/v2/json/issues/list/%@/%@/%@"

// Organizations
#define kOrganizationGithubFormat @"http://github.com/%@"
#define kOrganizationFormat @"http://github.com/api/v2/json/organizations/%@"
#define kOrganizationsFormat @"http://github.com/api/v2/json/user/show/%@/organizations"
#define kOrganizationsRepositoriesFormat @"http://github.com/api/v2/json/organizations/repositories"
#define kOrganizationFeedFormat @"http://github.com/organizations/%@/%@.private.atom?token=%@"
#define kOrganizationPublicRepositoriesFormat @"http://github.com/api/v2/json/organizations/%@/public_repositories"
#define kOrganizationPublicMembersFormat @"http://github.com/api/v2/json/organizations/%@/public_members"

// Issues
#define kIssueStateOpen @"open"
#define kIssueStateClosed @"closed"
#define kIssueToggleClose @"close"
#define kIssueToggleReopen @"reopen"
#define kIssueTitleParamName @"title"
#define kIssueBodyParamName @"body"
#define kIssueCommentCommentParamName @"comment"

// Images
#define kImageGravatarMaxLogicalSize 44

// Following/Watching
#define kFollow @"follow"
#define kUnFollow @"unfollow"
#define kWatch @"watch"
#define kUnWatch @"unwatch"

// KVO
#define kResourceLoadingStatusKeyPath @"loadingStatus"
#define kResourceSavingStatusKeyPath @"savingStatus"
#define kUserLoginKeyPath @"login"
#define kUserGravatarKeyPath @"gravatar"
#define kOrganizationLoginKeyPath @"login"
#define kOrganizationGravatarKeyPath @"gravatar"
