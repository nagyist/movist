//
//  Movist
//
//  Copyright 2006 ~ 2008 Yong-Hoe Kim. All rights reserved.
//      Yong-Hoe Kim  <cocoable@gmail.com>
//
//  This file is part of Movist.
//
//  Movist is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  Movist is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import "Movist.h"
#import "CustomControls.h"
#import "SeekSlider.h"

#import "AppleRemote/RemoteControl.h"

@class MTrack;
@class MMovie;
@class MSubtitle;
@class Playlist;
@class PlaylistItem;
@class PlaylistController;
@class PreferenceController;

@class MultiClickRemoteBehavior;
@class RemoteControlContainer;

@class MMovieView;
@class MainWindow;
@class HoverButton;
@class ControlPanel;
@class FullScreener;
@class PlayPanel;

@interface AppController : NSObject
{
    MultiClickRemoteBehavior* _remoteControlBehavior;
    RemoteControlContainer* _remoteControlContainer;
    RemoteControlEventIdentifier _remoteControlRepeatButtonID;
    NSTimer* _remoteControlRepeatTimer;
    NSLock* _remoteControlRepeatTimerLock;

    PreferenceController* _preferenceController;
    PlaylistController* _playlistController;
    NSUserDefaults* _defaults;
    NSTimer* _updateSystemActivityTimer;
    BOOL _audioDeviceSupportsDigital;
    float _systemVolume;
    BOOL _checkForAltVolumeChange;

    // movie & subtitle
    IBOutlet NSMenu* _movieMenu;
    IBOutlet NSMenu* _aspectRatioMenu;
    IBOutlet NSMenu* _fullScreenFillMenu;
    IBOutlet NSTableView* _propertiesView;
    MMovie* _movie;
    Playlist* _playlist;
    NSArray* _subtitles;
    NSMutableIndexSet* _audioTrackIndexSet;
    NSMutableSet* _subtitleNameSet;
    float _playRate;
    float _seekInterval[3];

    // last-played-movie
    NSURL* _lastPlayedMovieURL;
    float _lastPlayedMovieTime;
    NSRange _lastPlayedMovieRepeatRange;

    // main-menu
    IBOutlet NSMenuItem* _reopenWithMenuItem;
    IBOutlet NSMenuItem* _altCopyImageMenuItem;
    IBOutlet NSMenuItem* _altSaveImageMenuItem;
    IBOutlet NSMenuItem* _playMenuItem;
    IBOutlet NSMenuItem* _seekBackward1MenuItem;
    IBOutlet NSMenuItem* _seekBackward2MenuItem;
    IBOutlet NSMenuItem* _seekBackward3MenuItem;
    IBOutlet NSMenuItem* _seekPrevSubtitleMenuItem;
    IBOutlet NSMenuItem* _seekForward1MenuItem;
    IBOutlet NSMenuItem* _seekForward2MenuItem;
    IBOutlet NSMenuItem* _seekForward3MenuItem;
    IBOutlet NSMenuItem* _seekNextSubtitleMenuItem;
    IBOutlet NSMenuItem* _repeatAllMenuItem;
    IBOutlet NSMenuItem* _repeatOneMenuItem;
    IBOutlet NSMenuItem* _repeatOffMenuItem;
    IBOutlet NSMenuItem* _rateSlowerMenuItem;
    IBOutlet NSMenuItem* _rateFasterMenuItem;
    IBOutlet NSMenuItem* _rateDefaultMenuItem;
    IBOutlet NSMenuItem* _volumeUpMenuItem;
    IBOutlet NSMenuItem* _altVolumeUpMenuItem;
    IBOutlet NSMenuItem* _volumeDownMenuItem;
    IBOutlet NSMenuItem* _altVolumeDownMenuItem;
    IBOutlet NSMenuItem* _muteMenuItem;
    IBOutlet NSMenu* _subtitleMenu;
    IBOutlet NSMenu* _subtitleEncodingMenu;
    IBOutlet NSMenuItem* _subtitleVisibleMenuItem;
    IBOutlet NSMenuItem* _subtitleControlMenuItem;
    IBOutlet NSMenuItem* _subtitlePositionUBoxMenuItem;
    IBOutlet NSMenuItem* _subtitlePositionTopMenuItem;
    IBOutlet NSMenuItem* _subtitlePositionCenterMenuItem;
    IBOutlet NSMenuItem* _subtitlePositionBottomMenuItem;
    IBOutlet NSMenuItem* _subtitlePositionLBoxMenuItem;
    IBOutlet NSMenuItem* _letterBoxHeightSameMenuItem;
    IBOutlet NSMenuItem* _letterBoxHeight1LineMenuItem;
    IBOutlet NSMenuItem* _letterBoxHeight2LinesMenuItem;
    IBOutlet NSMenuItem* _letterBoxHeight3LinesMenuItem;
    IBOutlet NSMenuItem* _syncLaterMenuItem;
    IBOutlet NSMenuItem* _syncEarlierMenuItem;
    IBOutlet NSMenuItem* _syncDefaultMenuItem;

