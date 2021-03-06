// JLog
#ifndef DEBUG
#define DEBUG 0
#endif

#ifndef JLog
#define JLine(firstarg, ...) ([NSString stringWithFormat:@"\t(%08x.%04d)%s %@",self,__LINE__,__FUNCTION__,[NSString stringWithFormat:firstarg, ##__VA_ARGS__ ]])
#define JLineC(firstarg, ...) ([NSString stringWithFormat:@"\t(%08x.%04d) %s %s(): %@",NULL,__LINE__,__FILE__,__FUNCTION__,[NSString stringWithFormat:firstarg , ##__VA_ARGS__ ]])

#define JLog(firstarg, ...) NSLog(@"%@",JLine(firstarg , ##__VA_ARGS__ ))
#define JLogC(firstarg, ...) NSLog(@"%@",JLineC(firstarg , ##__VA_ARGS__ ))

#define DJLog if(DEBUG)JLog
#define DJLogC if(DEBUG)JLogC

#define D2JLog if(DEBUG>1)JLog
#define D2JLogC if(DEBUG>1)JLogC

#define D3JLog if(DEBUG>2)JLog
#define D3JLogC if(DEBUG>2)JLogC

#define DJLOG if(DEBUG)DJLog(@"");
#define D2JLOG if(DEBUG>1)DJLog(@"");
#define D3JLOG if(DEBUG>1)DJLog(@"");
#endif