#import <Cocoa/Cocoa.h>
#import <AVKit/AVKit.h>
#import <AVFoundation/AVFoundation.h>

const NSString *correctPassword = @"Tobiwan Kenobi";
const NSString *videoPath = @"video.mp4" // Change to your video path

NSString* promptForPassword() {
    NSAlert *alert = [[NSAlert alloc] init];
    [alert setMessageText:@"Enter Password"];
    [alert setInformativeText:@"This content is protected."];
    NSSecureTextField *input = [[NSSecureTextField alloc] initWithFrame:NSMakeRect(0, 0, 200, 24)];
    [alert setAccessoryView:input];
    [alert addButtonWithTitle:@"OK"];
    [alert addButtonWithTitle:@"Cancel"];

    NSModalResponse response = [alert runModal];
    if (response == NSAlertFirstButtonReturn) {
        return [input stringValue];
    }
    return nil;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSString *enteredPassword = promptForPassword();
        if (![enteredPassword isEqualToString:(NSString *)correctPassword]) {
            NSLog(@"Access denied.");
            return 0;
        }

        // Setup the app
        NSApplication *app = [NSApplication sharedApplication];
        [app setActivationPolicy:NSApplicationActivationPolicyRegular];

        NSWindow *window = [[NSWindow alloc] initWithContentRect:NSMakeRect(100, 100, 800, 600)
                                                       styleMask:(NSWindowStyleMaskTitled |
                                                                  NSWindowStyleMaskClosable |
                                                                  NSWindowStyleMaskResizable)
                                                         backing:NSBackingStoreBuffered
                                                           defer:NO];
        [window setTitle:@"Secret Video"];
        [window makeKeyAndOrderFront:nil];

        NSURL *videoURL = [NSURL fileURLWithPath:(NSString *)videoPath];
        AVPlayer *player = [AVPlayer playerWithURL:videoURL];
        AVPlayerView *playerView = [[AVPlayerView alloc] initWithFrame:window.contentView.bounds];
        [playerView setAutoresizingMask:(NSViewWidthSizable | NSViewHeightSizable)];
        [playerView setPlayer:player];
        [window.contentView addSubview:playerView];

        [app activateIgnoringOtherApps:YES];
        [player play];
        [app run];
    }
    return 0;
}