    // main window
    IBOutlet MainWindow* _mainWindow;
    IBOutlet MMovieView* _movieView;
    IBOutlet NSButton* _muteButton;
    IBOutlet NSSlider* _volumeSlider;
    IBOutlet MainSeekSlider* _seekSlider;
    IBOutlet NSButton* _playButton;
    IBOutlet TimeTextField* _lTimeTextField;
    IBOutlet TimeTextField* _rTimeTextField;
    IBOutlet HoverButton* _prevSeekButton;
    IBOutlet HoverButton* _nextSeekButton;
    IBOutlet HoverButton* _controlPanelButton;
    IBOutlet HoverButton* _prevMovieButton;
    IBOutlet HoverButton* _nextMovieButton;
    IBOutlet HoverButton* _playlistButton;
    NSButton* _decoderButton;
    float _prevMovieTime;
    BOOL _viewDuration;

    // control panel
    IBOutlet ControlPanel* _controlPanel;
    IBOutlet NSTextField* _audioDeviceTextField;
    IBOutlet NSTextField* _audioOutTextField;
    IBOutlet NSSegmentedControl* _subtitleLanguageSegmentedControl;
    IBOutlet NSTextField* _subtitleNameTextField;
    IBOutlet NSPopUpButton* _subtitlePositionPopUpButton;
    IBOutlet NSButton* _subtitlePositionDefaultButton;
    IBOutlet NSPopUpButton* _letterBoxHeightPopUpButton;
    IBOutlet NSButton* _letterBoxHeightDefaultButton;
    IBOutlet NSTextField* _repeatBeginningTextField;
    IBOutlet NSTextField* _repeatEndTextField;
    IBOutlet NSButton* _cpDecoderButton;
    IBOutlet NSTextField* _dataSizeBpsTextField;
    IBOutlet NSTextField* _fpsTextField;

    // full-screen & navigation
    NSLock* _fullScreenLock;
    FullScreener* _fullScreener;

    // play panel
    IBOutlet PlayPanel* _playPanel;
    IBOutlet NSButton* _fsMuteButton;
    IBOutlet NSSlider* _fsVolumeSlider;
    IBOutlet FSSeekSlider* _fsSeekSlider;
    IBOutlet NSButton* _fsPlayButton;
    IBOutlet NSButton* _fsPrevSeekButton;
    IBOutlet NSButton* _fsNextSeekButton;
    IBOutlet TimeTextField* _fsLTimeTextField;
    IBOutlet TimeTextField* _fsRTimeTextField;
    IBOutlet NSButton* _fsPlaylistButton;
    IBOutlet NSButton* _fsDecoderButton;
}

- (MMovie*)movie;
- (NSURL*)movieURL;

- (void)updateUI;
- (void)setIncludeLetterBoxOnCapture:(BOOL)includeLetterBox;
- (void)checkForUpdatesOnStartup;
- (void)checkForUpdates:(BOOL)manual;

- (IBAction)viewDurationAction:(id)sender;
- (IBAction)controlPanelAction:(id)sender;
- (IBAction)preferencePanelAction:(id)sender;

@end

////////////////////////////////////////////////////////////////////////////////

@interface AppController (Open)

- (BOOL)openFile:(NSString*)filename;
- (BOOL)openFiles:(NSArray*)filenames;
- (BOOL)openURL:(NSURL*)url;
- (BOOL)openFile:(NSString*)filename option:(int)option;
- (BOOL)openFiles:(NSArray*)filenames option:(int)option;
- (BOOL)openMovie:(NSURL*)movieURL movieClass:(Class)movieClass
         subtitle:(NSURL*)subtitleURL subtitleEncoding:(CFStringEncoding)subtitleEncoding;
