#import "GHOrganization.h"
#import "GHFeed.h"
#import "GHUser.h"
#import "GHUsers.h"
#import "GHRepository.h"
#import "GHRepositories.h"
#import "GravatarLoader.h"
#import "ASIFormDataRequest.h"
#import "CJSONDeserializer.h"
#import "NSString+Extensions.h"
#import "NSURL+Extensions.h"
#import "flownbird.h"


@implementation GHOrganization

@synthesize name;
@synthesize login;
@synthesize email;
@synthesize company;
@synthesize blogURL;
@synthesize location;
@synthesize gravatarHash;
@synthesize gravatar;
@synthesize publicMembers;
@synthesize publicRepositories;
@synthesize recentActivity;
@synthesize followersCount;
@synthesize followingCount;
@synthesize publicGistCount;
@synthesize privateGistCount;
@synthesize publicRepoCount;
@synthesize privateRepoCount;

+ (id)organizationWithLogin:(NSString *)theLogin {
	return [[[[self class] alloc] initWithLogin:theLogin] autorelease];
}

- (id)initWithLogin:(NSString *)theLogin {
	[self init];
	self.login = theLogin;
	self.gravatar = [UIImage imageWithContentsOfFile:[[flownbird sharedInstance] cachedGravatarPathForIdentifier:self.login]];
    gravatarLoader = [[GravatarLoader alloc] initWithTarget:self andHandle:@selector(loadedGravatar:)];
	return self;
}

- (void)dealloc {
	[name release], name = nil;
	[login release], login = nil;
	[email release], email = nil;
	[company release], company = nil;
	[blogURL release], blogURL = nil;
	[location release], location = nil;
    [gravatarLoader release], gravatarLoader = nil;
	[gravatarHash release], gravatarHash = nil;
	[gravatar release], gravatar = nil;
	[publicMembers release], publicMembers = nil;
	[publicRepositories release], publicRepositories = nil;
	[recentActivity release], recentActivity = nil;
    [super dealloc];
}

- (NSUInteger)hash {
	NSString *hashValue = [login lowercaseString];
	return [hashValue hash];
}

- (NSString *)description {
    return [NSString stringWithFormat:@"<GHOrganization login:'%@' status:'%d' name:'%@' email:'%@' company:'%@' location:'%@' blogURL:'%@' publicRepoCount:'%d' privateRepoCount:'%d'>", login, loadingStatus, name, email, company, location, blogURL, publicRepoCount, privateRepoCount];
}

- (int)compareByName:(GHOrganization *)theOtherOrg {
    return [login localizedCaseInsensitiveCompare:[theOtherOrg login]];
}

- (void)setLogin:(NSString *)theLogin {
	[theLogin retain];
	[login release];
	login = theLogin;
    
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
	NSString *username = [defaults stringForKey:kLoginDefaultsKey];
	NSString *token = [defaults stringForKey:kTokenDefaultsKey];
    NSURL *activityFeedURL = [NSURL URLWithFormat:kOrganizationFeedFormat, login, username, token];
	NSURL *repositoriesURL = [NSURL URLWithFormat:kOrganizationPublicRepositoriesFormat, login];
	NSURL *membersURL = [NSURL URLWithFormat:kOrganizationPublicMembersFormat, login];
    
    self.resourceURL = [NSURL URLWithFormat:kOrganizationFormat, login];
	self.publicRepositories = [GHRepositories repositoriesWithURL:repositoriesURL];
	self.publicMembers = [GHUsers usersWithURL:membersURL];
    self.recentActivity = [GHFeed resourceWithURL:activityFeedURL];
}

- (void)setGravatarHash:(NSString *)theHash {
	[theHash retain];
	[gravatarHash release];
	gravatarHash = theHash;
    
	if (gravatarHash) {
        [gravatarLoader loadHash:gravatarHash withSize:[[flownbird sharedInstance] gravatarSize]]; 
    }
}

- (void)setValuesFromDict:(NSDictionary *)theDict {
    NSDictionary *resource = [theDict objectForKey:@"organization"] ? [theDict objectForKey:@"organization"] : theDict;
    
    if (![login isEqualToString:[resource objectForKey:@"login"]]) self.login = [resource objectForKey:@"login"];
    self.email = [[resource objectForKey:@"email"] isKindOfClass:[NSNull class]] ? nil : [resource objectForKey:@"email"];
    self.name = [[resource objectForKey:@"name"] isKindOfClass:[NSNull class]] ? nil : [resource objectForKey:@"name"];
    self.company = [[resource objectForKey:@"company"] isKindOfClass:[NSNull class]] ? nil : [resource objectForKey:@"company"];
    self.gravatarHash = [[resource objectForKey:@"gravatar_id"] isKindOfClass:[NSNull class]] ? nil : [resource objectForKey:@"gravatar_id"];
    self.location = [[resource objectForKey:@"location"] isKindOfClass:[NSNull class]] ? nil : [resource objectForKey:@"location"];
    self.blogURL = [[resource objectForKey:@"blog"] isKindOfClass:[NSNull class]] ? nil : [NSURL URLWithString:[resource objectForKey:@"blog"]];
    self.followersCount = [[resource objectForKey:@"followers_count"] integerValue];
    self.followingCount = [[resource objectForKey:@"following_count"] integerValue];
    self.publicGistCount = [[resource objectForKey:@"public_gist_count"] integerValue];
    self.privateGistCount = [[resource objectForKey:@"private_gist_count"] integerValue];
    self.publicRepoCount = [[resource objectForKey:@"public_repo_count"] integerValue];
    self.privateRepoCount = [[resource objectForKey:@"private_repo_count"] integerValue];
}

#pragma mark Gravatar

- (void)loadedGravatar:(UIImage *)theImage {
	self.gravatar = theImage;
	[UIImagePNGRepresentation(theImage) writeToFile:[[flownbird sharedInstance] cachedGravatarPathForIdentifier:self.login] atomically:YES];
}

@end