- (BOOL)openSubtitle:(NSURL*)subtitleURL encoding:(CFStringEncoding)encoding;
- (BOOL)reopenMovieWithMovieClass:(Class)movieClass;
- (void)reopenSubtitle;
- (void)closeMovie;

- (void)updateDecoderUI;
- (void)updateDataSizeBpsUI;

- (IBAction)openFileAction:(id)sender;
- (IBAction)openURLAction:(id)sender;
- (IBAction)openSubtitleFileAction:(id)sender;
- (IBAction)reopenMovieAction:(id)sender;
- (IBAction)reopenSubtitleAction:(id)sender;

- (IBAction)moviePropertyAction:(id)sender;

@end

////////////////////////////////////////////////////////////////////////////////

@interface AppController (Playlist)

- (Playlist*)playlist;
- (void)addFiles:(NSArray*)filenames;
- (void)addURL:(NSURL*)url;
- (void)updatePrevNextMovieButtons;
- (BOOL)openCurrentPlaylistItem;
- (void)openPrevPlaylistItem;
- (void)openNextPlaylistItem;
- (void)playlistEnded;

- (BOOL)playlistWindowVisible;
- (void)showPlaylistWindow;
- (void)hidePlaylistWindow;

- (void)setRepeatMode:(unsigned int)mode;
- (void)updateRepeatUI;

- (void)loadLastPlayedMovieInfo;
- (void)saveLastPlayedMovieInfo;

- (IBAction)playlistAction:(id)sender;
- (IBAction)prevNextMovieAction:(id)sender;
- (IBAction)repeatAction:(id)sender;

@end

////////////////////////////////////////////////////////////////////////////////

@interface AppController (Playback)

- (void)play;
- (void)pause;
- (void)gotoBeginning;
- (void)gotoEnd;
- (void)gotoTime:(float)time;
- (void)seekPrevSubtitle;
- (void)seekNextSubtitle;
- (void)seekBackward:(unsigned int)indexOfValue;
- (void)seekForward:(unsigned int)indexOfValue;
- (void)stepBackward;
- (void)stepForward;
- (void)setSeekInterval:(float)interval atIndex:(unsigned int)index;
- (void)setPlayRate:(float)rate;
- (void)changePlayRate:(int)tag;
- (void)setRangeRepeatRange:(NSRange)range;
- (void)setRangeRepeatBeginning:(float)beginning;
- (void)setRangeRepeatEnd:(float)end;
- (void)clearRangeRepeat;

- (void)updateTimeUI;
- (void)updatePlayUI;

- (IBAction)playAction:(id)sender;
- (IBAction)seekAction:(id)sender;
- (IBAction)rangeRepeatAction:(id)sender;
- (IBAction)rateAction:(id)sender;

@end

////////////////////////////////////////////////////////////////////////////////

@interface AppController (Video)

- (void)setVideoTrackAtIndex:(unsigned int)index enabled:(BOOL)enabled;
- (void)resizeWithMagnification:(float)magnification;
- (void)resizeToScreen;

- (int)aspectRatio;
- (void)setAspectRatio:(int)aspectRatio;
- (void)updateAspectRatioMenu;

- (BOOL)isFullScreen;
- (void)beginFullScreen;
- (void)endFullScreen;

- (BOOL)isDesktopBackground;
- (void)beginDesktopBackground;
- (void)endDesktopBackground;

- (BOOL)isFullNavigation;
- (void)beginFullNavigation;
- (void)endFullNavigation;

- (void)setFullScreenFill:(int)fill forWideMovie:(BOOL)forWideMovie;
- (void)setFullScreenFill:(int)fill;
- (void)setFullScreenUnderScan:(float)underScan;
- (void)updateFullScreenFillMenu;

- (IBAction)movieSizeAction:(id)sender;
- (IBAction)fullScreenAction:(id)sender;
- (IBAction)desktopBackgroundAction:(id)sender;
- (IBAction)fullScreenFillAction:(id)sender;
- (IBAction)fullScreenUnderScanAction:(id)sender;
- (IBAction)aspectRatioAction:(id)sender;
- (IBAction)fullNavigationAction:(id)sender;
- (IBAction)saveCurrentImage:(id)sender;

@end

////////////////////////////////////////////////////////////////////////////////

@interface AppController (Audio)

- (void)volumeUp;
- (void)volumeDown;
- (void)setVolume:(float)volume;
- (void)setMuted:(BOOL)muted;
- (void)updateVolumeUI;

- (void)setAudioTrackAtIndex:(unsigned int)index enabled:(BOOL)enabled;
- (void)enableAudioTracksInIndexSet:(NSIndexSet*)set;
- (void)autoenableAudioTracks;
- (void)changeAudioTrack:(int)tag;
- (void)updateAudioTrackMenuItems;
- (void)updateVolumeMenuItems;

- (void)scrollWheelAction:(NSEvent*)event;
- (IBAction)volumeAction:(id)sender;
- (IBAction)muteAction:(id)sender;
- (IBAction)audioTrackAction:(id)sender;

@end

@interface AppController (AudioDigital)

- (void)initDigitalAudioOut;
- (BOOL)updateDigitalAudioOut:(id)sender;
- (BOOL)isCurrentlyDigitalAudioOut;

@end

////////////////////////////////////////////////////////////////////////////////

@interface AppController (Subtitle)

- (void)setSubtitleEnable:(BOOL)enable;
- (void)changeSubtitleVisible;

- (void)setSubtitleFontSize:(float)size atIndex:(int)index;
- (void)changeSubtitleFontSize:(int)tag atIndex:(int)index;
- (void)setSubtitlePosition:(int)position atIndex:(int)index;
- (void)changeSubtitlePositionAtIndex:(int)index;
- (void)setSubtitleHMargin:(float)hMargin atIndex:(int)index;
- (void)setSubtitleVMargin:(float)vMargin atIndex:(int)index;
- (void)changeSubtitleVMargin:(int)tag atIndex:(int)index;
- (void)setSubtitleLineSpacing:(float)spacing atIndex:(int)index;
- (void)setSubtitleSync:(float)sync atIndex:(int)index;
- (void)changeSubtitleSync:(int)tag atIndex:(int)index;

- (void)setLetterBoxHeight:(int)height;
- (void)changeLetterBoxHeight;
- (void)setSubtitleScreenMargin:(float)screenMargin;

- (void)setSubtitle:(MSubtitle*)subtitle enabled:(BOOL)enabled;
- (void)autoenableSubtitles;
- (void)changeSubtitleLanguage:(int)tag;
- (void)updateMovieViewSubtitles;
- (void)updateSubtitleLanguageMenuItems;
- (void)updateSubtitlePositionMenuItems;
- (void)updateLetterBoxHeightMenuItems;

- (IBAction)subtitleVisibleAction:(id)sender;
- (IBAction)subtitleLanguageAction:(id)sender;
- (IBAction)subtitleFontSizeAction:(id)sender;
- (IBAction)subtitleVMarginAction:(id)sender;
- (IBAction)subtitlePositionAction:(id)sender;
- (IBAction)subtitleSyncAction:(id)sender;
- (IBAction)letterBoxHeightAction:(id)sender;

@end

////////////////////////////////////////////////////////////////////////////////

@interface AppController (Remote)

- (void)initRemoteControl;
- (void)cleanupRemoteControl;

- (void)startRemoteControl;
- (void)stopRemoteControl;

- (IBAction)remoteControlPlusAction:(id)sender;
- (IBAction)remoteControlPlusHoldAction:(id)sender;
- (IBAction)remoteControlMinusAction:(id)sender;
- (IBAction)remoteControlMinusHoldAction:(id)sender;
- (IBAction)remoteControlLeftAction:(id)sender;
- (IBAction)remoteControlLeftHoldAction:(id)sender;
- (IBAction)remoteControlRightAction:(id)sender;
- (IBAction)remoteControlRightHoldAction:(id)sender;
- (IBAction)remoteControlPlayAction:(id)sender;
- (IBAction)remoteControlPlayHoldAction:(id)sender;
- (IBAction)remoteControlMenuAction:(id)sender;
- (IBAction)remoteControlMenuHoldAction:(id)sender;

@end
